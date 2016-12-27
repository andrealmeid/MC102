/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 14b - PaMonHa */

#include <stdio.h>
#include <stdlib.h>

/* essa funcao percorre as linhas dos parlamentares selecionados da matriz 
 * influencia retirando influencias repetidas para se obter o numero real de 
 * parlamentares */
int retiraRepetidos(int n, int nParls, int *combs, int **infl){
    /* r = repetidos, aux = matriz auxiliar que recebe infl */
    int i, j, k, r=0, **aux;
    
    /* alocacao da matriz aux e clonagem da matriz infl */
    aux = malloc(n * sizeof(int *));
    for(i=0;i<n;i++)
        aux[i] = malloc(n * sizeof(int));
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            aux[i][j]=infl[i][j];
    
    /* se duas linhas influenciam a mesma coluna, r eh incrementado e a
     * posicao zerada */
    for(i=0;i<nParls-1;i++)
        for(j=i+1;j<nParls;j++)
            for(k=0;k<n;k++)
                if(aux[combs[i]][k]==1 && aux[combs[j]][k]==1){
                    aux[combs[i]][k]=0;
                    r++;
                }                        
        
    for(i=0;i<n;i++)
        free(aux[i]);
    free(aux);
    
    return r; 
}

/* esse metodo faz a combinacao de nParls elementos dos n parlamentares, 
 * verifica se a combinacao possui o numero minimo de parlamentares e soma os 
 * salarios dos parlamentares contratados */
void combinar(int n, int nParls, int *comb, int prox, int tam, int *somaInlf, 
              int *salario, int k, int **infl, int *menor){    
    /* p = parlamentares da combinacao; s = soma dos salarios; 
     * r = parlamentares repetidos */
    int i, p=0, s=0, r;
    
    if(tam == nParls){       
        
        /* aqui as influencias e os salarios sao somados */
        for(i=0; i<nParls; i++){
            p+=somaInlf[comb[i]];
            s+=salario[comb[i]];
        }
        
        /* se o salario atual for menor do que o menor geral, sao retirados os
         * repetidos para checar se a combinacao possui o minimo de 
         * parlamentares necessarios. uma pre-selecao eh realizada com p>=k
         * para se evitar a utilizacao do metodo retiraRepetidos, que demanda
         * muito processamento */
        if(s<*menor && p>=k){                      
            r = retiraRepetidos(n, nParls, comb, infl);
            if(p-r>=k)
                *menor=s;
        }
    }
    
    else
        for(i=prox;i<n;i++){
            comb[tam] = i;
            combinar(n, nParls, comb, i + 1, tam + 1, somaInlf, salario, k, 
                     infl, menor);
        }
}

int main(){
    /* n = numero de parlamentares; k = tamanho minimo do partido */;
    int n, k, i, j;
    /* salario = vetor dos salarios; infl = matriz influencia */
    int *salario, **infl;
    /* somaInlf = soma das influencias de cada candidato; comb = combinacao 
     atual; nParls = numero de parlamentares da combinacao atual;
     menor = menor combinacao de salarios */
    int *somaInlf, *comb, nParls=1, menor=0;
    
    /* entrada da primeira linha */
    scanf("%d %d", &n, &k);
    
    /* alocacoes dinamicas */
    salario = malloc(n * sizeof(int));
    
    infl = malloc(n * sizeof(int *));
    for(i=0;i<n;i++)
        infl[i] = malloc(n * sizeof(int));
    
    somaInlf = malloc(n * sizeof(int));
    for(i=0;i<n;i++)
        somaInlf[i]=0;
    
    comb = malloc(n * sizeof(int));

    /* entrada dos salarios e das influencias; o primero valor de menor sera
     a soma de todos os salarios */
    for(i=0;i<n;i++){
        scanf("%d", &salario[i]);
        menor+= salario[i];
    }
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &infl[i][j]);

    /* contabilizacao da soma das influencias */
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            somaInlf[i] +=  infl[i][j];
        }
    }            
    
    /* o metodo sera executado fazendo combinacoes de 1 ate n elementos */
    while(nParls<=n){
        combinar(n, nParls, comb, 0, 0, somaInlf, salario, k, infl, &menor);
        nParls++;
    }
    
    /* impressao do menor valor encontrado */
    printf("%d\n", menor);
        
    /* desalocacao */
    for(i=0;i<n;i++)
        free(infl[i]);
    free(infl);
    free(salario);
    free(somaInlf);
    free(comb);
    
    return 0;
}
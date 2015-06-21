/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 14b - PaMonHa */

#include <stdio.h>
#include <stdlib.h>

int menor=100000000;

int real(int n, int nC, int combs[], int **infl){
    int i, j, k, r=0, **aux;
    
    aux = malloc(n * sizeof(int *));
    for(i=0;i<n;i++)
        aux[i] = malloc(n * sizeof(int));
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            aux[i][j]=infl[i][j];    
    
    for(i=0;i<nC-1;i++){
        for(j=i+1;j<nC;j++){
            for(k=0;k<n;k++){
                if(aux[combs[i]][k]==1 && aux[combs[j]][k]==1){
                    aux[combs[i]][k]=0;
                    r++;
                }
            }
        }
    }
        
    return r; 
}

void imprime_vetor(int vetor[], int n, int cont) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("cont = %d\n", cont);
}

void combinar(int n, int nC, int combs[], int prox, int tam, int parl[], 
              int salario[], int *cont, int k, int **infl){
    int i, c=0, s=0, r, j;
    
    if(tam == nC){       
        
        for(i=0; i<nC; i++){
            c+=parl[combs[i]];
            s+=salario[combs[i]];
        }
        r = real(n, nC, combs, infl);
        if(c-r>=k){                      
            if(s<menor)
                menor=s;
        }
    }
    else
        for(i=prox; i<n; i++){
            combs[tam] = i;
            combinar(n, nC, combs, i + 1, tam + 1, parl, salario, cont, k, 
                     infl);
        }
}

int main(){
    /* n = numero de parlamentares; k = tamanho minimo do partido */
    int n, k, i, j, l;
    /* salario = vetor dos salarios; infl = matriz influencia */
    int *salario, **infl;
    
    int parl[100], combs[100], cont = 0, nC=1;
    
    /* entrada da primeira linha */
    scanf("%d %d", &n, &k);
    
    /* alocacoes dinamicas */
    salario = malloc(n * sizeof(int));
    
    infl = malloc(n * sizeof(int *));
    for(i=0;i<n;i++)
        infl[i] = malloc(n * sizeof(int));
    
    for(i=0;i<n;i++)
        parl[i]=0;

    /* entrada dos salarios e das influencias */
    for(i=0;i<n;i++)
        scanf("%d", &salario[i]);
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &infl[i][j]);
                
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            parl[i] +=  infl[i][j];
        }
    }
        
    

    
    while(nC<=n){
        combinar(n, nC, combs, 0, 0, parl, salario, &cont, k, infl);
        nC++;
    }
        
        printf("%d\n", menor);
        
    /* desalocacao */
    free(salario);
    
    for(i=0;i<n;i++)
        free(infl[i]);
    free(infl);
    
    return 0;
}
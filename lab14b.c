/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 14b - PaMonHa */

#include <stdio.h>
#include <stdlib.h>

int real(int n, int nC, int combs[], int **infl){
    int i, j, k, r=0;
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ", infl[i][j]);
        printf("\n");
    }
    
    for(i=0;i<nC-1;i++){
        for(j=i+1;j<nC;j++){
            for(k=0;k<n;k++){
                if(infl[combs[i]][k]==1 && infl[combs[j]][k]==1){
                    infl[combs[i]][k]=0;
                    printf("[%d][%d] e [%d][%d]\n", 
                           combs[i], k, combs[j], k);
                    r++;
                }
            }
        }
    }
    printf("r=%d\n", r);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ", infl[i][j]);
        printf("\n");
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
        if(c==7)
            r = real(n, nC, combs, infl);
        if(c>=k){            
//             for (i = 0; i < nC; i++)
//                 printf("%d ", combs[i]);
//             printf("cont = %d sala = %d\n", c, s);  
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
        
    
//     printf("Lista de custo/influencias:\n");
//     for(i=0;i<n;i++)
//         printf("parlamentar %d: infl = %d custo = %d c/i = %d\n", 
//                i+1, parl[i], salario[i], salario[i]/parl[i]);         
    
    while(nC<=n){
        combinar(n, nC, combs, 0, 0, parl, salario, &cont, k, infl);
        nC++;
    }
        
//         printf("cont = %d\n", cont);
        
    /* desalocacao */
    free(salario);
    
    for(i=0;i<n;i++)
        free(infl[i]);
    free(infl);
    
    return 0;
}
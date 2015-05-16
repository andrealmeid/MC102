/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 09a - A Batalha de Geonosis */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int m, n, **campo, i, j, k, l, aux, total, maior=0, Xmaior=0, Ymaior=0;
    
    int *linhas, *colunas, dp=0, ds=0;
    
    
    scanf("%d %d", &m, &n);
    
    linhas = malloc(m * sizeof(int));
    colunas = malloc(n * sizeof(int));
    
    for(i=0;i<m;i++)  
        linhas[i]=0;
    
    for(i=0;i<n;i++)  
        colunas[i]=0;
    
    
    campo = malloc(m * sizeof(int));
    for(i=0;i<m;i++)
        campo[i] = malloc(n * sizeof(int));
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &campo[i][j]);
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(campo[i][j]==1)
                    linhas[i]++;
            }
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(campo[j][i]==1)
                    colunas[i]++;
            }
        }
        
        i=0, j=0, k=0, l=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(campo[i][j]!=1){
                printf("ponto[%d][%d]:%d\n", i, j, campo[i][j]);
                k=i, l=j;
                dp=0, ds=0;
                
                while(k<m && l<n){
                    dp+=campo[k][l];
                    printf("campo1[%d][%d]:%d\n", k, l, campo[k][l]);
                    k++;
                    l++;
                }
                
                k=i, l=j;
                
                while(k>0 && l>0){
                    k--;
                    l--;
                    printf("campo2[%d][%d]:%d\n", k, l, campo[k][l]);
                    dp+=campo[k][l];
                }

                 k=i, l=j;
                while(k<m && l>0){
                    ds+=campo[k][l];
                    printf("campo3[%d][%d]:%d\n", k, l, campo[k][l]);
                    k++;
                    l--;
                }
                
                k=i, l=j;
                
                while(k>0 && l<n){
                    k--;
                    l++;
                    printf("campo4[%d][%d]:%d\n", k, l, campo[k][l]);
                    ds+=campo[k][l];
                }
                
                
                
                printf("dp: %d ds: %d\n", dp, ds);
                total = dp + ds + linhas[i] + colunas[j];
                printf("total:%d\n", total);
                if(total>maior){
                    maior=total;
                    Xmaior=i;
                    Ymaior=j;
                }
                }
            }
        }
        
        printf("maior(%d,%d): %d\n", Xmaior, Ymaior, maior);
        
        /*for(i=0;i<m;i++)
         *     printf("linha[%d]=%d\n", i+1, linhas[i]);
         *  printf("\n");
         *  
         *  for(i=0;i<n;i++)
         *     printf("%d ", colunas[i]);
         *  printf("\n");*/
        
        /*for(i=0;i<m;i++){
         *     for(j=0;j<n;j++){
         *        printf("%d ", campo[i][j]);
         }
         printf("\n");
        }*/
        
        return 0;
}
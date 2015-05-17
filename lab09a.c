/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 09a - A Batalha de Geonosis */

#include <stdio.h>
#include <stdlib.h>

int disparos(int a){
    if(a==0)
        return 0;
    else
        return 1;
}

int main(){
    
    int m, n, **campo, i, j, k, l, aux, total, maior=0, xMaior=0, yMaior=0;
    
    int *linhas, *colunas, dp=0, ds=0, dMaior=5, disp=0;
    
    
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
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &campo[i][j]);
        }
    }
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
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(campo[i][j]!=1){
                dp=0, ds=0;
                
                k=i, l=j;
                while(k<m-1 && l<n-1){
                    k++;
                    l++;
                    dp+=campo[k][l];
                }
                
                k=i, l=j;
                while(k>0 && l>0){
                    k--;
                    l--;
                    dp+=campo[k][l];
                }
                
                k=i, l=j;
                while(k<m-1 && l>0){
                    k++;
                    l--;
                    ds+=campo[k][l];             
                }
                
                k=i, l=j;                
                while(k>0 && l<n-1){
                    k--;
                    l++;
                    ds+=campo[k][l];
                }
                
                
                total = dp + ds + linhas[i] + colunas[j];  
                disp = disparos(dp) + disparos(ds) + disparos(linhas[i]) +
                disparos(colunas[j]);
                
                if(total>maior){
                    maior=total;
                    dMaior=disp;
                    xMaior=i;
                    yMaior=j;
                }
                
                if(total==maior && disp<dMaior){
                    dMaior=disp;
                    xMaior=i;
                    yMaior=j;
                }

                if(total==maior && disp==dMaior){
                    if(xMaior+yMaior<i+j)
                        i=i-0;
                }
            }
        }
    }
    
    
    printf("Posicao = (%d,%d)\n", xMaior, yMaior);
    printf("Droids = %d\n", maior);
    printf("Disparos = %d\n", dMaior);
    
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
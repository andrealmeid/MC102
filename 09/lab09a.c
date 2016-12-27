/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 09a - A Batalha de Geonosis */

#include <stdio.h>
#include <stdlib.h>

/* verifica se foi realizado disparo no sentido especificado */
int disparos(int a){
    if(a==0)
        return 0;
    else
        return 1;
}


int main(){
    /* m = linhas; n = colunas; **campo = matriz que representa o campo de
     * batalha; total = total =  total de droids destruidos */
    int m, n, **campo, total, i, j, k, l;
    
    /* maior = melhor posicao conforme os criterios do enunciado; xMaior e
     * yMaior = coordenadas dessa posicao */
    int maior=0, xMaior=0, yMaior=0;
    
    /* dp = diagonal principal; ds = diagonal secundaria */
    int *linhas, *colunas, dp=0, ds=0;
    
    /* dMaior = numero de disparos da melhor posicao; disp = disparos */
    int dMaior=5, disp=0;
    
    scanf("%d %d", &m, &n);
    
    linhas = malloc(m * sizeof(int));
    colunas = malloc(n * sizeof(int));
    
    for(i=0;i<m;i++)  
        linhas[i]=0;
    
    for(i=0;i<n;i++)  
        colunas[i]=0;
    
    campo = malloc(m * sizeof(int*));
    for(i=0;i<m;i++)
        campo[i] = malloc(n * sizeof(int));
    
    /* entrada da matriz */
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &campo[i][j]);
        }
    }
    
    /* o programa guarda o numero de droids que contem em cada linha e 
     * coluna em um banco de dados para uma consulta posterior */
    /* contabilizacao das linhas */
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(campo[i][j]==1)
                linhas[i]++;
        }
    }
    
    /* contabilizacao das colunas */
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(campo[j][i]==1)
                colunas[i]++;
        }
    }
    
    /* o codigo ira percorrer casa posicao da matriz contabilizando quantos
     * droids possuem nas diagonais e nas colunas e linhas */
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(campo[i][j]!=1){
                dp=0, ds=0;
                
                /* contabilizacao da diagonal principal */
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
                
                /* contabilizacao da diagonal secundaria */
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
                
                /* soma dos droids e dos disparos */
                total = dp + ds + linhas[i] + colunas[j];  
                disp = disparos(dp) + disparos(ds) + disparos(linhas[i]) +
                disparos(colunas[j]);
                
                /* verificacao da melhor combinacao */
                if(total>maior){
                    maior=total;
                    dMaior=disp;
                    xMaior=i;
                    yMaior=j;
                } else if(total==maior && disp<dMaior){
                    dMaior=disp;
                    xMaior=i;
                    yMaior=j;
                }
            }
        }
    }
    
    
    printf("Posicao = (%d,%d)\n", xMaior, yMaior);
    printf("Droids = %d\n", maior);
    printf("Disparos = %d\n", dMaior);
    
    free(linhas);
    free(colunas);
    for(i=0;i<m;i++)
        free(campo[i]);
    free(campo);
    
    return 0;
}
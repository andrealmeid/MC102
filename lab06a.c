/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 06a - Raio Sugestor */

#include <stdio.h>
#define TAM 50

int main(){
    
    int cidade[TAM][TAM], m, n, i, j, k, r;
    
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cidade[i][j]=0;
    
    scanf("%d %d %d", &m, &n, &r);
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &cidade[i][j]);
    
    /* transforma o alcance nas dimensoes da matriz 'area afetada' 
     * como a matriz é quadrada, as duas dimensoes tem o mesmo tamanho */
    r = (2 * r) + 1;
    
    for(i=0;i<=m-r;i++)
        for(j=0;j<=n-r;j++)
            
    
        return 0;
}
/* Nome: André Figueiredo de Almeida
* RA: 164047
* Laboratorio 06a - Raio Sugestor */

#include <stdio.h>
#define TAM 50

int main(){
    
    int cidade[TAM][TAM], m, n, i, j, lim_i, lim_j, inicio_i, inicio_j, r, soma, maior;
    
    /* entrada das dimensoes da matriz (m,n) e do alcance do transmissor (r) */
    scanf("%d %d %d", &m, &n, &r);
    
    /* entrada dos valores da matriz */
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &cidade[i][j]);
        
    /* transforma o alcance nas dimensoes da matriz 'area alcancada'; 
     * como a matriz é quadrada, as duas dimensoes tem o mesmo tamanho */
    r = (2 * r) + 1;
    
    lim_i=r;
    lim_j=r;
    inicio_i=0;
    inicio_j=0;
    
    /* esses lacos vao verificar todas as possibilidades de posicionamento
     * do transmissor e a soma da populacao atingida em cada posicao */
    while(lim_i<=m){
        soma=0;
        for(i=inicio_i;i<lim_i;i++){
            for(j=inicio_j;j<lim_j;j++)
                soma+=cidade[i][j];
        }
        
        if(soma>maior)
            maior=soma;
        
        if(lim_j<n){
            inicio_j++;
            lim_j++;
        } else {
            inicio_i++;
            lim_i++;
            inicio_j=0;
            lim_j=r;
        }
        
    }
    
    /* a maior soma sera impressa */
    printf("%d\n", maior);
    
    return 0;
}
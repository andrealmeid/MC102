/* Nome: André Figueiredo de Almeida
* RA: 164047
* Laboratorio 06a - Raio Sugestor */

#include <stdio.h>
#define TAM 50

int main(){
    
    int cidade[TAM][TAM], m, n, r, i, j, fim_i, fim_j, inicio_i, inicio_j, soma,
    maior=0;
    
    /* entrada das dimensoes da matriz (m,n) e do alcance do transmissor (r) */
    scanf("%d %d %d", &m, &n, &r);
    
    /* entrada dos valores da matriz */
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &cidade[i][j]);
        
    /* transforma o alcance nas dimensoes da matriz 'area alcancada'; 
     * como a matriz é quadrada, as duas dimensoes tem o mesmo tamanho */
    r = (2 * r) + 1;
    
    /* essas variaveis determinam o inicio e o fim da area alcancada */
    inicio_i=0;
    inicio_j=0;
    fim_i=r;
    fim_j=r;
    
    /* esses lacos irao verificar todas as possibilidades de posicionamento
     * do transmissor e a soma da populacao atingida em cada posicao; 
     * serao consideradas matrizes temporarias com dimensoes rxr;
     * (fim_i<=m) verifica se a linha em uso nao vai alem da matriz inserida */
    
    while(fim_i<=m){
        soma=0;
        for(i=inicio_i;i<fim_i;i++){
            for(j=inicio_j;j<fim_j;j++)
                soma+=cidade[i][j];
        }
        
        if(soma>maior)
            maior=soma;
        
        /* se a coluna atual nao eh a ultima, o codigo avanca mais uma; se nao
         * o codigo pula para proxima linha e recomeca da primeira coluna */
        if(fim_j<n){
            inicio_j++;
            fim_j++;
        } else {
            inicio_i++;
            fim_i++;
            inicio_j=0;
            fim_j=r;
        }
    }
    
    /* a maior soma sera impressa */
    printf("%d\n", maior);
    
    return 0;
}
/* Nome: André Figueiredo de Almeida
* RA: 164047
* Laboratorio 06a - Raio Sugestor */

#include <stdio.h>
#define TAM 50

int main(){
    
    int cidade[TAM][TAM], m, n, i, j, a, b, c, d, r, soma, maior;
    
    /* entrada das dimensoes da matriz (m,n) e do alcance do transmissor (r) */
    scanf("%d %d %d", &m, &n, &r);
    
    /* entrada dos valores da matriz */
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &cidade[i][j]);
        
    /* transforma o alcance nas dimensoes da matriz 'area alcancada'; 
     * como a matriz é quadrada, as duas dimensoes tem o mesmo tamanho */
    r = (2 * r) + 1;
    
    a=r;
    b=r;
    c=0;
    d=0;
    
    /* esses lacos vao verificar todas as possibilidades de posicionamento
     * do transmissor e a soma da populacao atingida em cada posicao */
    while(a<=m){
        soma=0;
        for(i=c;i<a;i++){
            for(j=d;j<b;j++)
                soma+=cidade[i][j];
        }
        
        if(soma>maior)
            maior=soma;
        
        if(b<n){
            d++;
            b++;
        } else {
            c++;
            a++;
            d=0;
            b=r;
        }
        
    }
    
    /* a maior soma sera impressa */
    printf("%d\n", maior);
    
    return 0;
}
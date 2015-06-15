/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 13b - Quadtree */

#include <stdio.h>
#include <stdlib.h>

/* a funcao percorre a matriz ate verificar que existe uma regiao nao homogenea
 * ou seja, onde as ij posicoes sao diferentes da primeira posicao da regiao 
 * depois, divide a regiao em quatro novas regioes com base na metade da regiao
 * metade da regiao = variavel m */
int quadTree(int a, int b, int n, int **mat){
    int i, j, first=mat[a][b], r1, r2, r3, r4, m = n/2;        
        
    for(i=a;i<n+a;i++){
        for(j=b;j<n+b;j++){                       
            if(mat[i][j]!=first){
                /* conforme sao encontradas sub-regioes, elas sao somadas
                 * recursivamente */
                r1 = quadTree(a, b, m, mat);
                r2 = quadTree(a, m+b, m, mat);
                r3 = quadTree(m+a, b, m, mat);
                r4 = quadTree(m+a, m+b, m, mat);       
                return r1+r2+r3+r4;                
            }                
        }
    }
    
    /* se a regiao nao for dividida, retorna 1 */
    return 1;
}


int main(){
    int i, j, n, regioes, **mat;
    
    /* entrada do numero de linhas e colunas */
    scanf("%d", &n);
    
    /* alocacao dinamica da matriz que recevera a matriz de entrada */
    mat = malloc(n * sizeof(int*));
    for(i=0;i<n;i++)
        mat[i] = malloc(n * sizeof(int));
    
    /* entrada da matriz */
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &mat[i][j]);
    
    /* chamada e impressao da funcao quadTree */
    regioes = quadTree(0, 0, n, mat);    
    printf("Numero de regioes = %d\n", regioes);
    
    /* desalocacao de memoria */
    for(i=0;i<n;i++)
        free(mat[i]);
    free(mat);
    
    return 0;
}
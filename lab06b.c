/* Nome: André Figueiredo de Almeida
* RA: 164047
* Laboratorio 06b - A Ameaça Fantasma */

#include <stdio.h>
#define TAM 100

int main(){
    
    int recinto[100][100];
    
    /* entrada das dimensoes da matriz (m,n) */
    scanf("%d %d %d", &m, &n);
    
    /* entrada dos valores da matriz */
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &recinto[i][j]);
	
    return 0;
    
}
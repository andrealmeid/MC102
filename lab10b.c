/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 10b - O Baile de Inverno */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int m, n, d, i, j, aux;
    
    int *alunos, *alunas, duplas=0;
    
    scanf("%d %d %d", &m, &n, &d);

    alunos = malloc(m * sizeof(int));
    alunas = malloc(n * sizeof(int));
    
    for(i=0;i<m;i++)
        scanf("%d", &alunos[i]);
    
    for(i=0;i<n;i++)
        scanf("%d", &alunas[i]);
    
    for(i=1;i<m;i++){
        j=i;
        while (j>0 && alunos[j-1]<alunos[j]) {
            aux = alunos[j];
            alunos[j] = alunos[j-1];
            alunos[j-1] = aux; 
            j--;
        }
    }
    
    for(i=1;i<n;i++){
        j=i;
        while (j>0 && alunas[j-1]<alunas[j]) {
            aux = alunas[j];
            alunas[j] = alunas[j-1];
            alunas[j-1] = aux; 
            j--;
        }
    }
    
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(alunos[i] - alunas[j] <= d && 
                alunos[i] - alunas[j] >=-d){
                duplas++;
                alunos[i]=-1000;
                alunas[j]=-1000;
                j=n;
            }
        }
    }
    

    
    
    printf("Numero maximo de duplas equilibradas = %d\n", duplas);
    
    return 0;
}
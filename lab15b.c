 /* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 15b - O o CR! */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam, *vetor, i, cont=0;

    scanf("%d", &tam);
    vetor = malloc(tam * sizeof(int));

    for(i=0;i<tam;i++)
        scanf("%d", &vetor[i]);

    /* o promgrama computa quantos numeros estao fora de ordem. dessa maneira,
     * podemos calcular o numero minimo de trocas possiveis para ordenar o 
     * vetor */
    for(i=0;i<tam-1;i++)
        if(vetor[i]>vetor[i+1])
            cont++;

    printf("%d\n", cont);

    free(vetor);
    
    return 0;
}
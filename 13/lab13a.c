/* Nome: Andre Figueiredo de Almeida 
 * RA: 164047 
 * Laboratorio 13a - Hanabi */

#include <stdio.h>

/* funcao recursiva para procurar a arvore mais alta */
void alturaArvore(int *altura, int *maior){
    int i=0, n;
    
    /* se a entrada for 0, ou seja, nao tem filhos, nao entrara no loop e 
     * diminuira a altura em 1 */
    scanf("%d", &n);
    
    /* atualiza a maior altura */
    if (*altura > *maior)
        *maior = *altura;    

    /* sai do loop e diminui a altura, por acabar filhos */
    while(i<n){
        *altura = *altura + 1; 
        alturaArvore(altura, maior);
        i++;
    }
    
    *altura = *altura -  1;    
}

int main() { 
    int altura=1, maior=1;
    
    /* chama a funcao e imprime a maior altura */
    alturaArvore(&altura, &maior);
    printf("%d\n", maior);

    return 0;
}
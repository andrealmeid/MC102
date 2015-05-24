/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 10a - Tag Cloud */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct Palavra{
    char *nome;
    int cont;
    int minimo;
};

typedef struct Palavra Palavra;

int main(){
    /* d = palavras distintas; f = numero minimo de ocorrencias de uma palavra
     * l = tamanho minimo de uma palavra; m = tamanho maxio de uma palavra */
    int  d, f, l, m, i, j;
    
    /* aux guarda provisoriamente a palavra lida */
    char *aux;
    
    /* add= booleano para apontar se palavra ja foi adicionada */
    int add=FALSE;
    Palavra *palavras;
    
    scanf("%d %d %d %d", &d, &f, &l, &m);
    
    aux =  malloc(m * sizeof(char));
    palavras = malloc(d * sizeof(Palavra));
    for(i=0;i<d;i++){
        palavras[i].nome = malloc(m * sizeof(char));
        palavras[i].minimo = FALSE;
    }
    
    i=0;
    
    scanf("%s", aux);
    
    while(strncmp(aux,"*",1)){
        add=FALSE;
        /* verifica se a palavra ja foi armazenada */
        for(j=0;j<i;j++){
            /* caso positivo, ele aumenta o contador e quebra o loop */
            if(strcmp(palavras[j].nome,aux)==0){
                palavras[j].cont++;
                printf("Contagem da palavra '%s' = %d\n", 
                       palavras[j].nome, palavras[j].cont);
                add=TRUE;
                j=i;
            }
        }
        if(strlen(aux)>=l && add==FALSE){
            strcpy(palavras[i].nome, aux);
            palavras[i].cont=1;
            printf("Palavra '%s' adicionada.\n", palavras[i].nome);
            i++;
        }
        scanf("%s", aux);
    }

    for(j=0;j<i;j++){
        printf("%s %d\n", palavras[j].nome, palavras[j].cont);
    }
        
    
    return 0;
}
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
};

typedef struct Palavra Palavra;

int main(){
    /* d = palavras distintas; f = numero minimo de ocorrencias de uma palavra
     * l = tamanho minimo de uma palavra; m = tamanho maximo de uma palavra 
     * n = numero de palavras armazenadas; auxn auxilia na ordenacao numerica */
    int  d, f, l, m, n=0, i, j, auxn;
    
    /* aux guarda provisoriamente a palavra lida */
    char *aux;
    
    /* add = booleano para apontar se palavra ja foi adicionada anteriormente 
     * e depois reaproveitada para a ordenacao */
    int add=FALSE;
    Palavra *palavras;
    
    scanf("%d %d %d %d", &d, &f, &l, &m);
    
    aux =  malloc(m+1 * sizeof(char));
    palavras = malloc(d * sizeof(Palavra));
    for(i=0;i<d;i++)
        palavras[i].nome = malloc(m+1 * sizeof(char));
    
    scanf("%s", aux);
    
    while(strncmp(aux,"*",1)){
        add=FALSE;
        /* verifica se a palavra ja foi armazenada */
        for(i=0;i<n;i++){
            /* caso positivo, ele aumenta o contador e quebra o loop */
            if(strcmp(palavras[i].nome,aux)==0){
                palavras[i].cont++;
                add=TRUE;
                i=n;
            }
        }
        if(strlen(aux)>=l && strlen(aux)<=m && add==FALSE){
            strcpy(palavras[n].nome, aux);
            palavras[n].cont=1;
            n++;
        }
        scanf("%s", aux);
    }
    
    /* ordenacao das palavras. cada operacao e realizada para o nome e para o 
     * contador */
      for(i=1;i<n;i++){
            j=i;
            while (j>0 && palavras[j-1].cont<palavras[j].cont) {
                  strcpy(aux, palavras[j].nome);
                  auxn = palavras[j].cont;
                  
                  strcpy(palavras[j].nome, palavras[j-1].nome);
                  palavras[j].cont = palavras[j-1].cont;
                  
                  strcpy(palavras[j-1].nome, aux);
                  palavras[j-1].cont = auxn;
                  
                  j--;
            }
      }

    /* reordenacao conforme valor lexicografico */
    add = TRUE;
    while(add){
        add = FALSE;
        for(i=0;i<n-1;i++){
            if(strcmp(palavras[i].nome, palavras[i+1].nome)>0 && 
                palavras[i].cont==palavras[i+1].cont){
                strcpy(aux, palavras[i].nome); 
                strcpy(palavras[i].nome, palavras[i+1].nome);
                strcpy(palavras[i+1].nome, aux);
                add = TRUE;
                }
        }
    }
    
    for(i=0;palavras[i].cont>=f;i++){
            printf("%s %d\n", palavras[i].nome, palavras[i].cont);
    }

    free(aux);
    for(i=0;i<d;i++)
        free(palavras[i].nome);
    free(palavras);
    
    return 0;
}
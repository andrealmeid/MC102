/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 05a - Necronomicon */

#include <stdio.h>
#include <string.h>
#define TAM 21
#define MAX 100
#define palavra_igual 0
#define palavra_diferente 1

int main(){
    int n, i, j, k;
    char nome[TAM], codigo[TAM], resultado[MAX];
    
    
    for(i=0;i<TAM;i++){
        nome[i]='\0';
        codigo[i]='\0';
    }
    
    for(i=0;i<MAX;i++)
        resultado[i]=palavra_igual;
    
    /* n = numero de palavras */
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        
        scanf("%s %s", nome, codigo);
        
        /* caso exista um  char diferente, ele sera eliminado 
         * e a string reposicionada para ocupar os espacos vazios */
        for(j=0;j<TAM-1;j++){
            if(nome[j]!=codigo[j] && codigo[j]!=0){
                for(k=j;k<TAM-1;k++){
                    codigo[k]=codigo[k+1];
                }
                j--;
            }         
        }
        
        
        
        /* depois de eliminar os chars diferentes, sera verificado 
         * se o tamanho das strings sao iguais; se forem diferentes,
         * ele ja sinaliza que as palavras nao correspondem*/
        if(strlen(codigo)!=strlen(nome))
            resultado[i]=palavra_diferente;
    }
    
    /* imprime as respostas conforme o vetor resultado */
    for(i=0;i<n;i++){
        if(resultado[i]==palavra_igual)
            printf("Sim\n");
        else
            printf("Nao\n");
    }
    
    return 0;
}
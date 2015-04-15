/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 05a - Necronomicon */

#include <stdio.h>
#include <string.h>
#define TAM 21

int main(){
    int n, i, j, k;
    char nome[TAM], codigo[TAM], resultado[100];
    
    
    for(i=0;i<TAM;i++){
        nome[i]='\0';
        codigo[i]='\0';
    }
    
    for(i=0;i<100;i++)
        resultado[i]=0;
    
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
        
        
        
        /* depois de elimiar os chars diferentes, sera verificado 
         * se o que sobrou eh igual a string original 
         * resultado[i]: 1=diferente; 0=igual */
        if(strlen(codigo)!=strlen(nome))
	  resultado[i]=1;
	
    }
    
    /* imprime as respostas conforme o vetor resultado */
    for(i=0;i<n;i++){
        if(resultado[i]==0)
            printf("Sim\n");
        else
            printf("Nao\n");
    }
    
    return 0;
    }
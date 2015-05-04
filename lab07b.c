/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 07b - Walk-Bot - Part I*/

#include <stdio.h>

#define TAM 50
#define FALSE 0
#define TRUE 1

int main(){
   
   /* mapa armazena as casas do tabuleiro, n = linhas, m = colunas */
   char mapa[TAM][TAM], peca;
   int n, m, fim;
   
   /* pos = posicao atual; mov = numero de movimentos */
   int posX, posY, mov = 0, i, j;
   
   
   scanf("%d %d", &n, &m);
   
   for(i=0;i<n;i++)
      scanf("%s", mapa[i]);
   
   
   for(i=0;i<n;i++){
      /* reinicializacao das variaveis */
      fim=FALSE;
      posX=0;
      posY=i;
      mov=0;
      peca = mapa[i][0];
      
      while(fim==FALSE){      
         switch(peca){
            case 'R':
               posX++;
               break;
               
            case 'L':
               posX--;
               break;
               
            case 'U':
               posY--;
               break;
               
            case 'D':
               posY++;
               break;
         }
         
         if(posX>m-1){
            printf("Saiu em em (%d,%d) apos %d passo(s)\n", 
                   posY+1, posX+1, mov);
            fim=TRUE;
         }
         
         
         mov++;
         peca = mapa[posY][posX];
         printf("peça: %c ", peca);
         
         printf("pos(%d,%d)\n", posY, posX);
         
         if(posX>m-1){
            printf("Saiu em em (%d,%d) apos %d passo(s)\n", 
                   posY+1, posX+1, mov);
            fim=TRUE;
         }
         
         if(mov>40)
            fim=TRUE;
      }
      
      printf("n=%d\n", i);
   }
   
   
   
   return 0;
}
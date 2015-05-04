/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 07b - Walk-Bot - Part I*/

#include <stdio.h>

#define TAM 51
#define FALSE 0
#define TRUE 1

int main(){
   
   /* mapa armazena as casas do tabuleiro, n = linhas, m = colunas */
   char mapa[TAM][TAM], mapaLoop[TAM][TAM], peca;
   int n, m, fim, loop = 0;
   
   /* pos = posicao atual; mov = numero de movimentos */
   int posX, posY, mov = 0, i, j, k, l;
   
   for(i=0;i<TAM;i++)
      for(j=0;j<TAM;j++)
         mapaLoop[i][j]=0;
   
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
      loop=0;
      for(k=0;k<TAM;k++)
         for(l=0;l<TAM;l++)
            mapaLoop[k][l]=0;
      
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
               
            case 'X':
               printf("Armadilha em (%d,%d) apos %d passo(s)\n",
                      posY+1, posX+1, mov);
               fim=TRUE;
               break;
               
         }
         
         
         if(posX>m-1){
            printf("Saiu em (%d,%d) apos %d passo(s)\n", 
                   posY+1, posX, mov);
            fim=TRUE;
         }
         
         mapaLoop[posY][posX]++;
         if(mapaLoop[posY][posX]>=2){
            if(mapaLoop[posY][posX]==3){
               printf("Loop de tamanho %d\n", loop);
               fim=TRUE;
            } else
               loop++;
         }
         
         mov++;
         peca = mapa[posY][posX];
      }
   }
 
   return 0;
}
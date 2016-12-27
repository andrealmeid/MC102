/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 07b - Walk-Bot - Part I*/

#include <stdio.h>

#define TAM 50
#define FALSE 0
#define TRUE 1

int main(){
   
   /* mapa armazena as casas do tabuleiro; mapaLoop verifica se o robo
    * esta repetindo as posicoes; peca = casa do tabuleiro atual */
   char mapa[TAM][TAM], mapaLoop[TAM][TAM], peca;
   
   /* n = linhas, m = colunas; fim = aponta se o caminho acabou ou
    * se deve ser interrompido; loop = conta o tamanho do loop */
   int n, m, fim, loop;
   
   /* pos = posicao atual do robo; mov = numero de movimentos */
   int posX, posY, mov, i, j, k, l;
   
   /* inicializa a matriz mapaLoop */
   for(i=0;i<TAM;i++)
      for(j=0;j<TAM;j++)
         mapaLoop[i][j]=0;
   
      
   scanf("%d %d", &n, &m);
   
   for(i=0;i<n;i++)
      scanf("%s", mapa[i]);
   
   
   /* percorre todos os n caminhos */
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
               /* verifica se a proxima posicao nao esta fora dos limites 
                * da matriz. se sim, imprime o resultado e encerra o caminho 
                * se nao, move uma casa pra direita */
               if(posX+1>m-1){
                  printf("Saiu em (%d,%d) apos %d passo(s)\n", 
                        posY+1, posX+1, mov);
                  fim=TRUE;
               } else
                  posX++;
               break;
            
            /* move uma casa para esquerda */
            case 'L':
               posX--;
               break;
            
            /* move uma casa para cima */
            case 'U':
               posY--;
               break;

            /* move uma casa para baixo */               
            case 'D':
               posY++;
               break;
            
            /* se a casa for uma armadilha, imprime a posicao e finaliza */
            case 'X':
               printf("Armadilha em (%d,%d) apos %d passo(s)\n",
                        posY+1, posX+1, mov);
               fim=TRUE;
               break;     
         }
         
         /* bloco que verifica se entrou em loop infinito.
          * se o robo passar uma segunda vez no mesmo lugar, um contador 
          * aumenta ate que ele passe uma terceira vez e interrompe a linha*/
         mapaLoop[posY][posX]++;
         if(mapaLoop[posY][posX]>=2){
            if(mapaLoop[posY][posX]==3){
               printf("Loop de tamanho %d\n", loop);
               fim=TRUE;
            } else
               loop++;
         } 
         
         /* aumenta a contagem dos movimentos a cada ciclo */
         mov++;
         /* atribui a peca o valor da casa do prox ciclo */
         peca = mapa[posY][posX];
      }
   }
   
   return 0;
}
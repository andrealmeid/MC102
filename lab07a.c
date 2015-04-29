/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 07a - Cargo-Bot - Part II*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
   
   /* x = posicoes para empilhamento de caixas; y=numero max de empilhamento
    * p = num de programas; c = num max de comandos por programa; e = num de 
    * execucoes de programas */
   int x, y, p, c, e, i, j;
   
   /* sqnc = sequencia dos programas */
   int sqnc[60];
   
   /* progs = armazena cada programa em uma linha; boxes = posicionamento 
    * das caixas */
   char progs[9][60], boxes[10][10];
   
   /* braco = posicao do braco; hold = guarda se braco segura uma caixa */
   int braco = 0, hold = FALSE;
   
   /* entrada da primeira linha */
   scanf("%d %d %d %d %d", &x, &y, &p, &c, &e);
   
   /* entrada das posicoes iniciais das caixas */
   scanf("");
   for(i=0;i<x;i++)
      for(j=0;j<y;j++)
         scanf("%c", &boxes[i][j]);
   
   for(i=0;i<x;i++)
      for(j=0;j<y;j++)
         printf("%c", boxes[i][j]);
      
   printf("BOXES OK\n");
   
   /* entrada da sequencia de execucao dos programas *   
   for(i=0;i<e;i++)
      scanf("%d", &sqnc[i]);
   printf("SQNC OK\n");
   
   /* entrada dos comandos dos programas; quando for encontrado o fim (*) do
    * programa, o preenchimento daquela linha é esgotado e pula pra prox 
    * j<=c para poder armazenar o asterisco * 
   for(i=0;i<p;i++)
      for(j=0;j<=c;j++){
         scanf("%c", &progs[i][j]);
         if(progs[i][j]=='*')
            j=c;
         printf("PROGS LINHA OK\n");
      }
   printf("PROGS OK\n");*/

   
      
   return 0;
}

/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 07a - Cargo-Bot - Part II*/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(){
   
   /*VARIAVEIS*/
   /* x=posicoes para empilhamento de caixas; y=numero max de empilhamento */
   int x, y;
   
   /* p = num de programas; c = num max de comandos de programas*/
   int p, c;
   
   /* e = num de execucoes de programas; i, j, k, l = contadores */
   int e, i, j, k, l, num;
   
   /* boxes = posicionamento das caixas */
   char boxes[10][10];

   /* sqnc = sequencia dos programas*/
   char sqnc[60];
  
   /* progs = armazena cada programa em uma linha, duas pos extras foram
    * adicionada para guardar o asterisco e o \0 */
   char progs[9][62];
  
   /* garra = posicao da garra; acidente indica se ocorreu algum acidente */
   int garra=0, acidente = FALSE;
   
   /* hold = guarda o que a garra segura
    * . = nada, B = caixa azul, G = caixa verde*/
   char hold='.';
   
   /*ENTRADAs*/
   /* entrada da primeira linha */
   scanf("%d %d %d %d %d", &x, &y, &p, &c, &e);
  
   /* entrada das posicoes iniciais das caixas */
   for(i=0;i<y;i++)
      scanf("%s", boxes[i]);
    
   /* entrada da sequencia de execucao dos programas */
   scanf(" ");
   for(i=0;i<e;i++)
      scanf("%c", &sqnc[i]);
  
   /* entrada dos comandos dos programas */
   for(i=0;i<p;i++)
      scanf("%s", progs[i]);
   
   /*PROCESSAMENTOS*/

   for(k=0;k<e;k++){
      i=0;
      num=sqnc[k]-'1';
      printf("%d\n", num);
      while(progs[num][i]!='*'){
         j=0;
         switch(progs[0][i]){
            case 'D':
               if(hold=='.'){
                  while(boxes[j][garra]=='.' && j<y-1)
                     j++;
                  hold=boxes[j][garra];
                  boxes[j][garra]='.';
               } else {
                  for(j=0;j<y;j++)
                     if(boxes[j+1][garra]!='.')
                        break;
                     boxes[j][garra]=hold;
                  hold='.';
               }
               break;
               
            case 'R':
               if(garra<x)
                  garra++;
               break;
               
            case 'L':
               if(garra>0)
                  garra--;
               break;
               
            case 'B':
               if(hold!='B')
                  i++;
               break;
               
            case 'G':
               if(hold!='G')
                  i++;
               break;
         }
         /*printf("comando=%c j=%d garra=%d hold=%c",progs[0][i], j, garra, hold);
          *   printf("\n");          */
         
         
         i++;
      }
   }
   
   for(i=0;i<y;i++){
      printf("%s", boxes[i]);
      printf("\n");    
      }
   return 0;
}
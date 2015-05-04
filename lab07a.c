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
   
   /* e = num de execucoes de programas; i, j, k = contadores 
    * num serve de variavel auxiliar para uma conversao */
   int e, i, j, k, num;
   
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
   /* o loop percorre o vetor executando os programas */
   for(k=0;k<e;k++){
      i=0;
      /* conversao char -> int = char - '1' */
      num=sqnc[k]-'1';
      /* para o loop quando encotnar o fim do programa (*) */
      while(progs[num][i]!='*'){
         j=0;
         switch(progs[num][i]){
            /* pegar/soltar caixa */
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
            
            /* move para direita se for possivel */   
            case 'R':
               if(garra<x-1)
                  garra++;
               if(boxes[0][garra]!='.' && hold!='.')
                  acidente=TRUE;
               break;
               
            /* move para esquerda se for possivel */   
            case 'L':
               if(garra>0)
                  garra--;
               if(boxes[0][garra]!='.' && hold!='.')
                  acidente=TRUE;
               break;
               
            /* nesse bloco, se as condicoes nao forem verdadeiras,
             * o programa pula a proxima instrucao. se forem, ele as executa */
            case 'B':
               if(hold!='B')
                  i++;
               break;
               
            case 'G':
               if(hold!='G')
                  i++;
               break;
            
            case 'N':
               if(hold!='.')
                  i++;
               break;
            
            case 'A':
               if(hold=='.')
                  i++;
               break;
         }      
         
         /* se ocorreu algum acidente, quebra o loop */
         if(acidente==TRUE)
            k=e;
         
         i++;
      }
   }
   
   /* imprime as posicoes das caixas se nenhum acidente ocorreu */
   if(acidente==FALSE)
      for(i=0;i<y;i++){
         printf("%s", boxes[i]);
         printf("\n");    
      }
   else 
      printf("Um acidente ocorreu\n");
   return 0;
}
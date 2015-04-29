/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 07a - Cargo-Bot - Part II*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* braco = posicao do braco; hold = guarda se braco segura uma caixa */
int braco=0, hold = FALSE, acidente = FALSE;

/* boxes = posicionamento das caixas */
char boxes[10][10];


void executarPrograma(int progAtual, char progMatriz[][62]){
  char programa[62] = progMatriz[progAtual];
  int k=0;
  
  while(programa[k]!='*'){
    mover(programa[k], k);
    k++;
  }
}

void mover(char comando, int posicao){
  switch(comando){
    case 'L':
      if(braco<0){
	if(hold==TRUE && boxes[braco-1][0]!='.'){
	  acidente=TRUE;
	} else
	braco--;
	break;
      }
      
}

int main(){
  
  /* x = posicoes para empilhamento de caixas; y=numero max de empilhamento
   * p = num de programas; c = num max de comandos por programa; e = num de 
   * execucoes de programas */
  int x, y, p, c, e, i, j;
  
  /* sqnc = sequencia dos programas*/
  char sqnc[60];
  
  /* progs = armazena cada programa em uma linha, uma pos extra foi 
   * adicionada para guardar o asterisco */
  char progs[9][62];
  
  /* entrada da primeira linha */
  scanf("%d %d %d %d %d", &x, &y, &p, &c, &e);
  
  /* entrada das posicoes iniciais das caixas */
  for(i=0;i<x;i++)
    scanf("%s", boxes[i]);
  
  for(i=0;i<x;i++)
    for(j=0;j<y;j++)
      printf("%c", boxes[i][j]);
    
    scanf(" ");
  /* entrada da sequencia de execucao dos programas */
  for(i=0;i<e;i++)
    scanf("%c", &sqnc[i]);
  
  /* entrada dos comandos dos programas */
  for(i=0;i<p;i++)
    scanf("%s", progs[i]);
  
  for(i=0;i<e;i++){
    executarPrograma(i, progs); 
    
  }
  
  return 0;
}
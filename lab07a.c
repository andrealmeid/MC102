/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 07a - Cargo-Bot - Part II*/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/* braco = posicao do braco; hold = guarda o que o braco segura,
 * F = nada, B = caixa azul, G = caixa verde*/
int braco=0, acidente = FALSE;
char hold='F';

/* boxes = posicionamento das caixas */
char boxes[10][10];

void mover(char comando, int posicao){
int i;
  switch(comando){
    
    case 'L':
      if(braco>0){
	if(hold!='F' && boxes[braco-1][0]!='.'){
	  acidente=TRUE;
	} else
	braco--;
      }
	break;

    case 'R':
      if(braco<x){
	if(hold!='F' && boxes[braco+1][0]!='.'){
	  acidente=TRUE;
	} else
	braco++;
      }
	break;
	
    case 'D':
      i=0;
      if(hold!='F'){
	do{
	  hold = boxes[braco][i];
	  boxes[braco][i]='.';
	  i++;
	}while(boxes[braco][i]=='.');
      } 
      else {
	while(boxes[braco][i]=='.')
	  i++;
	boxes[braco][i]=hold;
      }
      break;
      
  }  
}

void executarPrograma(int progAtual, char progMatriz[][62]){
  char programa[62];
  int k=0;
   
  strcpy(programa,progMatriz[progAtual]);

  while(programa[k]!='*'){
    mover(programa[k], k);
    k++;
  }
}


int main(){
  
  /* x = posicoes para empilhamento de caixas; y=numero max de empilhamento
   * p = num de programas; c = num max de comandos por programa; e = num de 
   * execucoes de programas */
  int x, y, p, c, e, i;
  
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
    
  /* entrada da sequencia de execucao dos programas */
  scanf(" ");
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
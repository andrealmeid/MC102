/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 04a - Cargo-Bot - Part I*/

#include <stdio.h>
#include <math.h>
#define M 11

int main(){
  
  int x[M], y, i, pos = 1, box = 0;
  char mov;
  
  for(i=0;i<M;i++)
    x[i]=0;
  
  /*a posicao 0 do vetor guarda o numero de posicoes*/
  scanf("%d %d", &x[0], &y);
  
  /*cada i>0 do vetor guarda seu respectivo numero de caixas*/
  for(i=1;i<=x[0];i++)
    scanf("%d", &x[i]);
  
  do{
    scanf("%c", &mov);
    switch(mov){
      case 'D':
	if(box==0){
	  x[pos]-=1;
	  box=1;
	}else{
	  x[pos]+=1;
	  box=0;
	}
	break;
      case 'R':
	pos+=1;
	break;
      case 'L':
	pos-=1;
	break;
    }
  }while(mov!='*');
  
    for(i=1;i<=x[0];i++)
    printf("%d ", x[i]);
  
    printf("\n");
  return 0;
}
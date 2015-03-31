/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 03a - Admiravel Mundo Novo */

#include <stdio.h>
#include <math.h>
#define MX 100

int main(){
  
  int l, c, i, tot[MX], pos, total=0;
  char get;
  double porc;
  
  for(i=0;i<MX;i++)
    tot[i]=0;
  
  
  scanf("%d %d", &l, &c);
  
  for(i=0;i<=l;i++){
    do{
      scanf("%c", &get);
      pos = (int)get-48;
      tot[pos]+=1;
      if(get!=10 && get!=32)
	total+=1;
    }while(get!=10);
  }
  
  printf("Total: %d individuos\n", total);
  
  for(i=1;i<=c;i++)
    printf("Total da casta %d: %d\n", i, tot[i]);
  
  for(i=1;i<=c;i++){
    porc = ((tot[i]*100.0)/total);
    printf("Percentual da casta %d: %.2f\n", i, porc);
  }
  
  return 0;
}
/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 02b - Dólares Élficos */

#include <stdio.h>
#include <math.h>
#define MAX 100

int main(){
  
  /*variaveis
   *    int i, n, g, c, capital;
   *    int casa[100]; 
   *    
   *    
   *    scanf("%d %d %d", &n, &g, &c);
   *    
   *    for(i=0;i<n;i++)
   *        scanf("%d", &casa[i]);
   *    
   *    processamento
   *    capital = g * c;
   */
  
  int i, valor, fator, potencias[MAX], menor=0, cont=0;
  
  for(i=0;i<MAX;i++)
    potencias[i]=0;
  
  scanf("%d %d", &valor, &fator);
  
  i=0;
  while(potencias[i-1]<=valor){
    potencias[i] = pow(fator, i);
    i++;
    menor++;
  }
  
  /*remove o último valor do vetor, que sera maior que o valor da entrada*/
  menor--;
    /*menor--;*/
  
  printf("Existem %d valores menores do que %d, que sao:\n", menor, valor);
  for(i=0;i<menor;i++)
    printf("%d\n", potencias[i]);
  
  /**/
  i=menor;
  while(valor>0){
    printf("valor=%d\npot=%d\n", valor, potencias[i]);
    if(valor>=potencias[i]){
      valor-=potencias[i];
      cont++;     
    }
    else{
      i--;
    }
  }
      printf("valor=%d\npot=%d\n", valor, potencias[i]);
  printf("foram feitas %d operacoes\n", cont);
  
  return 0;
}
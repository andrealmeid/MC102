/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 02a - Coeficiente de Rendimento */

#include <stdio.h>
#include <math.h>

int main(){
  
  char x, aux;
  int y, divisor = 0, dividendo = 0;
  float resultado;
  
  while(x!='*'){
    scanf("%c", &x);
    if(x!='*'){
      scanf(" %d", &y);
      scanf("%c", &aux);
      dividendo += (69-x) * y;
      divisor += y;
      /*printf("x=%d\n", x);
      printf("y=%d\n", y);
      printf("dividendo=%d\n", dividendo);
      printf("divisor=%d\n", divisor); */
    }
  }
  
  resultado = (float) dividendo / divisor;
  /*printf("#dividendo=%d\n", dividendo);*/
  /*printf("#divisor=%d\n", divisor);*/
  if  (divisor != 0)
    printf("CR = %.4f\n", resultado);
  else
    printf("CR = Indefinido\n");
  
  return 0;  
}

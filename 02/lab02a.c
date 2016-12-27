/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 02a - Coeficiente de Rendimento */

#include <stdio.h>
#include <math.h>

int main(){
    
  /*variaveis*/
  char x, aux;
  int y=-1, divisor = 0, dividendo = 0;
  double resultado;
  
  /*entrada*/
  /*var aux ira descartar o \n da leitura*/
  while(x!='*'){
    scanf("%c", &x);
    if(x!='*'){
      scanf(" %d", &y);
      scanf("%c", &aux);
      dividendo += (69-x) * y;
      divisor += y;
    }
  }
  
  /*processamento*/
  resultado = (double) dividendo / divisor;
  
  /*saida*/
  /*verifica o tipo de saida conforme o valor obtido*/
  if  (y >= 0){
    if(y==0){
      resultado = 0;
    }
    printf("CR = %.4f\n", resultado);
  }
  else
    printf("CR = Indefinido\n");
  
  return 0;  
}
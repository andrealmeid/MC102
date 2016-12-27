/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 01b - Conta de Água */

#include <stdio.h>
#include <math.h>

int main(){
  
  /*VARIAVEIS*/
  /*var fatia ira 'fatiar' o consumo para
   *     obter os valores conforme as faixas;
   *     cons = consumo;
   *     aux = variavel auxiliar;*/
  int consNow, consPast, fatia, aux;
  float orgnl=0, final=0, dif;
  
  /*ENTRADA*/
  scanf("%d %d", &consPast, &consNow);
  
  /*PROCESSAMENTOS*/
  /*ORIGINAL*/
  aux = consNow;
  if (consNow > 50){
    fatia = consNow-50;
    orgnl = fatia * 4.43;
    consNow -= fatia;
  } 
  if (consNow > 20){
    fatia = consNow-20;
    orgnl += fatia * 3.7;
    consNow -= fatia;
  } 
  if (consNow > 10){
    fatia = consNow-10;
    orgnl += fatia * 2.41;
    consNow -= fatia;
  } 
  if (consNow > 0) {
    orgnl += 17.34;
  }
  
  /*FINAL*/
  consNow = aux;
  dif = (100.0*consNow)/consPast;
  dif -= 100;
  printf("Difernça: %.2f\n", dif);
  
  /*DESCONTO*/
  if (dif <= -10){
    
    if (dif > -15){
      final = orgnl - orgnl*0.1;
    } else if (dif > -20){
      final = orgnl - orgnl*0.2;
    } else {
      final = orgnl - orgnl*0.3;
    }
  
  /*MULTA*/
  } else if (dif > 0){
   
    if (dif < 20){
      final = orgnl + orgnl*0.4;
    } else {
      final = orgnl + orgnl*1;
    }
  } else {
    final = orgnl;
  }
  
  
  /*SAIDA*/
  printf("Valor original = %.2f\n", orgnl);
  printf("Valor final = %.2f\n", final);
  
  return 0;
}
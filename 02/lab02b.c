/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 02b - Dólares Élficos */

#include <stdio.h>
#include <math.h>
#define MX 100

int main(){
  
  /*variaveis*/
  int i, j, nCasas, g, c, capital, valor, potencias[MX], casa[MX], notas, cont; 
  
  for(i=0;i<MX;i++)

    casa[i]=0;
  
  /*entrada*/
  scanf("%d %d %d", &nCasas, &g, &c);
  
  for(i=0;i<nCasas;i++)
    scanf("%d", &casa[i]);
  
  /*processamento*/
  /*capital = valor de ouro em dolares*/
  capital = g * c;
  
  /*calculo repetido para cada casa*/
  for(j=0;j<nCasas;j++){
    
    /*reinicia as variaveis*/
    for(i=0;i<MX;i++)
    potencias[i]=0;
    i=0;
    valor=capital;
    cont=0;
    notas=0;
    
    /*identifica as notas que a casa tem para realizar a troca*/
    while(potencias[i-1]<=capital){
      potencias[i] = pow(casa[j], i);
      i++;
      notas++;
    }
    
    /*ignora a ultima nota, que sera maior que o valor capital*/
    notas--;
    
    /*realiza as subtracoes com as notas disponiveis ate que valor=0*/
    i=notas;
    while(valor>0){
      if(valor>=potencias[i]){
    valor-=potencias[i];
    cont++;     
      }
      else{
    i--;
      }
    }
    
    /*apos contar quantas operacoes foram feitas, guarda essa valor no vetor*/
    casa[j]=cont;
  }
  
  /*compara os resultados, reutilizando a var capital como o menor valor*/
  capital=casa[0];
  for(j=0;j<nCasas;j++){
     if(casa[j]<capital)
       capital=casa[j];
  }
  
  /*saida*/
  printf("Numero minimo de notas = %d\n", capital);
  
  return 0;
}
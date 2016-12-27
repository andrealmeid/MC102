/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 03b - O Enigma dos Guardioes Quanticos*/

#include <stdio.h>
#include <math.h>
#define MX 101

int main(){
  
  /* variaveis*/
  int n, g[MX], i, j, min[MX], max[MX], nSinc=0;
  
  for(i=0;i<MX;i++){
    g[i]=0;
    min[i]=0;
    max[i]=0;
  }
  
  /* entrada*/
  scanf("%d", &n);
  
  /* recebe os intervalos e guarda o num de vezes que cada total de sinceros aparece*/
  for(i=1;i<=n;i++){
    scanf("%d %d", &min[i], &max[i]);
    for(j=min[i];j<=max[i];j++)
      g[j]++;
  }
  
  /* verifica qual o numero com mais ocorrencia
  *  esse numero sera o total de guardioes sinceros
  *  se ele for coerente com o numero de ocorrencias*/
  for(i=1;i<=n;i++){
    if(g[i]>=g[nSinc] && i==g[i])
      nSinc=i;
  }
  
  /* saida*/
  printf("Numero de guardioes sinceros = %d\n", nSinc);
  
  /* procura e imprime o primeiro guardiao que cita o numero correto*/
  for(i=1;i<=n;i++){
    for(j=min[i];j<=max[i];j++)
      if(j==nSinc){
	printf("Guardiao %d\n", i);
	i=n;
      }
  }
  return 0;
}
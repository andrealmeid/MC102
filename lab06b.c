/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 06b - A Ameaça Fantasma */

#include <stdio.h>
#define TAM 101

int contaminar(int *p1, int *p2, int *p3, int *p4, int *limp){
  /* como um espaco contamidado pode contaminar os outros, ele pode ser
   * considerado um dispersor; nesse metodo, as posicoes sao marcadas com 
   * o valor 3, que signica pre-contamidas para depois virarem dispersores
   * p1-p4 sao ponteiros que apontam para as coordenadas dos espacos 
   * o retorno informa se ocorreu alguma contaminacao bem sucedida*/
  
  int retorno=0;
  
  if(*p1==0){
    *p1=3;
    *limp-=1;
    retorno=1;
  }
  
  if(*p2==0){
    *p2=3;
    *limp-=1;
    retorno=1;    
  }
  
  if(*p3==0){
    *p3=3;
    *limp-=1;
    retorno=1;    
  }    
  
  if(*p4==0){
    *p4=3;
    *limp-=1;
    retorno=1;    
  }    
  
  return retorno;
}

int main(){
  
  /* rcnt guarda as caracteristicas do recinto;
   * tempo é o tempo de dispersao;
   * limpos guarda os espacos vazios
   * agiu verifica se alguma contaminacao ocorreu */
  int rcnt[TAM][TAM], m, n, tempo=0, i, j, limpos=0, agiu=-1;
  
  /* inicializa a matriz preenchendo ela com paredes */
  for(i=0;i<TAM;i++)
    for(j=0;j<TAM;j++)
      rcnt[i][j]=1;
    
  /* entrada das dimensoes da matriz (m,n) */
  scanf("%d %d", &m, &n);
  
  /* entrada dos valores da matriz 
   * a matriz comeca a ser preenchida da pos[1][1] para que exista
   * uma borda de paredes em volta da sala inserida */
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
      scanf("%d", &rcnt[i][j]);
    
  /* faz a contagem dos espacos vazios sem dispersores*/
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
      if(rcnt[i][j]==0)
	limpos++;
	
  /* verificacao e acao dos aspersores 
   * o laco so continua se agiu for negativo, ou seja, se ocorrer uma 
   * contaminacao no laco anterior */
  while (agiu<0){
    agiu=0;
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
	if(rcnt[i][j]==3)
	  rcnt[i][j]--;
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
	    if(rcnt[i][j]==2){
	    /* se o lugar for um dispersor, ele ira passar as coordenadas dos
	     * espacos vizinhos para o metodo contaminar */
	        agiu -= contaminar(&rcnt[i+1][j],&rcnt[i-1][j],
			                   &rcnt[i][j-1],&rcnt[i][j+1], &limpos);
	}
    tempo++;
  }
	
  /* se todos os espacos vazios estiverem contaminados,
   * imprimir o tempo de contaminacao */
    if(limpos==0)
      printf("Tempo = %d\n", tempo);
    else
      printf("Perigo: Jedis podem estar vivos\n");
  
  return 0;
}
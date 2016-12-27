/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 06b - A Ameaça Fantasma */

#include <stdio.h>
#define TAM 101

int contaminar(int matr[TAM][TAM], int a, int b, int *limp){
  /* como um espaco contamidado pode contaminar os outros, ele pode ser
   * considerado um dispersor; nesse metodo, as posicoes sao marcadas com 
   * o valor 3, que signica pre-contamidas para depois virarem dispersores
   * a e b sofrem operacoes para apontarem para os espacos vizinhos
   * o retorno informa se ocorreu alguma contaminacao bem sucedida*/
  
  int retorno=0;
  
  if(matr[a-1][b]==0){
    matr[a-1][b]=3;
    *limp-=1;
    retorno=1;
  }
  
  if(matr[a+1][b]==0){
    matr[a+1][b]=3;
    *limp-=1;
    retorno=1;    
  }
  
  if(matr[a][b-1]==0){
    matr[a][b-1]=3;
    *limp-=1;
    retorno=1;    
  }    
  
  if(matr[a][b+1]==0){
    matr[a][b+1]=3;
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
	     * espacos para o metodo contaminar */
	        agiu -= contaminar(rcnt, i, j, &limpos);
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
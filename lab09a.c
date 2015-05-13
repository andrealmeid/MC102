/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 09a - A Batalha de Geonosis */

#include <stdio.h>
#include <stdlib.h>

int main(){
   
   int m, n, **campo, i, j, k, aux;
   
   int *linhas, *colunas, *dp, *ds;
   
   
   scanf("%d %d", &m, &n);
   
   linhas = malloc(m * sizeof(int));
   colunas = malloc(n * sizeof(int));
   
   for(i=0;i<m;i++)  
      linhas[i]=0;
   
   for(i=0;i<n;i++)  
      colunas[i]=0;
   
   campo = malloc(m * sizeof(int));
   for(i=0;i<m;i++)
      campo[i] = malloc(n * sizeof(int));
   
   for(i=0;i<m;i++)
      for(j=0;j<n;j++)
         scanf("%d", &campo[i][j]);
   
   for(i=0;i<m;i++){
      for(j=0;j<n;j++){
         if(campo[i][j]==1)
            linhas[i]++;
      }
   }
   
   for(i=0;i<n;i++){
      for(j=0;j<m;j++){
         if(campo[j][i]==1)
            colunas[i]++;
      }
   }
   
   i=0, j=0, k=0, aux=0;
   while(i+j+aux>m+n){
      i=k;
      while(i>m || j>n){
         j = k + i;
         dp[k]+=campo[i][j];
      }
         
   
   
   /*for(i=0;i<m;i++)
      printf("linha[%d]=%d\n", i+1, linhas[i]);
   printf("\n");
   
   for(i=0;i<n;i++)
      printf("%d ", colunas[i]);
   printf("\n");*/
   
   /*for(i=0;i<m;i++){
      for(j=0;j<n;j++){
         printf("%d ", campo[i][j]);
      }
   printf("\n");
   }*/
         
   return 0;
}
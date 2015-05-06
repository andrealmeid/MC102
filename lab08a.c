/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 08a - BigCalc */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* realiza a adicao n1+n2, armazendo o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
   int i;   
   
   for(i=0; i<tam_n2; i++){
      result[i] += n1[i] + n2[i];
      if(result[i]>9){
         result[i]=result[i]%10;
         result[i+1]++;
      }
      
   }
   
   for(;i<tam_n1;i++)
      result[i]+=n1[i];
   
   if(result[tam_n1]==0)
      tam_n1--;
   for(i=tam_n1;i>=0;i--)
      printf("%d", result[i]);
   printf("\n");
}

/* realiza a subtracao n1-n2, com n1>=n2, armazenando o resultado em result */
void substract(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
   int i;
   
   for(i=0; i<tam_n2; i++){
      if(n1[i]>=n2[i]){
         result[i] = n1[i] - n2[i];
      } else {
         n1[i]+=10;
         n1[i+1]--;
         result[i] = n1[i] - n2[i];         
      }

   }
   
   for(;i<tam_n1;i++){
      if(n1[i]>=0)
         result[i]=n1[i];  
      else{
         n1[i]+=10;
         n1[i+1]--;
         result[i]=n1[i];  
      }
   }
   
   for(i=tam_n1-1; result[i]==0 && i>0; i--)
      tam_n1--;
   
   for(i=tam_n1-1;i>=0;i--)
      printf("%d", result[i]);   
   printf("\n");
}

/* realiza a multiplicacao n1*n2, armazendo o resultado em result */
void multiply(int *n1, int tam_n1, int *n2, int tam_n2, int *result) {
int i, j, tam;
	for(i=0;i<tam_n2;i++)
		for(j=0;j<tam_n1;j++){
			result[j+i]+=n2[i]*n1[j];
			if(result[j+i]>9){
				result[j+i+1]+=result[j+i]/10;
				result[j+i]=result[j+i]%10;
			}
		}
	
	tam = tam_n1 + tam_n2;
	
	for(i=tam; result[i]==0 && i>0; i--)
      tam--;
	
	
   for(i=tam;i>=0;i--)
      printf("%d", result[i]);   
   printf("\n");
}



int main() {    
   
   int x, y, *n1, *n2, *result, i, z;
   char c, aux;
   
   scanf("%d %d %c", &x, &y, &c);
   
   n1 = malloc(x * sizeof(int));
   n2 = malloc(y * sizeof(int));
   
   scanf(" ");
   for(i=x-1;i>=0;i--){
      scanf("%c", &aux);
      n1[i]= aux - '0';
   }
   
   scanf(" ");
   for(i=y-1;i>=0;i--){
      scanf("%c", &aux);
      n2[i]= aux - '0';
   }
   
   
   switch(c){
      case 'A':
         z = x+1;
         result = malloc(z * sizeof(int));
         for(i=0;i<z;i++)
            result[i]=0;
         add(n1, x, n2, y, result);
         break;
         
      case 'S':
         result = malloc(x * sizeof(int));
         substract(n1, x, n2, y, result);
         break;
         
      case 'M':
         z = x+y;
         result = malloc(z * sizeof(int));
		for(i=0;i<z;i++)
            result[i]=0;
         multiply(n1, x, n2, y, result);
         break;
             
   }
   
   return 0;
}
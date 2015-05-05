/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 08a - BigCalc */

#include <stdio.h>
#include <stdlib.h>

/* realiza a adicao n1+n2, armazendo o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
   int i, j;   
      
   for(i=tam_n1-1, j=tam_n2-1; i<=0; i--, j--){
         result[i] = n1[i] + n2[j];
         printf("%d", result[i]);
   }
	 printf("\n");
   
}


int main() {    
   
   int x, y, *n1, *n2, *result, i, z;
   char c, aux;
   
   scanf("%d %d %c", &x, &y, &c);
   
   n1 = malloc(x * sizeof(int));
   n2 = malloc(y * sizeof(int));

   scanf(" ");
   for(i=0;i<x;i++){
      scanf("%c", &aux);
      n1[i]= aux - '0';
   }
   
   scanf(" ");
   for(i=0;i<y;i++){
      scanf("%c", &aux);
      n2[i]= aux - '0';
   }
   
   switch(c){
      case 'A':
	 z = x+1;
         result = malloc(z * sizeof(int));
         add(n1, x, n2, y, result);
         break; 

   }
   /*
   for(i=0;i<z;i++)
   printf("%d", result[i]);
   printf("\n");
   */
   return 0;
}
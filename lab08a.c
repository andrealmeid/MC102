/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 08a - BigCalc */

#include <stdio.h>
#include <stdlib.h>

/* realiza a adicao n1+n2, armazendo o resultado em result */
void add(int *n1, int tam_n1, int *n2, int tam_n2, int *result) { 
   int i;   
      
   for(i=0;i<tam_n1;i++)
         *result += n1[i] + n2[i];
   
}


int main() {    
   
   int x, y, *n1, *n2, *result, i;
   char c, aux;
   
   scanf("%d %d %c", &x, &y, &c);
   
   n1 = malloc(x * sizeof(int));
   n2 = malloc(y * sizeof(int));

   for(i=0;i<x;i++){
      scanf("%c", aux);
      n1[i]= aux - '0';
      printf("%d", *n1);
   }
   
   printf("%d\n", *n1);
   
   switch(c){
      case 'A':
         result = malloc(x+1 * sizeof(int));
         add(n1, x, n2, y, result);
         break; 

   }
   
   printf("%d\n", *result);
   
   
   return 0;
}

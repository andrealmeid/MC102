/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 02b - Dólares Élficos */

#include <stdio.h>
#include <math.h>

int main(){
    
    /*variaveis
    int i, n, g, c, capital;
    int casa[100]; 
    
    
    scanf("%d %d %d", &n, &g, &c);
    
    for(i=0;i<n;i++)
        scanf("%d", &casa[i]);
    
    processamento
    capital = g * c;
    */
    
    int i, valor, fator;

    scanf("%d %d", &valor, &fator);
    
    for(i=1;i<valor;i++)
        printf("%.0f\n", pow(fator, i));
        
    return 0;
}
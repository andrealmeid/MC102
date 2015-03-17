/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 01A - Coding Bad */

#include <stdio.h>
#include <math.h>

int main(){
    
    /*VARIAVEIS (nomeadas conforme sugestao do exercicio)*/
    double C, i, M, montante, lote;
    int n;
    
    /*ENTRADA*/
    scanf("%lf %lf %d %lf", &C, &i, &n, &M);
    
    /*PROCESSAMENTOS*/
    /*CALCULO 1*/
    i = i/100;
    i++;
    montante = C * pow(i, n);
    
    /*CALCULO 2*/
    lote = log(M/C)/log(i);
    lote = ceil(lote);
    
    /*SAIDA*/
    printf("Montante = %.2lf\n", montante);
    printf("%.0lf lote(s)\n", lote);
    
    return 0;
}
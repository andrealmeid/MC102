#include <stdio.h>
#include <math.h>

int main(){
    
    /*VARIAVEIS*/
    /*var fatia ira 'fatiar' o consumo para
     obter os valores conforme as faixas*/
    int consNow, consPast, fatia;
    float orgnl=0, final=0;
    
    /*ENTRADA*/
    scanf("%d %d", &consPast, &consNow);
    
    /*PROCESSAMENTOS*/
    /*ORIGINAL*/
    if (consNow > 50){
        fatia = consNow-50;
        orgnl = fatia * 4.43;
        consNow -= fatia;
    } 
    if (consNow > 20){
        fatia = consNow-20;
        orgnl += fatia * 3.7;
        consNow -= fatia;
    } 
    if (consNow > 10){
        fatia = consNow-10;
        orgnl += fatia * 2.41;
        consNow -= fatia;
    } 
    if (consNow > 0) {
        orgnl += 17.34;
    }
    
    /*FINAL*/
    if (consNow < consPast){
    }
    
    /*SAIDA*/
    printf("Valor original = %.2f\n", orgnl);
    printf("Valor final = %f\n", final);
    
    return 0;
}
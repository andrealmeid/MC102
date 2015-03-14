#include <stdio.h>
#include <math.h>

int main(){
    
    int x1, x2, y1, y2, salto;
    
    scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &salto);
    
    int a = x2-x1,
        b = y2-y1;
    float c = a*a+b*b;
    printf("%f", c);
    c=4;
    float reta = sqrt(c);
    float pulos = c/salto;
    
    printf("O coelho precisa de %f saltos para chegar em %d, %d partindo de %d, %d.\n", pulos, x1, y1, x2, y2);
    
    return 0;
}
/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 03a - Admiravel Mundo Novo */

#include <stdio.h>
#include <math.h>
#define MX 100

int main(){
    
    int l, c, i, tot[MX];
    char get;
    
    for(i=0;i<MX;i++)
        tot[i]=0;
    
    
    scanf("%d %d", &l, &c);
    
    for(i=0;i<=l;i++){
        do{
        scanf("%c", &get);
	tot[(int)get-48]+=1;
        }while(get!=10);
    }
    
    for(i=1;i<=c;i++)
    printf("tot[%d]: %d\n", i, tot[i]);
    
    
    return 0;
}
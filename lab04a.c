/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 04a - Cargo-Bot - Part I*/

#include <stdio.h>
#include <math.h>
#define M 11

int main(){
        
    int x[M], y, i;
    char mov;
    
    for(i=0;i<M;i++)
        x[i]=0;

    scanf("%d %d", &x[0], &y);
    
    for(i=1;i<=x[0];i++)
        scanf("%d", &x[i]);
    
    do{
        scanf("%c", &mov);
        switch(mov){
            case 'D':
                printf("down\n");
                break;
            case 'R':
                printf("right\n");
                break;
            case 'L':
                printf("left\n");
                break;
        }
    }while(mov!='*');
    
    return 0;
}
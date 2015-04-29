/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 04a - Cargo-Bot - Part I*/

#include <stdio.h>
#include <math.h>
#define M 11

int main(){
    
    /*box = 0 sem caixa; box = 1 com  caixa*/
    /*y guarda a altura maxima; pos guarda a posicao*/
    int x[M], y, i, pos = 1, box = 0, acidente=0;
    char mov;
    
    for(i=0;i<M;i++)
        x[i]=0;
    
    /*a posicao 0 do vetor guarda o numero de posicoes de empilhamento*/
    scanf("%d %d", &x[0], &y);
    
    /*cada x[i>0] do vetor guarda seu respectivo numero de caixas*/
    for(i=1;i<=x[0];i++)
        scanf("%d", &x[i]);
    
    do{
        scanf("%c", &mov);
        switch(mov){
            /*verifica se existe caixa a ser pega*/
            case 'D':
                if(box==0){
                    if(x[pos]>0){
                        x[pos]-=1;
                        box=1;
                    }
                }else{
                    x[pos]+=1;
                    box=0;
                }
                break;
            /*verifica se existe a prox posicao e se nao ocorreu acidente*/
            case 'R':
                if(pos<x[0]){
                    if(x[pos+1]==y && box==1){
                        acidente=pos+1;
                    } else
                        pos+=1;
                }
                break;
            /*a mesma coisa do caso R, so que para esquerda*/
            case 'L':
                if(pos>1){
                    if(x[pos-1]==y && box==1){
                        acidente=pos+1;
                    } else
                        pos-=1;
                    break;
                }
        }
    }while(mov!='*');
    
    
    /*imprime o resultado*/
    if(acidente)
        printf("Um acidente ocorreu");
    else{
        for(i=1;i<x[0];i++)
            printf("%d ", x[i]);
        printf("%d", x[i]);
    }
    
    printf("\n");
    return 0;
}
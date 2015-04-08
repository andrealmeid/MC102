/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 04a - Cargo-Bot - Part I*/

#include <stdio.h>
#include <math.h>
#define M 11

int main(){
    
    /*box = 0 sem caixa; box = 1 com  caixa*/
    int x[M], y, i, pos = 1, box = 0, acidente=0;
    char mov;
    
    for(i=0;i<M;i++)
        x[i]=0;
    
    /*a posicao 0 do vetor guarda o numero de posicoes de empilhamento*/
    scanf("%d %d", &x[0], &y);
    
    /*cada i>0 do vetor guarda seu respectivo numero de caixas*/
    for(i=1;i<=x[0];i++)
        scanf("%d", &x[i]);
    
    do{
        scanf("%c", &mov);
        switch(mov){
            /*pegar/soltar caixa*/
            case 'D':
                if(box==0){
                    x[pos]-=1;
                    box=1;
                }else{
                    x[pos]+=1;
                    box=0;
                }
                break;
                
                /*andar para direita*/            
                case 'R':
                    if(box==1 && x[pos]==y){
                        if(pos<x[0])
                            pos+=1;
                    } else 
                        acidente=1;
                    break;
                    
                    /*andar para esquerda*/            
                    case 'L':
                        if(box==1 && x[pos]==y){
                            if(pos>1)
                                pos-=1;
                        } else 
                            acidente=1;
                        break;
        }
    }while(mov!='*');
    
    if(!acidente)
        printf("Um acidente ocorreu");
    else{
        for(i=1;i<=x[0];i++)
            printf("%d ", x[i]);
    }
    
    printf("\n");
    return 0;
}
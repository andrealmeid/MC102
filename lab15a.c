/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 15a - Walk-Bot - Part II */

#include <stdio.h>
#include <stdlib.h>

void atravessar(int n, int m, int **mapa, int **aux, int x, int y, int energia, int *passou){
    
    if(energia + x < m){        
        return;        
    }    
        
    aux[y][x]++;  
    if(aux[y][x]>n*m)
        return;
        
    int casa = mapa[y][x];    
//     printf("%d (%d,%d) %d\n", casa, x, y, energia);
    
    switch(casa){
        case 0:
            return;
            
        case 1:
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou);

        case 2:
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            break;
            
        case 3:
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou);
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            break;
            
        case 4:
            if(x+1>m-1){
                *passou = 1;             
                return;
            }
            atravessar(n, m, mapa, aux, x+1, y, energia-1, passou);
            break;
            
        case 5:
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou);
            atravessar(n, m, mapa, aux, x+1, y, energia-1, passou);
            break;
            
        case 6:
            if(x==m-1){
                *passou = 1;
                                printf("P\n");   
                return;
            }           
            atravessar(n, m, mapa, aux,x+1, y, energia-1, passou);
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            break;
            
        case 7:
            if(x==m-1){
                *passou = 1;
                                printf("P\n");   
                return;
            }        
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou);            
            atravessar(n, m, mapa, aux, x+1, y, energia-1, passou);
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            break;
            
        case 8:
            atravessar(n, m, mapa, aux, x, y-1, energia-1, passou);
            break;
            
        case 9:
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou);
            break;
            
        case 10:
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            atravessar(n, m, mapa, aux, x, y-1, energia-1, passou);
            break;            
            
        case 11:
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            atravessar(n, m, mapa, aux, x, y-1, energia-1, passou);
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou);
            break;
            
        case 12:
            if(x==m-1){
                *passou = 1;
                                printf("P\n");   
                return;
            }      
            atravessar(n, m, mapa, aux, x, y-1, energia-1, passou);      
            atravessar(n, m, mapa, aux, x+1, y, energia-1, passou);
            break;
            
        case 13:
            if(x==m-1){
                *passou = 1;
                                printf("P\n");   
                return;                
            }          
            atravessar(n, m, mapa, aux, x, y-1, energia-1, passou);
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou); 
            atravessar(n, m, mapa, aux, x+1, y, energia-1, passou);
            break;
            
        case 14:
            if(x==m-1){
                *passou = 1;
                                printf("P\n");   
                return;                
            }                        
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);           
            atravessar(n, m, mapa, aux, x+1, y, energia-1, passou);       
            atravessar(n, m, mapa, aux, x, y-1, energia-1, passou);
            break;
            
        case 15:
            if(x==m-1){
                *passou = 1;
                                printf("P\n");   
                return;                
            }                        
            atravessar(n, m, mapa, aux, x+1, y, energia-1, passou);
            atravessar(n, m, mapa, aux, x, y-1, energia-1, passou);
            atravessar(n, m, mapa, aux, x-1, y, energia-1, passou);
            atravessar(n, m, mapa, aux, x, y+1, energia-1, passou);
            break;            
    }   
}

int main(){
    
    int n, m, energia, i, j, passou;
    int **mapa, **aux;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &energia);
    
    mapa = malloc(n * sizeof(int *));
    aux = malloc(n * sizeof(int *));
    for(i=0;i<n;i++){
        mapa[i] = malloc(m * sizeof(int));
        aux[i] = malloc(m * sizeof(int));
    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d", &mapa[i][j]);    
            aux[i][j] = 0;
        }

        
        
   for(i=0;i<n;i++){
        passou=0;
        atravessar(n, m, mapa, aux, 0, i, energia, &passou);
        if(passou==0)
            printf("Nao\n");
        else
            printf("Sim\n");
   }

    return 0;
}
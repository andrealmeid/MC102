/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 09b - Peladeiros */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int nJogadores, nTimes, i, j, **time, mMedia, jTimes;
    
    float **jogadores, *media;
    
    scanf("%d %d", &nJogadores, &nTimes);
    
    media = malloc(nJogadores * sizeof(float));
    
    jTimes = nJogadores/nTimes;
    
    time = malloc(nTimes * sizeof(int));
    for(i=0;i<jTimes;i++)
        time[i] = malloc(jTimes * sizeof(int*));
        
    for(i=0;i<nJogadores;i++)
        media[i]=0;
    
    jogadores = malloc(nJogadores * sizeof(float*));
    for(i=0;i<nJogadores;i++)
        jogadores[i] = malloc(nJogadores * sizeof(float));
    
    for(i=0;i<nJogadores;i++){
        for(j=0;j<nJogadores;j++){
            scanf("%f", &jogadores[i][j]);
            media[j]+=jogadores[i][j];
        }
    }
    
    for(i=0;i<nJogadores;i++)
        media[i]/=nJogadores;
    
    for(i=0;i<nTimes;i++){
        mMedia=0;
        for(j=1;j<nJogadores;j++){
            if(media[j]>media[mMedia]){
            mMedia=j;
            }
        }
        time[i]=mMedia;
        media[mMedia]=-1;
    }
    
    for(i=0;i<nTimes;i++)
        printf("%d\n", capitao[i]+1);
    
    return 0;
}
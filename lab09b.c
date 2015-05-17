/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 09b - Peladeiros */

#include <stdio.h>
#include <stdlib.h>

void negativar(float **jogadores, int nJogadores, int a){
    int i;
    
    for(i=0;i<nJogadores;i++){
        jogadores[i][a]=-1;
    }
}

int main(){
    
    int nJogadores, nTimes, i, j, k, **time, maior, jTimes, capitao;
    
    float **jogadores, *media;
    
    scanf("%d %d", &nJogadores, &nTimes);
    
    media = malloc(nJogadores * sizeof(float));
    
    /* calculo de jogadores por time */
    jTimes = nJogadores/nTimes;
    
    time = malloc(nTimes * sizeof(int*));
    for(i=0;i<nTimes;i++)
        time[i] = malloc(jTimes * sizeof(int));
    
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
    
    /* calculo das medias de notas */
    for(i=0;i<nJogadores;i++)
        media[i]/=nJogadores;
    
    /* atribuicao dos capitaes de cada time com base nas medias*/
    for(i=0;i<nTimes;i++){
        maior=0;
        for(j=1;j<nJogadores;j++){
            if(media[j]>media[maior]){
                maior=j;
            }
        }
        time[i][0]=maior;
        media[maior]=-1;
        negativar(jogadores, nJogadores, maior);
    }
    
    for(i=0;i<nJogadores;i++){
        for(j=0;j<nJogadores;j++){
            printf("%.1f ", jogadores[i][j]);
        }
        printf("\n");
    }
    
    for(i=1;i<jTimes;i++){
        for(j=0;j<nTimes;j++){
            maior=0;
            capitao=time[j][0];
            for(k=1;k<nJogadores;k++){
                if(jogadores[capitao][k]>jogadores[capitao][maior])
                    maior=k;
            }
            time[j][i]=maior;
            negativar(jogadores, nJogadores, maior);
            
            for(i=0;i<nTimes;i++){
                for(j=0;j<nJogadores;j++){
                            capitao=time[i][0];
                printf("%.1f ", jogadores[capitao][j]);
            }
            printf("\n");
            }
        }
        printf("\n");
    }
    
    
    
    /* impressao dos valores */
    for(i=0;i<nTimes;i++){
        printf("Time %d:", i+1);
        for(j=0;j<jTimes;j++){
            printf(" %d", time[i][j]+1);
        }
        printf("\n");
    }
    
    return 0;
}
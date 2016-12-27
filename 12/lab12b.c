/* Laboratorio 12b - Bola de Ouro
   Autor: Andre Figueiredo de Almeida 164047
   Email: fda.andre@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tamanho maximo do nome do jogador */
#define MAXNOME 26
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de jogadores */
#define MAXJOGADORES 40
/* Numero maximo de dados */
#define MAXDADOS 6

/* Jogador:
 * nome = nome do jogador
 * C1 = numero de gols
 * C2 = numero de assistencias
 * C3 = numero de dribles feitos
 * C4 = numero de gols contra
 * C5 = numero de cartoes vermelhos
 * C6 = numero de cartoes amarelos
 */
struct Jogador {
    char nome[MAXNOME];
    int C1;
    int C2;
    int C3;
    int C4;
    int C5;
    int C6;
};

typedef struct Jogador Jogador;
  
/* faz a troca da ordenacao */
void troca(int pontuacao[], Jogador scout[], int i, int l){
    char nome[MAXNOME];
    int aux;
    
    aux = pontuacao[i];
    pontuacao[i] = pontuacao[l];
    pontuacao[l] = aux;
    strcpy(nome, scout[i].nome); 
    strcpy(scout[i].nome, scout[l].nome);
    strcpy(scout[l].nome, nome); 
}
    
    
/* atualiza as estatisticas dos jogadores com os dados da entrada */    
void atualizaScout(Jogador scout[], char nome[MAXNOME], int dados[MAXDADOS]){
    int i=0;
    
    /* encontra o registro do jogador pelo nome */
    while(strcmp(nome, scout[i].nome))    
        i++;
    
    scout[i].C1+=dados[0];
    scout[i].C2+=dados[1];
    scout[i].C3+=dados[2];
    scout[i].C4+=dados[3];
    scout[i].C5+=dados[4];
    scout[i].C6+=dados[5];    
    
}


int main(int argc, char **argv) {
    /* Nome do arquivo binario com as estatisticas */
    char nomeArqEstat[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];
    /* nome do jogador */
    char nome[26];
    /* peso das estatisticas, dados estatisticos do jogador, numero de rodadas
     * e numero de jogadores no total */
    int peso[MAXDADOS], dados[MAXDADOS], nRodadas, nJogadoresTotal;
    /* numero de jogadores da rodada; pontuacao final dos jogadores */
    int nJogadores, pontuacao[MAXJOGADORES], i, j, l;
    /* arquivo de entrada e arquivo de saida */
    FILE *arqin, *arqout;

    Jogador scout[MAXJOGADORES];
    
    /* Lendo os nomes dos arquivos binarios */
    strcpy(nomeArqEstat, argv[1]);
    strcpy(nomeArqSaida, argv[2]);   

    /* abrindo os arquivos */        
    arqin = fopen(nomeArqEstat, "rb");
    arqout = fopen(nomeArqSaida, "wb");
    
    /* escreve no struct scout os dados escritos no arquivo de entrada */
    fread(&nJogadoresTotal, sizeof(int), 1, arqin);
    for(i=0; i<nJogadoresTotal; i++)
        fread(&scout[i], sizeof(Jogador), 1, arqin);        
    
    /* recebe os pesos e o numero de rodadas */
    for(i=0;i<MAXDADOS;i++)
        scanf("%d", &peso[i]);    
    scanf("%d", &nRodadas);
    
    /* para cada rodada, eh recebido o nome do jogador e suas estatisticas. 
     * depois, esses dados sao enviados para atualizaScout() */     
    for(i=0;i<nRodadas;i++){
        scanf("%d", &nJogadores);
        
        for(j=0;j<nJogadores;j++){
            scanf("%s", nome);
            for(l=0;l<MAXDADOS;l++)                
                scanf("%d", &dados[l]);            
            
            atualizaScout(scout, nome, dados);
        }        
    }    
    
    /* escreve o arquivo com os dados finais do scout */
    fwrite(&nJogadoresTotal, sizeof(int), 1, arqout);
    for(i=0; i<nJogadoresTotal; i++)
        fwrite(&scout[i], sizeof(Jogador), 1, arqout);   
    
    /* compilacao da pontuacao dos jogadores */
    for(i=0;i<nJogadoresTotal;i++){
        j=0;
        pontuacao[i]=
    scout[i].C1*peso[0]+scout[i].C2*peso[1]+scout[i].C3*peso[2]-
    scout[i].C4*peso[3]-scout[i].C5*peso[4]-scout[i].C6*peso[5];
    }
            
    /* ordenacao dos jogadores com selection sort + tratamento de empate */       
      for (i=0;i<nJogadoresTotal-1;i++) {
            l = i;
            for (j=i+1;j<nJogadoresTotal;j++)
                if (pontuacao[j] > pontuacao[l]){                    
                    l = j;
                /* se dois jogadores empatam, ordena lexicograficamente */                    
                } else if(pontuacao[j]==pontuacao[l] &&
                          strcmp(scout[j].nome, scout[l].nome)<0){                     
                    troca(pontuacao, scout, i, l);
                }
                if (l != i) {
                    troca(pontuacao, scout, i, l);
            }
      }
    /* impressao dos tres primeiros jogadores */
    for(i=0;i<3;i++){
        printf("%s\n", scout[i].nome);
    }
        
    /* fechando arquivos */
    fclose(arqin);
    fclose(arqout);
 
    return 0;
}
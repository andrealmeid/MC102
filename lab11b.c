/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 11b - Brasil, o Pais do Volei */

#include <stdio.h>
#include <string.h>

#define MAX 6
#define TRUE 1
#define FALSE 0

struct time {
   char nome[21];
   int indice, pontos, vitorias;
   int pontosGanhos, pontosPerdidos, setsGanhos, setsPerdidos; 
};
typedef struct time time_t;

void inicializaStruct(time_t time[]){
	int i;	
	
	for(i=0;i<MAX;i++){
		time[i].nome[0]=' ';
		time[i].pontos=0;
		time[i].vitorias=0;
	}
	
}

int leString(time_t time[]){
	char aux[21];
	int i;
	
	scanf("%s", aux);

	for(i=0;i<MAX;i++){
			if(strcmp(time[i].nome,aux)==0){
				return i;
			}
		}
			
	for(i=0;i<MAX;i++){
		if(strncmp(" ", time[i].nome,1)==0){
			strcpy(time[i].nome, aux);
			time[i].indice = i;
			return i;		
		}	
	}	
}

/* Atualiza os atributos relativos aos sets e aos pontos */
void atualizaSetsPontos(time_t *time, int setsGanhos, int setsPerdidos, 
                        int pontosGanhos, int pontosPerdidos) {
   time->setsGanhos += setsGanhos;
   time->setsPerdidos += setsPerdidos;
   time->pontosGanhos += pontosGanhos;
   time->pontosPerdidos += pontosPerdidos;
}

/* Atualiza os atributos relativos as partidas */
void atualizaPartida(time_t *timeGanhador, time_t *timePerdedor, 
                     int diferencaSets, int confrontoDireto[][6]) {
   timeGanhador->vitorias++;

   if (diferencaSets > 1)
      timeGanhador->pontos += 3;
   else {
      timeGanhador->pontos += 2;
      timePerdedor->pontos += 1;
   }

   confrontoDireto[timeGanhador->indice][timePerdedor->indice] = 1;
   confrontoDireto[timePerdedor->indice][timeGanhador->indice] = -1;
}

/* Le os resultados das partidas entre todos os times de uma chave */
void leResultadosChave(time_t timesChave[], int confrontoDireto[][6]) {
	int  n=0, find=FALSE, indiceA, indiceB;
	
	inicializaStruct(timesChave);
	
	while(n<15){
		
		indiceA = leString(timesChave);
		indiceB = leString(timesChave);

		indiceA++;
		indiceB++;
		
		n++;
	}
}

/* Ordena o vetor de times */
void ordenaTimes(time_t times[], int n, int confrontoDireto[][6]) {

}

int main() {
   /* variaveis de entrada */
   time_t timesChaveA[6], timesChaveB[6];
   /* variaveis auxiliares */
   int i, confrontosChaveA[6][6], confrontosChaveB[6][6];

   /* le entrada */
   leResultadosChave(timesChaveA, confrontosChaveA);
   leResultadosChave(timesChaveB, confrontosChaveB);
  
   /* ordena os vetores de times na ordem de classificacao */
   ordenaTimes(timesChaveA, 6, confrontosChaveA);
   ordenaTimes(timesChaveB, 6, confrontosChaveB);

   /* imprime a saida */
   for (i = 0; i < 4; i++) {
      printf("%s x %s\n", timesChaveA[i].nome, timesChaveB[3-i].nome);
   }

   return 0;
}
/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 10a - Tag Cloud */

#include <stdio.h>
#include <string.h>

struct palavra{
	char *nome;
	int cont;
};

int main(){
	/* d = palavras distintas; f = numero minimo de ocorrencias de uma palavra
	 * l = tamanho minimo de uma palavra; m = tamanho maxio de uma palavra */
	int  d, f, l, m;
	char palavra[10];
	
	scanf("%d %d %d %d", &d, &f, &l, &m);
	
	
	do{
	scanf("%s", palavra);
	}while(strncmp(palavra,"*",1));
	
	
	return 0;
	
}
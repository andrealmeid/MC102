/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 12a - Tweet Extractor */

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME 25
#define MAX_ENTITY 10
#define MAX_TAG 48
#define TAG_INICIO "p class=\"ProfileTweet-text js-tweet-text u-dir\""
#define TAG_FIM "/p"
#define TRUE 1
#define FALSE 0

/* Funcao que converte uma entidade no caractere correspondente,
   supondo que o caractere '&' foi previamente lido no arquivo de
   entrada (arqin). Se a entidade eh diferente de aspas simples ou
   aspas dupla, a funcao simplesmente o ignora, caso contrario ela
   imprime o caractere correspondente no arquivo de saida (arqout). */
void converte_entidade(FILE *arqin, FILE *arqout) {
    char c, entidade[MAX_ENTITY];
    int i = 0;
    
    /* armazena o codigo da entidade ate encontrar o caractere ';' */
    c = fgetc(arqin);
    while (c != ';') {
        entidade[i++] = c;
        c = fgetc(arqin);
    }
    entidade[i] = '\0';
    
    /* se a entidade corresponde ao caractere aspas simples ou aspas duplas,
       imprime o caractere no arquivo de saida */
    if (!strcmp(entidade, "#39"))
        fprintf(arqout, "\'");
    else if(!strcmp(entidade, "quot"))
        fprintf(arqout, "\"");
}

/* Le os atributos da tag ate o final para nao aparecerem na escrita */
void limpaTag(FILE *arqin){
    char c = fgetc(arqin);
    
    while(c!='>')
        c = fgetc(arqin);
}

/* Escreve no arquivo os tweets */
void escreveTweet(FILE *arqin, FILE *arqout){
    char c = fgetc(arqin);
    
    while(c!='<'){
        if(c=='&')
            converte_entidade(arqin, arqout);
        else 
            fprintf(arqout, "%c", c);
            c = fgetc(arqin);
    }
}        

/* Analisa as tags do codigo HTML para verificar se eh um tweet */
void analisaTag(FILE *arqin, FILE *arqout, int *escrever){
    /* tag_atual tem tamanho 48 porque esse eh o tamanho do texto da tag
     * que identifica o inicio de um tweet. o resto da tag (independente do
     * tipo) nao eh armazenado ja que nao eh relevante */
    char c, tag_atual[MAX_TAG];
    int i=0;
           
    /* recebe o texto da tag */
    c = fgetc(arqin);
    while(c!='>' && i<MAX_TAG-1){
       tag_atual[i++] = c;
       c = fgetc(arqin);
    }    
    tag_atual[i]='\0';   
    
    /* se a tag tem os atributos de um tweet */
    if(!strcmp(tag_atual, TAG_INICIO)){        
        limpaTag(arqin);       
        *escrever = TRUE;
        escreveTweet(arqin, arqout);
        return;
    }         
    
    /* se a tag tem o formato de final de tweet */
    if(!strcmp(tag_atual, TAG_FIM) && *escrever==TRUE){
        fprintf(arqout, "\n");
        *escrever = FALSE;
        return;
    }
    
    /* se a tag nao se encaixa nas duas pode ser ignorada */
    if(*escrever == TRUE){
        if(c!='>')
            limpaTag(arqin);
        escreveTweet(arqin, arqout);
    }
    
}

void extrai_tweets(char nomearqin[], char nomearqout[]) {
    FILE *arqin = fopen(nomearqin, "r");
    FILE *arqout = fopen(nomearqout, "w");
    
    /* c = char auxiliar; escrever = se eh para escrever no arquivo de saida */
    char c = fgetc(arqin);  
    int escrever = FALSE;
    
    /* leitura do arquivo de entrada */
    while(c != EOF){        
        /* se encontrar alguma tag, chama o analisaTag() */
        if(c=='<'){
                /* como o metodo escreveTweet sempre acaba em um '<', o 
                 * metodo analisaTag eh chamado repetidas vezes se esta
                 * ocorrendo uma escrita */                 
                analisaTag(arqin, arqout, &escrever);
                while(escrever == TRUE)
                    analisaTag(arqin, arqout, &escrever);
        }        
        c = fgetc(arqin);
    }
    
    fclose(arqin);
    fclose(arqout);
}

int main(int argc, char *argv[]) {  
    char nomearqin[MAX_FILENAME], nomearqout[MAX_FILENAME];
    
    /* Copia os nomes do arquivo de entrada e de saida nas variaveis */
    strcpy(nomearqin, argv[1]);
    strcpy(nomearqout, argv[2]);
 
    extrai_tweets(nomearqin, nomearqout);

    return 0;
}
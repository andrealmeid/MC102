/* FILE */

#include <stdio.h>
#include <string.h>

#define tagInicio 1
#define tagFim 2
#define tagContinua 3


void verificaTag(FILE *arquivo, FILE *arqout);

void escrever(FILE *arqin, FILE *arqout);

int verificaTagInterna(FILE *arqin);

int main(){
    char aux;
    FILE *file = fopen("texto.txt", "r");
    FILE *fileout = fopen("out.txt", "w");
        
    aux = fgetc(file);
    while(aux != EOF){
        
        if(aux=='<'){
            printf("tag encontrada\n");
            verificaTag(file, fileout);
            printf("continuando leitura\n");            
        }            
        aux = fgetc(file);
        
    }          
    
    printf("arquivo chegou ao fim\n");
    fclose(file);
    fclose(fileout);
    
    return 0;
}

void escrever(FILE *arqin, FILE *arqout){
    char c;
    int tag;
    
    c = fgetc(arqin);
    printf("iniciando escrita\n");   
    
    while(c!='<'){     
        fprintf(arqout, "%c", c);
        c = fgetc(arqin);
    }
        
    tag = verificaTagInterna(arqin);
    if(tag==tagFim){
        fprintf(arqout, "\n");
        return;
    }
    else
        escrever(arqin, arqout);
    
    printf("escrita finalizada\n");
}

int verificaTagInterna(FILE *arquivo){
    char aux, tag_atual[3], tag_fim[] = "/p";
    int i=0;
    
    printf("Verificando tag interna...");
    aux = fgetc(arquivo);
    while(aux!='>' && i<3){
       tag_atual[i++] = aux;
       aux = fgetc(arquivo);
    }
    
    tag_atual[i]='\0';              

    if(!strcmp(tag_atual, tag_fim)){
        printf(" tag é do tipo final\n");
        return tagFim;
    }
    
        while(aux!='>')
        aux = fgetc(arquivo);      
    printf(" tag deve ser ignorada\n");
    return tagContinua;
}


void verificaTag(FILE *arquivo, FILE *arqout){
    char aux, tag_atual[48], tag_fim[] = "/p",
    tag_inicio[] = "p class=\"ProfileTweet-text js-tweet-text u-dir\"";
    int i=0;
    
    printf("Verificando tag...");
    aux = fgetc(arquivo);
    while(aux!='>' && i<47){
       tag_atual[i++] = aux;
       aux = fgetc(arquivo);
    }
    
    tag_atual[i]='\0';              

    if(!strcmp(tag_atual, tag_fim)){
        printf(" tag é do tipo final\n");
        return;
    }
    
    if(!strcmp(tag_atual, tag_inicio)){

        aux = fgetc(arquivo);
        while(aux!='>')
            aux = fgetc(arquivo);        
        
        printf(" tag é do tipo inicio\n");
        escrever(arquivo, arqout);
        return;
    }
    
    while(aux!='>')
        aux = fgetc(arquivo);      
    printf(" tag deve ser ignorada\n");
    return;
    
}

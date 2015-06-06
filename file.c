/* FILE */

#include <stdio.h>
#include <string.h>

#define tagInicio 1
#define tagFim 2
#define tagContinua 3


int verificaTag(FILE *arquivo){
    char aux, tag_atual[48], tag_fim[] = "/p",
    tag_inicio[] = "p class=\"ProfileTweet-text js-tweet-text u-dir\"";
    int i=0;
    
    aux = fgetc(arquivo);
    while(aux!='>' && i<47){
       tag_atual[i++] = aux;
       aux = fgetc(arquivo);
    }
    
    tag_atual[i]='\0';              

    if(!strcmp(tag_atual, tag_fim)){
        printf("tag fim aux -> %c\n", aux);
        return tagFim;
    }
    
    if(!strcmp(tag_atual, tag_inicio)){
        printf("tag inicio aux -> %c\n", aux);
        return tagInicio;
    }
    
    
    printf("tag continua\n");
    return tagContinua;
    
}

int main(){
    char aux;
    FILE *file = fopen("texto.txt", "r");
    FILE *fileout = fopen("out.txt", "w");
    
    int tag;
    
    aux = fgetc(file);
    while(aux != EOF){
        if(aux=='<'){
            tag = verificaTag(file);
                        
            if(tag==tagInicio){
                while(aux!='<'){
                    aux = fgetc(file);
                    fprintf(fileout, "%c", aux);
                    fprintf(fileout, "NAO DEIXA O SAMBA MORRER");
                }
            }
        }        
        
        aux = fgetc(file);
    }          
    
    fclose(file);
    fclose(fileout);
    
    return 0;
}
/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 14a - Cargo-Bot - Part III*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void executaProg(int num, char progs[][9], char *hold, char boxes[][10], 
                 int *garra, int x, int y, int *cont, int e){
    int i=0, j, acidente=FALSE, auxn;
    char aux = progs[num][i];
    
    /* para o loop quando encotnar o fim do programa (*) */   
    while(aux!='*'){
        printf("comando:%c hold:%c i:%d\n", aux, *hold, i); 
        j=0;
        switch(aux){
            /* pegar/soltar caixa */
            case 'D':
            if(*hold=='.'){
                while(boxes[j][*garra]=='.' && j<y-1)
                    j++;
                *hold=boxes[j][*garra];
                boxes[j][*garra]='.';
            } else {
                for(j=0;j<y;j++)
                    if(boxes[j+1][*garra]!='.')
                        break;
                    boxes[j][*garra]=*hold;
                *hold='.';
            }
            break;
            
            /* move para direita se for possivel */   
            case 'R':
            if(*garra<x-1)
                *garra = *garra + 1;
            if(boxes[0][*garra]!='.' && *hold!='.')
                acidente=TRUE;
            break;
            
            /* move para esquerda se for possivel */   
            case 'L':
            if(*garra>0)
                *garra = *garra - 1;
            if(boxes[0][*garra]!='.' && *hold!='.')
                acidente=TRUE;
            break;
            
            /* nesse bloco, se as condicoes nao forem verdadeiras,
            * o programa pula a proxima instrucao. se forem, ele as executa */
            case 'B':
            if(*hold!='B')
                i++;
            break;
            
            case 'G':
            if(*hold!='G')
                i++;
            break;
            
            case 'Y':
            if(*hold!='Y')
                i++;
            break;
            
            case 'N':
            if(*hold!='.')
                i++;
            break;
            
            case 'A':
            if(*hold=='.')
                i++;
            break;

            default:
            if(*cont<e){
                /* transforma o char em int */
                auxn = aux - '1';
                *cont = *cont + 1;
                printf("add pilha prog %d\n", num+1);
                executaProg(auxn, progs, hold, boxes, garra, x, y, cont, e);
                printf("rvm pilha prog %d\n", num+1);
            }
            break;                      
        }              
        i++;
        aux = progs[num][i];
    }    
    
    if(acidente==TRUE)
        printf("acidente\n");
}

int main(){   
    /*VARIAVEIS*/
    /* x=posicoes para empilhamento de caixas; y=numero max de empilhamento */
    int x, y;
    
    /* p = num de programas; c = num max de comandos de programas*/
    int p, c;
    
    /* e = num de execucoes de programas; i, j, k = contadores 
        * num serve de variavel auxiliar para uma conversao */
    int e, i, cont=0;
    
    /* boxes = posicionamento das caixas */
    char boxes[10][10];
    
    /* progs = armazena cada programa em uma linha, duas pos extras foram
        * adicionada para guardar o asterisco e o \0 */
    char progs[60][9];
    
    /* garra = posicao da garra; acidente indica se ocorreu algum acidente */
    int garra=0, acidente = FALSE;
    
    /* hold = guarda o que a garra segura
     * '.' = nada, B = caixa azul, G = caixa verde, Y = caixa amarela */
    char hold='.';
    
    /*ENTRADAS*/
    /* entrada da primeira linha */
    scanf("%d %d %d %d %d", &x, &y, &p, &c, &e);
    
    /* alocacoes dinamicas das matrizes *
    boxes = malloc(y * sizeof(char *));
    for(i=0;i<y;i++)
        boxes[i] = malloc(x * sizeof(char));*
    
    progs = malloc(p * sizeof(char *));
    for(i=0;i<p;i++)
        progs[i] = malloc(c+1 * sizeof(char));*/
            
    /* entrada das posicoes iniciais das caixas */
    for(i=0;i<y;i++)
        scanf("%s", boxes[i]);    
    
    /* entrada dos comandos dos programas */
    for(i=0;i<p;i++)
        scanf("%s", progs[i]);
    
    /*PROCESSAMENTOS*/

        executaProg(0, progs, &hold, boxes, &garra, x, y, &cont, e);
    
    
    /* imprime as posicoes das caixas se nenhum acidente ocorreu */
    if(acidente==FALSE)
        for(i=0;i<y;i++){
            printf("%s", boxes[i]);
            printf("\n");    
        }
    else 
        printf("Um acidente ocorreu\n");
    
    /*
    for(i=0;i<y;i++)
        free(boxes[i]);
    free(boxes);
    
    for(i=0;i<p;i++)
        free(progs[i]);
    free(progs);
    */
    
    return 0;
}
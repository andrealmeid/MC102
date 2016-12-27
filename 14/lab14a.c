/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 14a - Cargo-Bot - Part III*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* essa funcao executa o programa da matriz progs na linha de numero 'num' */
int executaProg(int num, char **progs, char **boxes, char *hold, int *garra, 
                int x, int y, int *cont, int e){
                    
    /* prox = proximo programa a ser chamado */
    int i=0, j, prox, acidente;
    /* cmd = comando atual */
    char cmd = progs[num][i];
    
    /* para o loop quando encotnar o fim do programa (*) */   
    while(cmd!='*'){
        switch(cmd){            
            /* pegar/soltar caixa */
            case 'D':
                if(*hold=='.'){
                    for(j=0; j<y-1 && boxes[j][*garra]=='.'; j++);
                    /* pega a caixa e deixa o local vazio */
                    *hold = boxes[j][*garra];
                    boxes[j][*garra]='.';
                } else {                
                    for(j=0; j<y-1 && boxes[j+1][*garra]=='.'; j++);
                    /* solta a caixa e deixa a garra vazia */
                    boxes[j][*garra] = *hold;
                    *hold='.';
                }
                break;
            
            /* move para direita se for possivel */   
            case 'R':
                if(*garra<x-1)
                    *garra = *garra + 1;
                if(boxes[0][*garra]!='.' && *hold!='.'){
                    /* se ocorrer um acidente, retorna TRUE */
                    return TRUE;
                }
                break;
            
            /* move para esquerda se for possivel */   
            case 'L':
                if(*garra>0)
                    *garra = *garra - 1;
                if(boxes[0][*garra]!='.' && *hold!='.'){
                    /* se ocorrer um acidente, retorna TRUE */
                    return TRUE;
                }
                break;
            
            /* nesse bloco, se as condicoes nao forem verdadeiras,
            * o programa pula a proxima instrucao */
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

            /* se o cmd nao se encaixar em nenhuma letra, entao se trata de um
             * numero e aqui sera chamado o programa desse numero */
            default:
                /* se o numero maximo de execucoes nao foi ultrapassado */
                if(*cont<e){
                    /* transforma o char em int */
                    prox = cmd - '1';
                    *cont = *cont + 1;
                    acidente = executaProg(prox, progs,  boxes, hold, garra, 
                                           x, y, cont, e);
                    /* se ocorreu um acidente, as execucoes se encerram */
                    if(acidente)
                        return acidente;
                }
                break;                      
        }              
        cmd = progs[num][++i];
    }    
    
    return FALSE;
}

int main(){   
    /* x=posicoes para empilhamento de caixas; y=numero max de empilhamento */
    int x, y;
    
    /* p = num de programas; c = num max de comandos de um programa*/
    int p, c;
    
    /* e = num max de execucoes de programas; cont = contagem de execucoes */
    int e, cont=1, i;
    
    /* boxes = posicionamento das caixas */
    char **boxes;
    
    /* progs = armazena cada programa em uma linha, duas pos extras foram
     * adicionada a alocacao para guardar o asterisco e o \0 */
    char **progs;
    
    /* garra = posicao da garra; acidente indica se ocorreu algum acidente */
    int garra=0, acidente;
    
    /* hold = guarda o que a garra segura
     * '.' = nada, 'B' = caixa azul, 'G' = caixa verde, 'Y' = caixa amarela */
    char hold='.';
    
    
    /* entrada da primeira linha */
    scanf("%d %d %d %d %d", &x, &y, &p, &c, &e);
    
    /* alocacoes dinamicas das matrizes */
    boxes = malloc(y * sizeof(char *));
    for(i=0;i<y;i++)
        boxes[i] = malloc(x+1 * sizeof(char));
    
    progs = malloc(p * sizeof(char *));
    for(i=0;i<p;i++)
        progs[i] = malloc(c+2 * sizeof(char));
            
    /* entrada das posicoes iniciais das caixas */
    for(i=0;i<y;i++)
        scanf("%s", boxes[i]);    
    
    /* entrada dos comandos dos programas */
    for(i=0;i<p;i++)
        scanf("%s", progs[i]);        
    
    
    /* executa o primeiro programa */
    acidente = executaProg(0, progs,  boxes, &hold, &garra, x, y, &cont, e);   
    
    /* imprime as posicoes das caixas se nenhum acidente ocorreu */
    if(acidente==FALSE){
        for(i=0;i<y;i++){
            printf("%s", boxes[i]);
            printf("\n");    
        }
    } else
        printf("Um acidente ocorreu\n");
        
    
    /* desalocacao das matrizes */
    for(i=0;i<y;i++)
        free(boxes[i]);
    free(boxes);
    
    for(i=0;i<p;i++)
        free(progs[i]);
    free(progs);    
    
    return 0;
}
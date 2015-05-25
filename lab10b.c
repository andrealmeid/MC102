/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 10b - O Baile de Inverno */

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    /* m = numero de alunos; n = numero de alunas; aux = auxiliar da ordenacao
     * e da subtracao */
    int m, n, d, i, j, aux;
    
    /* vetores que guardam os alunos/alunas e contador das duplas */
    int *alunos, *alunas, duplas=0;
    
    scanf("%d %d %d", &m, &n, &d);

    alunos = malloc(m * sizeof(int));
    alunas = malloc(n * sizeof(int));
    
    /* recebe as notas dos alunos */
    for(i=0;i<m;i++)
        scanf("%d", &alunos[i]);
    
    /* recebe as notas das alunas */
    for(i=0;i<n;i++)
        scanf("%d", &alunas[i]);
    
    /* ordenacao dos alunos */
    for(i=1;i<m;i++){
        j=i;
        while (j>0 && alunos[j-1]<alunos[j]) {
            aux = alunos[j];
            alunos[j] = alunos[j-1];
            alunos[j-1] = aux; 
            j--;
        }
    }
    
    /* ordenacao das alunas */
    for(i=1;i<n;i++){
        j=i;
        while (j>0 && alunas[j-1]<alunas[j]) {
            aux = alunas[j];
            alunas[j] = alunas[j-1];
            alunas[j-1] = aux; 
            j--;
        }
    }
    
    /* o programa vai subtraindo os valores ate encontrar uma subtracao que
     * esteja no intervalo [-d;d]. quando esse valor é encontrado, ambos alunos
     * recebem o valor de 200 para que seja impossivel que a diferença seja 
     * verdadeira para outra duplas, de forma que eles nao sejam mais 
     * escolhidos e o loop é quebrado*/
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            aux = alunos[i] - alunas[j];
            if(aux<=d && aux>=-d){
                duplas++;
                alunos[i]=200;
                alunas[j]=200;
                j=n;
            }
        }
    }
    
    printf("Numero maximo de duplas equilibradas = %d\n", duplas);
    
    free(alunos);
    free(alunas);
    
    return 0;
}
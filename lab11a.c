/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 11a - Transferências Bancárias */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* registro dos dados bancarios dos clientes */
struct Dados_Bancarios{
    char nome[21];
    char sobrenome[21];
    int conta;
    int agencia;
    float saldo;
};

typedef struct Dados_Bancarios dados;

/* verificar se a conta existe */
int verificarDados(int conta, int agencia, dados *dados, int n){
    int i;
    
    for(i=0;i<n;i++){
        if(dados[i].conta == conta && dados[i].agencia == agencia)
            return i;
    }
        
    return -1;
}

int main(){
    /* nClientes = numero de clientes; nTrans = numero de transacoes */
    int nClientes, nTrans, i;
    /* variaveis auxliares para realizar as tranferencias; F = from, T = to */
    int  conta, agencia;
    /* indice = indice da conta; se ela não existe, guarda -1 */
    int indiceF, indiceT;
    
    float valor;
    
    dados *banco;
    
    scanf("%d %d", &nClientes, &nTrans);
    
    banco = malloc(nClientes * sizeof(dados));

    /* entrada dos dados dos clientes */
    for(i=0;i<nClientes;i++){
        scanf("%d %d", &banco[i].conta, &banco[i].agencia);
        scanf("%s %s", banco[i].nome, banco[i].sobrenome);
        scanf("%f", &banco[i].saldo);
    }
    
    /* entrada e realizacao das tranferencias */
    for(i=0;i<nTrans;i++){
        
        scanf("%d %d", &conta, &agencia);
        indiceF = verificarDados(conta, agencia, banco, nClientes);
        if(indiceF == -1)
            continue;
        
        scanf("%f", &valor);    
        if(valor<banco[indiceF].saldo)
            continue;
        
        scanf("%d %d", &conta, &agencia);
        indiceT = verificarDados(conta, agencia, banco, nClientes);
        if(indiceT == -1)
            continue;

        banco[indiceF].saldo-=valor;
        banco[indiceT].saldo+=valor;
        
    }
    
    /* impressao dos valores finais da contas */
    for(i=0;i<nClientes;i++){
        printf("%d@%d %s %s %.2f", banco[i].conta, banco[i].agencia,
               banco[i].nome, banco[i].sobrenome, banco[i].saldo);
    }
        
    
    return 0;
}
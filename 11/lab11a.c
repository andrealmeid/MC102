/* Nome: Andre Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 11a - Transferencias Bancarias */

#include <stdio.h>
#include <stdlib.h>

#define FALSE -1

/* registro dos dados bancarios dos clientes */
struct Dados_Bancarios{
    char nome[21];
    char sobrenome[21];
    int conta;
    int agencia;
    double saldo;
};

typedef struct Dados_Bancarios dados;

/* verificar se a conta existe. caso positivo, retorna o endereco; caso 
 * contrario, retorna FALSE (-1) */
int verificarDados(int conta, int agencia, dados *dados, int n){
    int i;
    
    for(i=0;i<n;i++){
        if(dados[i].conta == conta && dados[i].agencia == agencia)
            return i;
    }
    
    return FALSE;
}

int main(){
    /* nClientes = numero de clientes; nTrans = numero de transacoes */
    int nClientes, nTrans, i;
    /* variaveis auxliares para realizar as tranferencias */
    int  conta, agencia;
    /* indice = endereco da conta */
    int indiceDe, indicePara;
    /* valor da transacao */
    double valor;
    
    dados *banco;
    
    scanf("%d %d", &nClientes, &nTrans);
    
    banco = malloc(nClientes * sizeof(dados));

    /* entrada dos dados dos clientes */
    for(i=0;i<nClientes;i++){
        scanf("%d@%d", &banco[i].conta, &banco[i].agencia);
        scanf("%s %s", banco[i].nome, banco[i].sobrenome);
        scanf("%lf", &banco[i].saldo);
    }
    
    /* entrada e realizacao das tranferencias */
    for(i=0;i<nTrans;i++){   
                
        
        scanf("%d@%d >> ", &conta, &agencia);
        indiceDe = verificarDados(conta, agencia, banco, nClientes);
        
        /* se a conta nao tiver saldo suficiente, torna o indice invalido */
        scanf("%lf", &valor);    
        if(valor>banco[indiceDe].saldo)
            indiceDe=FALSE;
                
        scanf(" >> %d@%d", &conta, &agencia);
        indicePara = verificarDados(conta, agencia, banco, nClientes);       
        
        /* se os dois enderecos forem validos, realiza a tranferencia */
        if(indiceDe != FALSE && indicePara != FALSE){
            banco[indiceDe].saldo-=valor;
            banco[indicePara].saldo+=valor;
        }
        
    }
    
    /* impressao dos valores finais da contas */
    for(i=0;i<nClientes;i++){
        printf("%d@%d %s %s %.2lf\n", banco[i].conta, banco[i].agencia,
               banco[i].nome, banco[i].sobrenome, banco[i].saldo);
    }      
        
    free(banco);
    
    return 0;
}
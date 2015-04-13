/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 04b - O Lobo de Wall Street*/

#include <stdio.h>
#define MAX 100

int main(){
    
    /* i, j, k e l são ponteiros, c = capital, 
     * valor[i] guarda o valor de cada dia 
     * cInicial, cAtual e cFinal sao usadas para nao perder dados*/ 
    int nDias, nAcoes, cInicial, cAtual, cFinal, valor[MAX], 
    resto, i, j, k, l, maior=0, decres=0;
    
    for(i=0;i<MAX;i++){
        valor[i]=0;
    }
    
    /*entrada*/
    scanf("%d %d", &nDias, &cInicial);   
    for(i=0;i<nDias;i++)
        scanf("%d", &valor[i]);
    
    /*processamento*/
    for(i=0;i<nDias;i++){ 
        /* esse if verifica se os valores nao sao decrescentes */
        if(valor[i]<valor[i+1])
            decres=1;
        
        /* a partir daqui se processam as possibilidades de venda e compra;
         * os ponteiros sao iniciados com base nos mais externos para se 
         * evitar que um valor faca operacao com ele mesmo*/
        for(j=i+1;j<nDias;j++){  
            nAcoes=cInicial/valor[i];
            resto=cInicial%valor[i];
            cAtual=(nAcoes*valor[j])+resto;
            
            if(cAtual>maior){
                maior=cAtual;          
            }
            
            for(k=j+1;k<nDias;k++){  
                for(l=k+1;l<nDias;l++){ 
                    cFinal=cAtual;
                    nAcoes=cFinal/valor[k];
                    resto=cFinal%valor[k];
                    cFinal=(nAcoes*valor[l])+resto;
                    
                    if(cFinal>maior){
                        maior=cFinal;
                    }               
                }
            }
        }
    }    
    
    /*se decres for falso, imprime o maior valor encontrado*/
    if(decres==1)
        printf("Capital final = R$%d\n", maior);
    else
        printf("Melhor nao investir agora, cara!\n");
    
    return 0;
}
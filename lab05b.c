/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 05b - Distancia de Tchonsky */

#include <stdio.h>
#define TAM 101

int main(){
    
    /* a=palavra a; b=palavra b */
    /* c=caracteres em comum; d=distancia de Tchonsky */
    char a[TAM], b[TAM], alfabeto[26];
    int  c=0, d, i, letra, tamA=0, tamB=0;
    
    for(i=0;i<26;i++)
        alfabeto[i]=0;
    
    
    scanf("%s %s", a, b);
    
    i=0;  
    while(a[i]){
        if(a[i]>='a')
            letra=a[i]-'a';
        else 
            letra=a[i]-'A';
        
        alfabeto[letra]++;
        
        i++;
        tamA++;
    }
    
    i=0;
    while(b[i]){
        if(b[i]>='a')
            letra=b[i]-'a';
        else 
            letra=b[i]-'A';
        
        if(alfabeto[letra]>0){
            alfabeto[letra]--;
            c++;
        }
        
        i++;
        tamB++;
    }
    
    
    d = (tamA + tamB) - 2 * c;
    
    printf("Distancia de Tchonsky = %d\n", d);
    
    return 0;
}
/* Nome: André Figueiredo de Almeida
 * RA: 164047
 * Laboratorio 05b - Distancia de Tchonsky */

#include <stdio.h>
#include <string.h>
#define TAM 101

int main(){
    
    /* a=palavra a; b=palavra b */
    /* c=caracteres em comum; d=distancia de Tchonsky */
    char a[TAM], b[TAM], alfabeto[26];
    int  c=0, d, i, letra;
    
    for(i=0;i<26;i++)
        alfabeto[i]=0;
    
    
    scanf("%s %s", a, b);
    
    
    i=0;  
    /* o laco acabara quando se encontrar o fim da palavra */
    while(a[i]){
        /* esse if atribui as letras maiusculas e minusculas o mesmo valor */
        if(a[i]>='a')
            letra=a[i]-'a';
        else 
            letra=a[i]-'A';
        
        /* cada pos do vetor guarda o numero de vezes que cada letra aparece 
         * alfabeto[0] para letra 'A', alfabeto[1] para letra 'B', ... */
        alfabeto[letra]++;
        
        i++;
    }
    
    i=0;
    while(b[i]){
        if(b[i]>='a')
            letra=b[i]-'a';
        else 
            letra=b[i]-'A';
        
        /* aqui se contam os chars repetidos */
        if(alfabeto[letra]>0){
            alfabeto[letra]--;
            c++;
        }
        
        i++;
    }
    
    
    d = (strlen(a) + strlen(b)) - 2 * c;
    
    printf("Distancia de Tchonsky = %d\n", d);
    
    return 0;
}
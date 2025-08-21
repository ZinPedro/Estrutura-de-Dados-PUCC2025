/*Faça uma função recursiva que permita somar os
elementos de um vetor de inteiros.*/

#include <stdio.h>
#include <stdlib.h>

int somador(int n,int V[]){

        if(n == 1){
            return V[n-1];
        }else{
            return V[n-1] + somador(n-1,V);
        }

}

int main(){
    int n;

    printf("Soma os numeros de um vetor: \n");

    printf("Qual o tamanho do vetor? ");
    scanf("%d",&n);

    int V[n],j=n;;

    for(int i=0;i<n;i++){
        printf("Digite um numero do vetor (numero restantes %d): ",j);
        scanf("%d",&V[i]);
        j--;
    }

    int soma = somador(n,V);

    printf("Resultado da soma dos %d numeros do vetor eh: %d",n,soma);


    return 0;
}
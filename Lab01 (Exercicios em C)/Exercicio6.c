/*Fazer um programa em C para ler um vetor de inteiros
positivos de 15 posições, no máximo. Imprimir a quantidade
de números pares e a quantidade de múltiplos de 5*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,cntP=0,cnt5=0;

    for(int i=15; i>0; i--){
        printf("Digite um numero (%d numeros restantes): ",i);
        scanf("%d",&n);

        if(n%2==0){
            cntP++;
        }
        if(n%5==0){
            cnt5++;
        }
    }

    printf("O numero de numeros pares foi: %d \n",cntP);
    printf("O numero de numeros multiplos de 5 foi: %d",cnt5);

    return 0;
}

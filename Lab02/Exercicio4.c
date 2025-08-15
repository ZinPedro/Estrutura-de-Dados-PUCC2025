/*Determine um algoritmo iterativo e recursivo que calcule
a soma de N números inteiros ímpares sequenciais a partir do um*/

#include <stdio.h>
#include <stdlib.h>

int sequencia (int n){

        if(n == 1){
            return 1;
        }else{
            return (2*n-1) + sequencia(n-1);
        }

}

int main(){
    int n;

    printf("Soma de n numeros Impares sequenciais (comecando do 1): \n");

    printf("Digite o numero referente a n (quantidade de numeros da soma): ");
    scanf("%d",&n);

    int soma = sequencia(n);

    printf("Resultado da soma dos %d primeiros numeros impares eh: %d",n,soma);


    return 0;
}
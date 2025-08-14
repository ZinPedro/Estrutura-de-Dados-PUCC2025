/*Elabore um programa que leia 3 números inteiros. Este
programa deverá ter uma função que retorne o fatorial de um
número. Use essa função, para calcular o fatorial dos números
lidos (imprima no programa principal).*/

#include <stdio.h>
#include <stdlib.h>

int fatorial (int n){

    for (int i=n;i > 1;){
        i--;
        n *= i;
    }

    return n;
}

int main(){
    int x,y,z,c;

    printf("Calculo: !x, !y, !z");


    printf("\nDigite o numero referente a x: ");
    scanf("%d",&x);

    printf("Digite o numero referente a y: ");
    scanf("%d",&y);

    printf("Digite o numero referente a z: ");
    scanf("%d",&z);

    x = fatorial(x);
    y = fatorial(y);
    z = fatorial(z);


    printf("\nO fatorial dos numeros x, y e z sao: %d, %d, %d (respectivamente)",x,y,z);

    return 0;
}

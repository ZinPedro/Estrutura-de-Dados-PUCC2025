//Elabore um programa em C que leia um número inteiro e determine quantos dígitos 7 possui esse número

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){

    setlocale(LC_ALL,"portuguese");

    int numero,resto,contador;

    printf("Digite um número: ");
    scanf("%d",&numero);
    contador = 0;
    resto = 0;

    do{
        resto = numero % 10;
        if(resto == 7){
            contador++;
        }
        numero /= 10;
    }
    while(numero != 0);

    printf("O número de 7 no número é: %d",contador);

    return 0;
}

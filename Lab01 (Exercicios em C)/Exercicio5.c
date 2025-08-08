/*Dada a sequência matemática de números 2, 3, 5,8,13, 21.... (Fibonatti)
Construa um programa que calcule a soma desta sequência
para os N primeiros termo onde, N é fornecido pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, num = 2, fib = 1, soma = 0;

    printf("Qual o tamanho da sequencia para soma?\n");
    scanf("%d",&N);

    for(int i=0; i < N; i++){
        soma += num;
        num += fib;
        fib = num - fib;

    }

    printf("A soma da sequencia de Fibonatti eh: %d", soma);

    return 0;
}


/*Construa um programa que leia vários números inteiros
positivos. O programa será encerrado quando um número
NÃO positivo for digitado e irá calcular:
• A quantidade de números lidos
• A soma dos números que são múltiplos de 3 maiores que
10
• A quantidade de múltiplos de 3
• O percentual de múltiplos de 7*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){

    setlocale(LC_ALL,"portuguese");

    int numero,cntN,cntM3M10, cntM3, cntM7, resto;
    cntN = 0;
    cntM3M10 = 0;
    cntM3 = 0;
    cntM7 = 0;

    do {
        printf("Digite o %d° número (digite um número negativo para encerrar contagem de números): ", cntN+1);
        scanf("%d",&numero);
        if(numero > 0){
            cntN++;
            resto = numero % 3;

            if (resto == 0){
                cntM3++;
                if (numero > 10){
                    cntM3M10++;
                }
            }

            resto = numero % 7;

            if (resto == 0){
                cntM7++;
            }
        }
    } while (numero > 0);

    printf("A quantidade de números lidos foi: %d \n", cntN);
    printf("A quantidade de números múltiplos de 3 maiores que 10 foi: %d \n", cntM3M10);
    printf("A quantidade de números múltiplos de 3 foi: %d \n", cntM3);
    printf("A quantidade de números múltiplos de 7 foi: %d \n", cntM7);

    return 0;
}
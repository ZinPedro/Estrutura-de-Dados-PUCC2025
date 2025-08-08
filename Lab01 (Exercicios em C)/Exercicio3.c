/*O quadrado de um número natural N é dado pela soma dos N
primeiros números ímpares consecutivos. Por exemplo:
3^2 = 1+3+5=9
4^2 = 1+3+5+7=16
Elabore um programa que leia um número natural N e calcule
o seu quadrado usando o cálculo acima.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){

    setlocale(LC_ALL,"portuguese");

    int numero,quadrado = 0, nImpar = 1;

    printf("Digite um número: ");
    scanf("%d",&numero);

    for(int i=0; i < numero; i++){
        quadrado += nImpar;
        nImpar += 2;
    }

    printf("O quadrado do número digitado é: %d", quadrado);

    return 0;

}

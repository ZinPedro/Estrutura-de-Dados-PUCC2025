// Escreva um programa que calcule e imprima o valor de S: S = 1/1 - 2/4 + 3/9 - 4/16 + ... - 10/100

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"portuguese");

    int n;

    printf("Digite o número referente ao númerador da última fração: ");
    scanf("%d",&n);

    float S;

    for(int i=1; i <= n; i++){
        if (i%2==0){
            S -= (float)i / (i * i);
        }else{
            S += (float)i / (i * i);
        }
    }
    
    printf("O resultado é: %f", S);

    return 0;
}

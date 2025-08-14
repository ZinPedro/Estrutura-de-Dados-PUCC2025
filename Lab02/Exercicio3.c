/*Escreva uma função recursiva, ImprimeSerie(i,j,k: inteiro),
que imprime na tela a série de valores do intervalo [i,j],
com incremento k.*/

#include <stdio.h>
#include <stdlib.h>

void ImprimeSerie (int i, int j, int k){

    if(i > j){
        return;
    }
    printf("%d ",i);

    ImprimeSerie(i+k,j,k);
}

int main(){
    int i,j,k;

    printf("Intervalo sequencial entre i e j ([i,j]) com incremento k: \n");


    printf("Digite o numero referente a i: ");
    scanf("%d",&i);

    do{
        printf("Digite o numero referente a j: ");
        scanf("%d",&j);
        if(j < i){
            printf("Numero Invalido (j precisa ser maior do que i)!\n");
        }
    }while (j < i);

    printf("Digite o numero referente a k: ");
    scanf("%d",&k);

    printf("Sequencia [i,j] +k: ");

    ImprimeSerie(i,j,k);

    return 0;
}

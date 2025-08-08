/*Preencher um vetor de 8 elementos inteiros. Mostrar o vetor
e informar quantos números são maiores que 30.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n=0,V[7],cnt30=0;

    for(int i=8;i>0;i--){
        printf("Digite um numero (%d numeros restantes): ",i);
        scanf("%d",&V[n]);

        if(V[n]>30){
            cnt30++;
        }

        n++;
    }

    printf("Numeros digitados: ");

    for (int i=0;i<8;i++){
            printf("%d ",V[i]);
    }

    printf("\nQuantidade de numeros maiores que 30: %d.", cnt30);

    return 0;

}
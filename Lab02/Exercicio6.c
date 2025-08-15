/*Elabore uma função recursiva que determina o elemento
máximo de um vetor*/

//inacabado

#include <stdio.h>
#include <stdlib.h>

int verifica(int n,int V[],int maior){

        if(n >= 1){
            if(V[n-1]>V[n]){
               return verifica(n-1,V,V[n-1]);
            }else {
                return verifica(n-1,V,V[n]);
            }
        }else {
            return;
        }

}

int main(){
    int n;

    printf("Maior numero de um vetor: \n");

    printf("Qual o tamanho do vetor? ");
    scanf("%d",&n);

    int V[n],j=n;;

    for(int i=0;i<n;i++){
        printf("Digite um numero do vetor (numero restantes %d): ",j);
        scanf("%d",&V[i]);
        j--;
    }

    int maior = verifica(n-1,V,V[n]);

    printf("snkjsbv: %d",n,soma);


    return 0;
}

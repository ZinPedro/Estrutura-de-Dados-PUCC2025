/*Elabore uma função recursiva que determina o elemento
máximo de um vetor*/

#include <stdio.h>
#include <stdlib.h>

int verifica(int n,int V[]){

    //caso base
    if (n==0){
            return V[0];
        } else {
            int maior = verifica(n-1,V);

            if(V[n]>maior){
               return V[n];
            }else {
               return maior ;
            }
        }

}

int main(){
    int n;

    printf("Maior numero de um vetor: \n");

    printf("Qual o tamanho do vetor? ");
    scanf("%d",&n);

    int V[n],j=n;

    for(int i=0;i<n;i++){
        printf("Digite um numero do vetor (numero restantes %d): ",j);
        scanf("%d",&V[i]);
        j--;
    }

    int maior = verifica(n-1,V);

    printf("O maior numero do vetor eh: %d",maior);


    return 0;
}

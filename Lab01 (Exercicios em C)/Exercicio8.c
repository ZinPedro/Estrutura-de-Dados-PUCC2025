/*Faça um algoritmo que leia uma matriz quadrada de no
máximo 3 posições e determine qual é o maior e o
menor valor da linha 2 e qual é o maior e o menor valor
da coluna 1.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int M[3][3],Ml2=0,ml2=0,Mc1=0,mc1=0;

    printf("Digite a Matriz 3x3: \n");

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("linha %d, coluna %d: ",i+1,j+1);
            scanf("%d",&M[i][j]);

            //Primeira leitura linha 2
            if(i==1 && j==0){
                Ml2 = M[i][j];
                ml2 = M[i][j];
            }

            //verificador linha 2
            if(i==1 && Ml2 < M[i][j]){
                Ml2 = M[i][j];
            }else if(i==1 && ml2 > M[i][j]){
                ml2 = M[i][j];
            }

            //Primeira leitura linha 2
            if(i==0 && j==0){
                Mc1 = M[i][j];
                mc1 = M[i][j];
            }


            //verificador coluna 1
            if(j==0 && Mc1 < M[i][j]){
                Mc1 = M[i][j];
            }else if(i==1 && mc1 > M[i][j]){
                mc1 = M[i][j];
            }
        }
    }

    printf("   Matriz digitada:");

    for(int i=0;i<3;i++){
        printf("\n\t");
        for(int j=0;j<3;j++){
            printf("%d ",M[i][j]);
        }
    }

    printf("\nO maior numero da linha 2 eh: %d \n", Ml2);
    printf("O menor numero da linha 2 eh: %d \n", ml2);
    printf("O maior numero da coluna 1 eh: %d \n", Mc1);
    printf("O menor numero da coluna 1 eh: %d \n", mc1);

    return 0;
}
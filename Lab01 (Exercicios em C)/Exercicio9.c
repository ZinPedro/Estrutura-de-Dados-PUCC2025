/*Faça um algoritmo que leia uma matriz de no máximo 4
linhas e 4 colunas. O programa deverá:
• Elaborar a matriz transposta
• Trocar os valores da coluna 0 com a coluna 3
• Determinar quantos números pares tem essa matriz
• A soma dos valores da diagonal principal
• O maior valor da diagonal secundária
• Determine a soma de cada linha desta matriz, coloque o
resultado em um vetor
• Determine o maior valor de cada coluna dessa matriz,
coloque o resultado em um vetor
• A cada item, a matriz resultante deverá ser impressa.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    //leitura tamanho da matriz
    int N;
    do{
    printf("Qual o tamanho da matriz quadrada? (minimo 2 e maximo 4)\n");
    scanf("%d",&N);
    if(N<2 || N>4){
        printf("Tamanho Invalido");
    }
    }while(N<2 || N>4);

    int M[N][N], cntP=0;

    //leitura matriz
    printf("Digite a Matriz %dx%d: \n",N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("linha %d, coluna %d: ",i+1,j+1);
            scanf("%d",&M[i][j]);

            if(M[i][j]%2==0){
                cntP++;
            }
        }
    }

    //amostra da matriz digitada
    printf("   Matriz digitada:");
    for(int i=0;i<N;i++){
        printf("\n\t");
        for(int j=0;j<N;j++){
            printf("%d ",M[i][j]);
        }
    }

    //matriz transposta
    printf("   \nMatriz transposta:");
    for(int j=0;j<N;j++){
        printf("\n\t");
        for(int i=0;i<N;i++){
            printf("%d ",M[i][j]);
        }
    }
    return 0;

}

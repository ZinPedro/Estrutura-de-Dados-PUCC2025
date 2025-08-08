/*Faça um algoritmo que leia uma matriz de no máximo 4
linhas e 4 colunas. O programa deverá:
• Elaborar a matriz transposta
• Trocar os valores da primeira coluna com a ultima coluna
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
        printf("Tamanho Invalido\n");
    }
    }while(N<2 || N>4);

    int M[N][N], cntP=0, somaDP=0, maiorDS, S[N], C[N];

    //leitura matriz
    printf("Digite a Matriz %dx%d: \n",N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("linha %d, coluna %d: ",i+1,j+1);
            scanf("%d",&M[i][j]);

            //contagem de nummeros pares
            if(M[i][j]%2==0){
                cntP++;
            }

            //soma da diagonal principal
            if(i == j){
                somaDP += M[i][j];
            }

            //salva o primeiro valor da diagonal secundaria e o primeiro de cada coluna (para ser usada como referencia)
            if(i == 0){
                C[j] = M[i][j];

                if(j == (N-1)){
                    maiorDS = M[i][j];
                }
            }


        }
    }

    //amostra da matriz digitada
    printf(" Matriz digitada:");
    for(int i=0;i<N;i++){
        printf("\n\t");
        for(int j=0;j<N;j++){
            printf("%d ",M[i][j]);
        }
    }

    //matriz transposta
    printf("\n Matriz transposta:");
    for(int j=0;j<N;j++){
        printf("\n\t");
        for(int i=0;i<N;i++){
            printf("%d ",M[i][j]);
        }
    }

    //matriz trocada (primeira coluna >< ultima coluna)
    printf("\n Matriz trocada (primeira coluna >< ultima coluna):");

    for(int i=0;i<N;i++){
        printf("\n\t");
        for(int j=0;j<N;j++){
            if (j == 0){
                printf("%d ",M[i][j+(N-1)]);
            }else if(j == (N-1)){
                printf("%d ",M[i][j-(N-1)]);
            }else{
                printf("%d ",M[i][j]);
            }
        }
    }

    //verificação de maior numero da diagonal secundaria
    for(int i=1;i<N;i++){
        int j=N-2;
            if(maiorDS < M[i][j]){
                maiorDS = M[i][j];
            }
        j--;
    }

    printf("\nQuantidade de numeros pares: %d\n",cntP);
    printf("Soma da diagonal principal: %d\n",somaDP);
    printf("Maior numero da diagonal secundaria: %d\n",maiorDS);

    //Soma das linhas da matriz e descobre qual o maior valor de cada coluna
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j==0){
                S[i] = 0;
            }
            S[i] += M[i][j];

            if (C[j] < M[i][j]){
                C[j] = M[i][j];
            }
        }
        printf("Soma da linha %d: %d\n",i+1,S[i]);
    }

    //Imprime os maiores numeros das colunas
    for(int j=0;j<N;j++){
        printf("Maior numero da coluna %d: %d\n",j+1,C[j]);
    }

    return 0;

}
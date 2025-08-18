/*Elabore um programa que crie uma estrutura com as
seguintes informações de um produto:
• Código do produto – inteiro de 3 dígitos
• Quantidade em estoque - inteiro
• Valor de compra - real
• Valor de Venda - real
O programa deverá ler a informação de 10 produtos e
determinar
• O código do produto com maior quantidade de estoque
• O quantidade de estoque do produto que proporciona o
maior lucro*/

#include <stdio.h>
#include <stdlib.h>

int verifica1(int n,int V[], int *indice){
    if(n==0){
        *indice = 0;
        return V[0];
    } else {
        int idx;
        int maior = verifica1(n-1,V,&idx);
        if (V[n]>maior){
            *indice = n;
            return V[n];
        }else{
            *indice = idx;
            return maior;
        }
    }
}

int verifica2(int n, int V[], int C[],int *indice){
    if (n==0){
        *indice = 0;
        return (V[0] - C[0]);
    } else {
        int idx;
        int Mlucro = verifica2(n-1,V,C,&idx);
        if((V[n] - C[n])>Mlucro){
            *indice = n;
            return (V[n] - C[n]);
        }else{
            *indice = idx;
            return Mlucro;
        }
    }

}

int main(){
    const int n=4;
    int C[n],Qestoque[n];
    float Vcompra[n],Vvenda[n];

    printf("Leitura %d Produtos: \n",n);

    for(int i=0;i<n;i++){
        do{
            printf("Digite o codigo (3 digitos) do produto %d: ",i+1);
            scanf("%d",&C[i]);
            if(!(C[i]>99 && C[i]<1000)){
                printf("Codigo Invalido. O codigo deve ter 3 digitos!");
            }
        }while(!(C[i]>99 && C[i]<1000));

        printf("Qual a quantidade de estoque do produto %d:  ",i+1);
        scanf("%d",&Qestoque[i]);
        printf("Qual o valor de compra produto %d(em reais): ",i+1);
        scanf("%f",&Vcompra[i]);
        printf("Qual o valor de venda produto %d(em reais): ",i+1);
        scanf("%f",&Vvenda[i]);
    }

    int indiceMaiorEstoque=0;
    verifica1(n-1,Qestoque,&indiceMaiorEstoque);

    printf("Codigo do produto com maior estoque: %d",C[indiceMaiorEstoque]);

    int indiceMaiorLucro=0;
    verifica2(n-1,Vvenda,Vcompra,&indiceMaiorLucro);

    printf("\nEstoque do produto com maior Lucro: %d",Qestoque[indiceMaiorLucro]);


    return 0;
}

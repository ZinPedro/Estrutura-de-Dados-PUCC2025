#include <stdio.h>
#include <stdlib.h>
#include "BiblioArvore.h"

int main (){
    int sair = 0,op = 0, v;
    Arv *A = CriaArvore();

    while (sair != 1){
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | MENU |");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | Opcoes: ");
        printf("\n\t\t\t\t 1. Inserir valor (inteiro) na Arvore: ");
        printf("\n\t\t\t\t 2. Imprimir Arvore: ");

        printf("\n\t\t\tDigite o numero referente a opcao desejada: ");
        scanf("%d",&op);

        if(op < 1 || op > 2){
            system("cls");
            printf("\t\t\t---------------------------------------------------------");
            printf("\n\t\t\tOpcao invalida. Tente novamente!\n");
            continue;
        }

        switch(op){
            case 1:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tDigite o valor que voce quer inserir na Arvore: ");
                scanf("%d",&v);
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                InsereArvore(A,v);
                if(!VaziaArvore(A)){
                    printf("Arvore: ");
                    ImprimeArv(A,2);
                }
            break;
            case 2:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tQual a ordem de impressao(1- PreOrder, 2- InOrder, 3- PosOrder): ");
                scanf("%d",&v);
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!VaziaArvore(A)){
                    printf("Arvore: ");
                    ImprimeArv(A,v);
                }else{
                    printf("A Arvore está vazia!");
                }
            break;

        }

    }


}

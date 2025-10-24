#include <stdio.h>
#include <stdlib.h>
#include "BiblioArvore.h"

int SomaArv(Arv *A){

    return SomaAux(A->raiz);
}

int SomaAux(NoArv *Pai){
    int soma = Pai->info;
    if(Pai->dir != NULL){
        soma = soma + SomaAux(Pai->dir);
    }
    if(Pai -> esq != NULL){
        soma = soma + SomaAux(Pai->esq);
    }
    return soma;
}

int NumFolhas(NoArv *Pai){
    int cnt;
    if(Pai -> esq == NULL && Pai -> dir == NULL){
        cnt = 1;
    } else {
        cnt = 0;
    }
    if(Pai->dir != NULL){
        cnt = cnt + NumFolhas(Pai->dir);
    }
    if(Pai -> esq != NULL){
        cnt = cnt + NumFolhas(Pai->esq);
    }
    return cnt;
}

int NumElemMaiorQ(Arv *A, int num){
    NoArv *Pai = A->raiz;
    int flag = 0;
    while(flag == 0){
        if(Pai -> info <= num){
            if(Pai->dir != NULL){
                Pai = Pai -> dir;
            }else{
                return 0;
            }
        }
        else{
            return NumElementos(Pai);
            flag = 1;
            printf("Erro Desconhecido!");
        }
    }
}


int main (){
    int sair = 0,op = 0, v;
    Arv *A = CriaArvore();

    while (sair != 1){
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | MENU |");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | Opcoes: ");
        printf("\n\t\t\t\t 1. Inserir valor (inteiro) na Arvore: ");
        printf("\n\t\t\t\t 2. Remover valor (inteiro) da Arvore: ");
        printf("\n\t\t\t\t 3. Imprimir Arvore: ");
        printf("\n\t\t\t\t 4. Esvaziar Arvore: ");
        printf("\n\t\t\t\t 5. Soma dos elementos da Arvore: ");
        printf("\n\t\t\t\t 6. Numero de Elementos da Arvore: ");
        printf("\n\t\t\t\t 7. Numero de Folhas da Arvore: ");
        printf("\n\t\t\t\t 8. Numero de Elementos maior que x da Arvore: ");


        printf("\n\t\t\tDigite o numero referente a opcao desejada: ");
        scanf("%d",&op);

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
                printf("\n\t\t\tDigite o valor que voce quer remover da Arvore: ");
                scanf("%d",&v);
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                A = RemoveArvore(A,v);
                if(!VaziaArvore(A)){
                    printf("Arvore: ");
                    ImprimeArv(A,2);
                }
            break;
            case 3:
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
            case 4:
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!VaziaArvore(A)){
                    LiberaArvore(A);
                    Arv *A = CriaArvore();
                    printf("Arvore limpa com sucesso.");

                }else{
                    printf("A Arvore ja esta vazia!");
                }
            break;
            case 5:
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!VaziaArvore(A)){
                    v = SomaArv(A);
                    printf("Soma:  %d",v);
                }else{
                    printf("A Arvore está vazia!");
                }
            break;
            case 6:
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!VaziaArvore(A)){
                    v = NumElementos(A->raiz);
                    printf("Numero de Elementos: %d",v);
                }else{
                    printf("A Arvore está vazia!");
                }
            break;
            case 7:
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!VaziaArvore(A)){
                    v = NumFolhas(A->raiz);
                    printf("Numero de Folhas: %d",v);
                }else{
                    printf("A Arvore está vazia!");
                }
            break;
            case 8:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tQual o valor de x: ");
                scanf("%d",&v);
                system("cls");
                printf("\n\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!VaziaArvore(A)){
                    printf("Numero de elementos maiores que x na Arvore: %d", NumElemMaiorQ(A,v));

                }else{
                    printf("A Arvore está vazia!");
                }
            break;

            default:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tOpcao invalida. Tente novamente!");
            break;
        }

    }


}

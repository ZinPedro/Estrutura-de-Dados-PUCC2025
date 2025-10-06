#ifndef BIBLIOARVORE_H_INCLUDED
#define BIBLIOARVORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {
    int info;
    struct noArvore *dir;
    struct noArvore *esq;
}NoArv;

typedef struct arvore{
    NoArv *raiz;
}Arv;

Arv* CriaArvore(void){
    Arv *A;
    A = (Arv*)malloc(sizeof(Arv));
    A->raiz = NULL;
    return A;
}

int VaziaArvore (Arv *A){
    if (A->raiz == NULL){
        return 1;
    }else{
        return 0;
    }
}

NoArv* InsereAux(NoArv *raiz, int num){

    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo -> info = num;
    novo -> esq = NULL;
    novo -> dir = NULL;

    if(raiz == NULL){  //Se a arvore ta vazia, novo eh a nova raiz
        return novo;
    }else{
        int flag = 0;
        NoArv *Pai = raiz;
        while(flag == 0){
            if(novo->info > Pai->info){
                if(Pai -> dir == NULL){
                    Pai -> dir = novo;
                    flag = 1;
                }else{
                    Pai = Pai -> dir;
                }
            }else if(novo->info < Pai -> info){
                if(Pai -> esq == NULL){
                    Pai -> esq = novo;
                    flag=1;
                }else{
                    Pai = Pai->esq;
                }
            }else if(novo ->info == Pai -> info){
                printf("Numero ja existe na Arvore!\n\t\t\t");
                free(novo);
                flag = 1;
            }else{
                printf("Erro Desconhecido!");
                free(novo);
                flag = 1;
            }
        }
        return raiz;

    }

}

void InsereArvore(Arv *A, int num){
    A->raiz = InsereAux(A->raiz, num);
}

void PreOrder(NoArv *Pai){
    printf("%d ", Pai->info);
    if(Pai -> esq != NULL){
        PreOrder(Pai->esq);
    }
    if(Pai -> dir != NULL){
        PreOrder(Pai->dir);
    }
}

void InOrder(NoArv *Pai){
    if(Pai -> esq != NULL){
        InOrder(Pai->esq);
    }
    printf("%d ", Pai->info);
    if(Pai -> dir != NULL){
        InOrder(Pai->dir);
    }
}

void PosOrder(NoArv *Pai){
    if(Pai -> esq != NULL){
        PosOrder(Pai->esq);
    }
    if(Pai -> dir != NULL){
        PosOrder(Pai->dir);
    }
    printf("%d ", Pai->info);
}

void ImprimeArv(Arv *A, int tipo){  //tipo: 1-PreOrder, 2-InOrder, 3-PosOrder
    if(tipo == 1){
        PreOrder(A->raiz);
        return;
    }else if(tipo == 2){
        InOrder(A->raiz);
        return;
    }else if(tipo == 3){
        PosOrder(A->raiz);
        return;
    }else{
        printf("Erro, Tipo de Impressão Inválida");
        return;
    }
}

int BuscaArvore(Arv *A, int num){
    NoArv *Pai = A -> raiz;
    int flag = 0;

    while(flag == 0){
        if(Pai -> info == num){
            return 1;
        }
        if(Pai -> info > num){
            if(Pai->esq != NULL){
                Pai = Pai->esq;
            }else{
                return 0;
            }
        }else if(Pai -> info < num){
            if(Pai -> dir != NULL){
                Pai = Pai->dir;
            }else{
                return 0;
            }
        }else{
            printf("Erro Desconhecido!");
        }
    }
}

int NumElementos(NoArv *Pai){
    int cnt = 1;
    if(Pai->dir != NULL){
        cnt = cnt + NumElementos(Pai->dir);
    }
    if(Pai -> esq != NULL){
        cnt = cnt + NumElementos(Pai->esq);
    }
    return cnt;
}

#endif // BIBLIOARVORE_H_INCLUDED

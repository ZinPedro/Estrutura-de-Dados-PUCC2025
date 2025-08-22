/*Construa, em C, um programa que contenha as seguintes
funções de Lista Encadeada- Básica
• Inserção de um Elemento da Lista (inserir no início)
• Remoção de um Elemento da Lista (retirar do início)
• Impressão da Lista
• Busca de um elemento na Lista, retorna 1 se ele existe e 0
caso contrário
• Uma função que verifica se a lista está vazia, retorna 1 se ela
estiver vazia e 0 caso contrário
• Uma função que retorne a quantidade de elementos de uma
lista. A lista é passada por parâmetro .
• Uma função que some os elementos de uma lista que é
passada por parâmetro*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}no;

typedef no Lista;

Lista* Inicializa (){
    return NULL;
}

Lista* Insere (Lista *aux,int v){
    Lista *novo;

    novo = (Lista*) malloc(sizeof(Lista));
    if(novo != NULL){
        novo -> info = v;
        novo -> prox = aux;
        printf("Valor '%d' adcionado com exito!",v);
        return novo;
    }
    printf("Memoria cheia.");
    return aux;
}

Lista* Exclui (Lista *aux){
    if (aux != NULL){
        Lista *aux2;
        aux2 = aux;
        aux = aux -> prox;
        free(aux2);

        printf("Ultimo elemento da lista excluido!");
        return aux;
    }
    printf("A lista ja esta vazia!");
    return aux;
}

void Imprime (Lista *aux){
    if(aux == NULL){
        printf("A lista esta vazia!");
    }else {

        printf("Lista: ");
        while(aux != NULL){
            printf("%d ",aux -> info);
            aux = aux -> prox;
        }
    }
    return;
}

int Busca (Lista *aux,int valor){
    while (aux != NULL){
        if (aux -> info == valor){
            return 1;
        }
        aux = aux -> prox;
    }

    return 0;
}

int ListaVazia (Lista *aux){
    if (aux == NULL){
        return 1;
    }else {
        return 0;
    }
}

int nElemenntosLista(Lista *aux){
    int cnt=0;
    while(aux != NULL){
        cnt++;
        aux = aux -> prox;
    }
    return cnt;
}

int somaLista(Lista *aux){
    int soma=0;
    while(aux != NULL){
        soma += aux->info;
        aux = aux -> prox;
    }
    return soma;
}



int main (){
    int op,verifica,v;
    int sair = 0;


    Lista *L;
    L = Inicializa();

    while (sair != 1){

        printf("\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | MENU |");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | Opcoes: ");
        printf("\n\t\t\t\t 1. Inserir valor (inteiro) na lista: ");
        printf("\n\t\t\t\t 2. Remover ultimo valor inserido da lista: ");
        printf("\n\t\t\t\t 3. Imprimir lista: ");
        printf("\n\t\t\t\t 4. Buscar valor na lista: ");
        printf("\n\t\t\t\t 5. Verificar se a lista esta vazia: ");
        printf("\n\t\t\t\t 6. Verificar o numero de elementos da lista: ");
        printf("\n\t\t\t\t 7. Soma dos elementos da lista: ");
        printf("\n\t\t\t\t 8. Sair. ");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\tDigite o numero referente a opcao desejada: ");
        scanf("%d",&op);

        if(op < 1 || op > 8){
            system("cls");
            printf("\t\t\t---------------------------------------------------------");
            printf("\n\t\t\tOpcao invalida. Tente novamente!\n");
            continue;
        }

        switch (op){
            case 1:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tDigite o valor que voce quer inserir na lista: ");
                scanf("%d",&v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                L = Insere(L,v);
                printf("\n");
            break;
            case 2:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                L = Exclui(L);
                printf("\n");

            break;
            case 3:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                Imprime(L);
                printf("\n");
            break;
            case 4:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tQual o valor que voce quer buscar: ");

                scanf("%d",&v);
                verifica = Busca(L,v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                if (verifica == 1){
                    printf("\n\t\t\tO valor %d existe na lista!\n",v);
                }else if(verifica == 0){
                    printf("\n\t\t\tO valor %d nao existe na lista!\n",v);
                }else{printf("\n\t\t\tErro!");}
            break;
            case 5:
                verifica = ListaVazia(L);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                if (verifica == 1){
                    printf("\n\t\t\tA lista esta vazia!\n");
                }else if(verifica == 0){
                    printf("\n\t\t\tA lista nao esta vazia\n");
                }else{printf("\n\t\t\tErro!");}
            break;
            case 6:
                verifica = nElemenntosLista(L);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tO tamanho da lista eh de %d elementos\n",verifica);
            break;
            case 7:
                verifica = somaLista(L);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tA soma de todos os elementos da lista eh igual a: %d\n",verifica);
            break;
            case 8:
                sair = 1;
            break;
        }
    }

    return 0;
}

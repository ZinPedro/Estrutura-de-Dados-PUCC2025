/*Vamos complicar um pouquinho, criando outras funções de
Lista Linear (utilizar ex1 como base
• Inserção de um Elemento da Lista (inserir no fim da lista)
• Remoção de um Elemento da Lista (retirar do fim da lista)
• Uma função que retorna a quantidade de números ímpares da lista
• Uma função que receba duas listas e retorne uma terceira lista
que é a união dessas duas listas (Não é permitido elementos
repetidos na Lista União)*/

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

Lista* InsereInicio (Lista *aux,int v){
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

Lista* InsereFim (Lista *aux,int v){
    Lista *novo;
    Lista *aux2;

    novo = (Lista*) malloc(sizeof(Lista));
    if(novo != NULL){
        novo -> info = v;
        novo -> prox = NULL;
        printf("Valor '%d' adcionado com exito!",v);

        if(aux == NULL){
            return novo;
        }

        aux2 = aux;

        while(aux2 -> prox != NULL){
            aux2 = aux2 -> prox;
        }

        aux2 -> prox = novo;


        return aux;
    }
    printf("Memoria cheia.");
    return aux;
}

Lista* ExcluiInicio (Lista *aux){
    if (aux != NULL){
        Lista *aux2;
        aux2 = aux;
        aux = aux -> prox;
        free(aux2);

        printf("Elemento do inicio da lista excluido!");

        return aux;
    }
    printf("A lista ja esta vazia!");
    return aux;
}

Lista* ExcluiFim (Lista *aux){
    if (aux != NULL){
        printf("Elemento do fim da lista excluido!");
        if (aux -> prox == NULL){
            free(aux);
            return NULL;
        }else{
            Lista *aux2;
            aux2 = aux;
            while(aux2 -> prox -> prox != NULL){
                aux2 = aux2 -> prox;
            }
            free(aux2 -> prox);
            aux2 -> prox = NULL;
            return aux;
        }
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

int nImparesLista(Lista *aux){
    int cnt=0;
    while(aux != NULL){
        if(aux->info%2 != 0){
            cnt++;
        }
        aux = aux -> prox;
    }
    return cnt;
}

Lista *UniaoLista(Lista *L1,Lista *L2){
    Lista *uniao = Inicializa();
    while(L1 != NULL){
        if(!Busca(uniao,L1->info)){
            uniao = InsereInicio(uniao,L1->info);
        }
    L1 = L1 -> prox;
    }

    while(L2 != NULL){
        if(!Busca(uniao,L2->info)){
            uniao = InsereFim(uniao,L2->info);
        }
    L2 = L2 -> prox;
    }
    return uniao;
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
        printf("\n\t\t\t\t  1. Inserir valor (inteiro) no inicio da lista: ");
        printf("\n\t\t\t\t  2. Inserir valor (inteiro) no final lista: ");
        printf("\n\t\t\t\t  3. Remover valor do inicio da lista: ");
        printf("\n\t\t\t\t  4. Remover valor do final da lista: ");
        printf("\n\t\t\t\t  5. Imprimir lista: ");
        printf("\n\t\t\t\t  6. Buscar valor na lista: ");
        printf("\n\t\t\t\t  7. Verificar se a lista esta vazia: ");
        printf("\n\t\t\t\t  8. Verificar o numero de elementos da lista: ");
        printf("\n\t\t\t\t  9. Soma dos elementos da lista: ");
        printf("\n\t\t\t\t 10. Quantidade de impares da lista: ");
        printf("\n\t\t\t\t 11. Uniao de 2 listas (Principal e Secundaria(Apenas valores positivos))");
        printf("\n\t\t\t\t Obs: A lista secundaria é criada dentro da opcao 11!");
        printf("\n\t\t\t\t 12. Sair. ");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\tDigite o numero referente a opcao desejada: ");
        scanf("%d",&op);

        if(op < 1 || op > 12){
            system("cls");
            printf("\t\t\t---------------------------------------------------------");
            printf("\n\t\t\tOpcao invalida. Tente novamente!\n");
            continue;
        }

        switch (op){
            case 1:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tDigite o valor que voce quer inserir no inicio da lista: ");
                scanf("%d",&v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                L = InsereInicio(L,v);
                printf("\n");
            break;
            case 2:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tDigite o valor que voce quer inserir no final da lista: ");
                scanf("%d",&v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                L = InsereFim(L,v);
                printf("\n");
            break;
            case 3:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                L = ExcluiInicio(L);
                printf("\n");
            break;
            case 4:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                L = ExcluiFim(L);
                printf("\n");
            break;
            case 5:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                Imprime(L);
                printf("\n");
            break;
            case 6:
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
            case 7:
                verifica = ListaVazia(L);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                if (verifica == 1){
                    printf("\n\t\t\tA lista esta vazia!\n");
                }else if(verifica == 0){
                    printf("\n\t\t\tA lista nao esta vazia\n");
                }else{printf("\n\t\t\tErro!");}
            break;
            case 8:
                verifica = nElemenntosLista(L);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tO tamanho da lista eh de %d elementos\n",verifica);
            break;
            case 9:
                verifica = somaLista(L);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tA soma de todos os elementos da lista eh igual a: %d\n",verifica);
            break;
            case 10:
                verifica = nImparesLista(L);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tA quantidade de impares da lista eh: %d\n",verifica);
            break;
            case 11:{
                Lista *L2 = Inicializa();
                v=0;
                while(v >= 0){
                    system("cls");
                    printf("\t\t\t---------------------------------------------------------");
                    printf("\n\t\t\t");
                    Imprime(L2);
                    printf("\n");
                    printf("\t\t\t---------------------------------------------------------");
                    printf("\n\t\t\tDigite o valor que voce quer inserir na lista: \n");
                    printf("\n\t\t\tObs: os valores serao inseridos no inicio \n");
                    printf("\n\t\t\t(Digite um valor negativo para encerrar a lista) \n");
                    printf("\t\t\t");
                    scanf("%d",&v);
                    L2 = InsereInicio(L2,v);
                }
                L2 = ExcluiInicio(L2);

                L = UniaoLista(L,L2);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                Imprime(L);
                printf("\n");

            break;
            }
            case 12:
                sair = 1;
            break;
        }
    }

    return 0;
}

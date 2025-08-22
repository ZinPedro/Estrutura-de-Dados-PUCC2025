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

//INACABADO

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

        return novo;
    }
    system("cls");
    printf("\t\t\t---------------------------------------------------------");
    printf("\n\t\t\tMemoria cheia.");
    return aux;
}

Lista* Exclui (Lista *aux){
    if (aux != NULL){
        Lista *aux2;
        aux2 = aux;
        aux = aux -> prox;
        free(aux2);
        system("cls");
        printf("\t\t\t---------------------------------------------------------");
        printf("\n\t\t\tUltimo elemento da lista excluido!\n");
        return aux;
    }
    system("cls");
    printf("\t\t\t---------------------------------------------------------");
    printf("\n\t\t\tA lista ja esta vazia!\n");
    return aux;
}

void Imprime (Lista *aux){
    if(aux == NULL){

    }else {
        system("cls");
        printf("\t\t\t---------------------------------------------------------");
        printf("\n\t\t\tLista: ");
        while(aux != NULL){
            printf("%d ",aux -> info);
            aux = aux -> prox;
        }
        printf("\n");
    }
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
        
    }
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
                L = Insere(L,v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tValor adcionado com exito!\n");
            break;
            case 2:
                L = Exclui(L);
            break;
            case 3:
                Imprime(L);
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
                
            break;
            case 7:

            break;
            case 8:
                sair = 1;
            break;
        }
    }



    /*Lista *Inicio;
    Inicio = Inicializa();
    Inicio = Insere(Inicio);
    Inicio = Insere(Inicio);
    Inicio = Insere(Inicio);
    Imprime(Inicio);
    Inicio = Exclui(Inicio);
    Imprime(Inicio);
*/

    return 0;
}

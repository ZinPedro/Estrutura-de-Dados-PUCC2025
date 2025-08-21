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

Lista* Insere (Lista *aux){
    int v;
    Lista *novo;

    printf("\nDigite o valor que voce quer inserir na lista: ");
    scanf("%d",&v);

    novo = (Lista*) malloc(sizeof(Lista));
    if(novo != NULL){
        novo -> info = v;
        novo -> prox = aux;
        return novo;
    }
    printf("Memoria cheia.");
    return aux;
}

Lista* Exclui (Lista *aux){
    Lista *aux2;
    aux2 = aux;
    aux = aux -> prox;
    free(aux2);
    printf("\nUltimo elemento da lista excluido!\n");
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
}

int Busca (Lista *aux){
    int v;
    printf("Qual o valor que você quer buscar: ");
    scanf("%d",&v);
    while (aux != NULL){
        if (aux -> info == v){
            printf("O valor existe na lista!");
            return 1;
        }
        aux = aux -> prox;
    }
    printf("O valor não existe na lista!");
    return 0;
}

int main (){
    int op;
    int sair = 0;
    printf("\t\t\t---------------------------------------------------------");
    printf("\n\t\t\t | MENU |");
    printf("\n\t\t\t---------------------------------------------------------");
    printf("\n\t\t\t | Opcoes: ");
    printf("\n\t\t\t\t 1. Inserir valor (inteiro) na lista: ");
    printf("\n\t\t\t\t 2. Remover ultimo valor inserido da lista: ");
    printf("\n\t\t\t\t 2. Imprimir lista: ");
    printf("\n\t\t\t\t 4. Buscar valor na lista: ");
    printf("\n\t\t\t\t 5. Verificar se a lista esta vazia: ");
    printf("\n\t\t\t\t 6. Verificar o numero de elementos da lista: ");
    printf("\n\t\t\t\t 7. Soma dos elementos da lista: ");
    printf("\n\t\t\t\t 8. Sair. ");
    printf("\n\t\t\t---------------------------------------------------------");
    printf("\n\t\t\tDigite o numero referente a opcao desejada: ");
    scanf("%d",op);

    Lista *L;
    L = Inicializa();

    while (sair != 1){
        switch (op){
            case 1:
                L = Insere(L);
            break;
            case 2:
                L = Exclui(L);
            break;
            case 3:
                Imprime(L);
            break;
            case 4:
                Busca(L);
            break;
            case 5:

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
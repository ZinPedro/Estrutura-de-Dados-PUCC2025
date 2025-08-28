#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

//Inacabado

int main (){
        int v=0;
        Pilha *P;

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
        scanf("%d",&v);

        P = CriaPilha();
        Push(P,v);
        Push(P,6);
        Push(P,5);
        printf("\n\t\t\t");
        Imprime(P);

        printf("\n\t\t\t---------------------------------------------------------\n");
        v = Pop(P);
        printf("\n\t\t\t%d",v);
        printf("\n\t\t\t---------------------------------------------------------\n");
        printf("\n\t\t\t");
        Imprime(P);
        printf("\n\t\t\t---------------------------------------------------------\n");
        liberaPilha(P);

}

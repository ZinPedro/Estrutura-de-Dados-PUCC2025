#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
/*
1. Conte os Elementos da Pilha

2. Inverta a Pilha

3. Remova um determinado elemento da pilha, se existir

4. Dado duas pilhas, passadas por parâmetro, retorne qual tem mais elementos. Os valores de retorno serão:
• 0 se as duas pilhas tiverem a mesma quantidade de elementos
• 1 se a pilha 1 tiver mais elementos
• 2 se a pilha 2 tiver mais elementos
O cabeçalho da função deverá ser: int comapara(Lista *p1, Lista *p2)

5. Leia um número inteiro e guarde os seus dígitos numa pilha. O cabeçalho da função deverá ser: Pilha *Digitos(int num)

6. Dado um número inteiro, cujo os seus dígitos estão armazenados numa pilha, imprima o número inteiro
*/
//Inacabado

int ContaPilha (Pilha *p){
    int cnt=0;
    No* aux = p -> Topo;
    while (aux != NULL){
        cnt++;
        aux = aux->prox;
    }
    printf("Numero de elementos da Pilha: %d",cnt);
    return cnt;
}

void InvertePilha (Pilha *p){
    int aux[ContaPilha(p)];
    int i=0;

    while(!vaziaPilha(p)){
        aux[i] = Pop(p);
        i++;
    }
    for(int j = 0; j < i; j++){
        Push(p,aux[j]);
    }

    return;
}

int main (){
        int v=0;
        Pilha *P;

        printf("\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | MENU |");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | Opcoes: ");
        printf("\n\t\t\t\t 1. Numero de elementos da Pilha: ");
        printf("\n\t\t\t\t 2. Inverter a Pilha: ");
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
        Push(P,4);
        Push(P,5);
        Push(P,13);
        Push(P,22);
        Push(P,7);
        Push(P,5);
        Push(P,9);
        Push(P,14);
        printf("\n\t\t\t");
        Imprime(P);
        InvertePilha(P);
        printf("\n\t\t\t");
        Imprime(P);
        printf("\n\t\t\t---------------------------------------------------------\n");
        printf("\n\t\t\t");
        ContaPilha(P);

        printf("\n\t\t\t---------------------------------------------------------\n");
        v = Pop(P);
        printf("\n\t\t\t%d",v);
        printf("\n\t\t\t---------------------------------------------------------\n");
        printf("\n\t\t\t");
        ContaPilha(P);
        printf("\n\t\t\t");
        Imprime(P);
        printf("\n\t\t\t---------------------------------------------------------\n");
        printf("\n\t\t\t");
        liberaPilha(P);


}
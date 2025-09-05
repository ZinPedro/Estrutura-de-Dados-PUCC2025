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
O cabeçalho da função deverá ser: int compara(Lista *p1, Lista *p2)

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
    Pilha *Paux = CriaPilha();
    int i=0;

    while(!vaziaPilha(p)){
        Push(Paux,Pop(p));
        i++;
    }
    p -> Topo = Paux -> Topo;
    free(Paux);
    return;
}

void RemoveElementoPilha(Pilha *P, int v){
    No* aux = p -> Topo;
    while (aux != NULL){
        if(aux -> info == v){
            v = Pop(P);
        }
        aux = aux->prox;
    }
    return;
}

int ComparaPilhas(Lista *p1, Lista *p2){
    int cnt1, cnt2;
    cnt1 = ContaPilha(p1);
    cnt2 = ContaPilha(p2);
    if(cnt1 == cnt2){
        return 0;
    }else if(cnt1 > cnt2){
        return 1;
    }else{
        return 2;
    }
}

int main (){
        int v=0;
        Pilha *P;


while (sair != 1){

        printf("\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | MENU |");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | Opcoes: ");
        printf("\n\t\t\t\t 1. Inserir valor (inteiro) na Pilha: ");
        printf("\n\t\t\t\t 2. Retirar da Pilha: ");
        printf("\n\t\t\t\t 3. Imprimir Pilha: ");
        printf("\n\t\t\t\t 4. Quantidade de elementos da Pilha: ");
        printf("\n\t\t\t\t 5. Inverter a Pilha: ");
        printf("\n\t\t\t\t 6. Remover elemento especifico da Pilha: ");
        printf("\n\t\t\t\t 7. Comparacao do numero de elementos entre 2 Pilhas: ");
        printf("\n\t\t\t\t 8. Separacao dos algarismmos de um número inteiro para Pilha: ");
        printf("\n\t\t\t\t 9. Imprimir numero inteiro com algarismos da Pilha: ");
        printf("\n\t\t\t\t 10. Sair. ");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\tDigite o numero referente a opcao desejada: ");
        scanf("%d",&op);

        if(op < 1 || op > 10){
            system("cls");
            printf("\t\t\t---------------------------------------------------------");
            printf("\n\t\t\tOpcao invalida. Tente novamente!\n");
            continue;
        }

        switch (op){
            case 1:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tDigite o valor que voce quer inserir na Pilha: ");
                scanf("%d",&v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                Push(P,v);
                if(!vaziaPilha(P)){
                    printf("Pilha: ");
                    Imprime(P);
                }
            break;
            case 2:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                v = Pop(P);
                if(!vaziaPilha(P)){
                    printf("Pilha: ");
                    Imprime(P);
                }
            break;
            case 3:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t ");
                if(!vaziaPilha(P)){
                    printf("Pilha: ");
                    Imprime(P);
                }else{
                    printf("Pilha vazia.\n");
                }
            break;
            case 4:
                v = ContaPilha(P);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tA quantidade de numeros na Pilha eh: %d\n",v);
            break;
            case 5:
                InvertePilha(P);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!vaziaPilha(P)){
                    printf("Pilha: ");
                    Imprime(P);
                }else{
                    printf("Pilha vazia.\n");
                }
            break;
            case 6:
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tDigite o valor que voce quer remover da Pilha: ");
                scanf("%d",&v);
                RemoveElementoPilha(P,v)
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!vaziaPilha(P)){
                    printf("Pilha: ");
                    Imprime(P);
                }else{
                    printf("Pilha vazia.\n");
                }
            break;
            //PAREI AQUI (NO 7)
            case 7:{
                Pilha *P2 = CriaPilha();
                v=0;
                while (v >= 0){
                    system("cls");
                    printf("\t\t\t---------------------------------------------------------");
                    printf("\n\t\t\t");
                    if(!vaziaPilha(P2)){
                        printf("Pilha 2: ");
                        Imprime(P2);
                    }else{
                        printf("Pilha 2 vazia.\n");
                    }
                    printf("\t\t\t---------------------------------------------------------");
                    printf("\n\t\t\tDigite os valores que voce quer inserir na segunda Pilha \n(Digite um numero negativo para ir para a proxima pilha)\n ");
                    scanf("%d",&v);
                }
                v = ComparaPilhas(P,P2);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tFila invertida: ");
                imprimeFila(F);
            break;
            }
            case 8:{
                Fila *F2 = CriaFila();
                DivideFila(F,F2);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tFila Par: ");
                imprimeFila(F);
                printf("\t\t\tFila Impar: ");
                imprimeFila(F2);
                liberaFila(F2);
                printf("\t\t\tObs: Continuacao do programa com operacoes na fila Par \n\t\t\t(o programa nao tem o foco de ter a opcao de escolher entre as filas)\n");
            break;
            }
            case 9:{
                Pilha *Pmenor = CriaPilha();
                Pilha *Pmaior = CriaPilha();
                TransformaFilaPilha(F,Pmenor,Pmaior);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tFila: ");
                imprimeFila(F);
                printf("\t\t\tPilha menor ou igual a 20: ");
                Imprime(Pmenor);
                printf("\t\t\tPilha maior que 20: ");
                Imprime(Pmaior);
                liberaPilha(Pmenor);
                liberaPilha(Pmaior);
            break;
            }
            case 10:
                sair = 1;
            break;
        }
    }
    return 0;
}

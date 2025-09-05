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
    Pilha* Paux = CriaPilha();
    int num;
    while (!vaziaPilha(P)){
        num = Pop(P);
        if(num != v){
            Push(Paux,num);
        }
    }
    InvertePilha(Paux);
    P -> Topo = Paux -> Topo;
    free(Paux);
    return;
}

int ComparaPilhas(Pilha *p1, Pilha *p2){
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

Pilha *DigitosPilha(int num){
    Pilha *P = CriaPilha();
    int resto;
    while(num != 0){
        resto = num % 10;
        num = num / 10;
        Push(P,resto);
    }
    return P;
}

int RestauraIntPilha(Pilha *P){
    int v=0,num;
    while(!vaziaPilha(P)){
        v = v*10;
        num = Pop(P);
        v = v + num;
    }
    return v;
}

int main (){
        int v=0,sair=0,op;
        Pilha *P = CriaPilha();
        Pilha *Palg = CriaPilha();


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
        printf("\n\t\t\t\t    (Pilha original do codigo com outra Pilha criada) ");
        printf("\n\t\t\t\t 8. Separacao dos algarismmos de um numero inteiro para Pilha: ");
        printf("\n\t\t\t\t 9. Imprimir numero inteiro com algarismos da Pilha: ");
        printf("\n\t\t\t\t    (Algarismos armazenados na opcao 8)");
        printf("\n\t\t\t\t Obs: Opcoes 8 e 9 nao alteram e nao operam na Pilha Original do programa.");
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
                RemoveElementoPilha(P,v);
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
                    printf("\n\t\t\tDigite os valores que voce quer inserir na segunda Pilha \n\t\t\t(Digite um numero negativo para ir para a proxima pilha)\n ");
                    printf("\t\t\t");
                    scanf("%d",&v);
                    Push(P2,v);
                }
                v = Pop(P2);
                v = ComparaPilhas(P,P2);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                if (v == 0){
                    printf("\n\t\t\tAs 2 Pilhas tem a mesma quantidade de elementos!\n");
                }else if(v == 1){
                    printf("\n\t\t\tA Pilha original tem mais elementos do que a segunda Pilha!\n");
                }else if(v == 2){
                    printf("\n\t\t\tA segunda Pilha tem mais elementos do que a Pilha original!\n");
                }else{printf("\n\t\t\tErro desconhecido!\n");}
                liberaPilha(P2);
            break;
            }
            case 8:{
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tDigite o inteiro para separar e armazenar na Piha:  ");
                scanf("%d",&v);
                Palg = DigitosPilha(v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tPilha: ");
                Imprime(Palg);
            break;
            }
            case 9:{
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                if(!vaziaPilha(Palg)){
                    v = RestauraIntPilha(Palg);
                    printf("\n\t\t\tNumero: %d\n",v);
                }else{
                    printf("\n\t\t\tA pilha esta vazia. Execute a opcao antes de executar esta! %d\n");
                }

            break;
            }
            case 10:
                sair = 1;
            break;
        }
    }
    return 0;
}

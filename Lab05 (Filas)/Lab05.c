#include <stdio.h>
#include <stdlib.h>
#include "BiblioFilaePilha.h"
/*
1. Analise e teste a biblioteca Fila fornecida para você
2. Elabore uma função que conte quantos números pares possui
uma fila e retorne esta quantidade
3. Elabore uma função que apague a informação 15 de uma fila se
ela existir
4. Elabore uma função que dado uma fila, transforme-a em duas
filas uma com os números pares e outra com os ímpares
5. Elabore uma função que inverta uma fila
6. Elabore uma função que recebe uma fila e transforme-a
em duas Filas: uma com os números pares e a outra com
os números ímpares. A fila original deve deixar de existir
7. Elabore uma função que receba uma fila e transforme-a
em duas pilhas: uma pilha com os números maiores que
20 e a outra com os menores iguais a 20

*/

int NParesFila(Fila *F){
    int cnt=0;
    No *aux= F -> ini;
    while(aux != NULL){
        if((aux->info%2) == 0){
            cnt++;
        }
        aux = aux -> prox;
    }
    return cnt;
}
void Apaga15Fila(Fila *F){
    Fila *Faux = CriaFila();
    int x;

    while(!VaziaFila(F)){
        x = RetiraFila(F);
        if(x != 15){
            InsereFila(Faux,x);
        }
    }
    printf("Valor(es) Apagados com sucesso!");
    F -> ini = Faux -> ini;
    F -> fim = Faux -> fim;
    free(Faux);
    return;
}

Fila CriaPareImpar(Fila *F, Fila *Fpar, Fila *Fimpar){
    No *aux = F -> ini;
    while(aux != NULL){
        if ((aux->info%2) == 0){
            InsereFila(Fpar,aux->info);
        }else{
            InsereFila(Fimpar,aux->info);
        }
        aux = aux -> prox;
    }
    return;
}

void DivideFila(Fila *F,Fila *Fimpar){
    Fila *Fpar = CriaFila();
    No *aux = F -> ini;
    int v;

    while(!VaziaFila(F)){
        v = RetiraFila(F);

        if ((v%2) == 0){
            InsereFila(Fpar,v);
        }else{
            InsereFila(Fimpar,v);
            }
    }
    F -> ini = Fpar -> ini;
    F -> fim = Fpar -> fim;
    free(Fpar);

    return;
}

void InverteFila(Fila *F){
    Pilha *Paux = CriaPilha();
    while(!VaziaFila(F)){
        Push(Paux,RetiraFila(F));
    }
    while(!vaziaPilha(Paux)){
        InsereFila(F,Pop(Paux));
    }
    free(Paux);
    return;
}

void TransformaFilaPilha(Fila *F, Pilha *Pmenor, Pilha* Pmaior){
    No *aux = F -> ini;
    while(aux != NULL){
        if(aux -> info <= 20){
            Push(Pmenor,aux->info);
        }else{
            Push(Pmaior,aux->info);
        }
        aux = aux -> prox;
    }
    return;
}





int main (){
    int sair = 0,op = 0, v;
    Fila *F = CriaFila();

    while (sair != 1){

        printf("\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | MENU |");
        printf("\n\t\t\t---------------------------------------------------------");
        printf("\n\t\t\t | Opcoes: ");
        printf("\n\t\t\t\t 1. Inserir valor (inteiro) na fila: ");
        printf("\n\t\t\t\t 2. Retirar da Fila: ");
        printf("\n\t\t\t\t 3. Imprimir fila: ");
        printf("\n\t\t\t\t 4. Buscar quantidade de pares na fila: ");
        printf("\n\t\t\t\t 5. Excluir valor(es) 15 da fila: ");
        printf("\n\t\t\t\t 6. Criacao Fila Par e Fila Impar com base na Fila Original: ");
        printf("\n\t\t\t\t 7. Inverte a fila: ");
        printf("\n\t\t\t\t 8. Divisao de Fila (Fila Par e Fila Impar) (Fila original se perde): ");
        printf("\n\t\t\t\t 9. Transformacao para Pilhas (>20 e <20): ");
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
                printf("\n\t\t\tDigite o valor que voce quer inserir na fila: ");
                scanf("%d",&v);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                InsereFila(F,v);
                if(!VaziaFila(F)){
                    printf("Fila: ");
                    imprimeFila(F);
                }
            break;
            case 2:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                v = RetiraFila(F);
                if(!VaziaFila(F)){
                    printf("Fila: ");
                    imprimeFila(F);
                }
            break;
            case 3:
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t ");
                if(!VaziaFila(F)){
                    printf("Fila: ");
                    imprimeFila(F);
                }else{
                    printf("Fila vazia.\n");
                }
            break;
            case 4:
                v = NParesFila(F);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tA quantidade de numeros pares eh: %d\n",v);
            break;
            case 5:
                Apaga15Fila(F);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\t");
                if(!VaziaFila(F)){
                    printf("Fila: ");
                    imprimeFila(F);
                }else{
                    printf("Fila vazia.\n");
                }
            break;
            case 6: {
                Fila *F2 = CriaFila();
                Fila *F3 = CriaFila();
                CriaPareImpar(F,F2,F3);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tFila Original: ");
                imprimeFila(F);
                printf("\t\t\tFila Par: ");
                imprimeFila(F2);
                printf("\t\t\tFila Impar: ");
                imprimeFila(F3);
                printf("\t\t\tObs: Continuacao do programa com operacoes na Fila Original\n");
            break;
            }
            case 7:
                InverteFila(F);
                system("cls");
                printf("\t\t\t---------------------------------------------------------");
                printf("\n\t\t\tFila invertida: ");
                imprimeFila(F);
            break;
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

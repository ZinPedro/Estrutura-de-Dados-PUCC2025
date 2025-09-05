#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/* FUNÇÕES DE MANIPULAÇÃO DE PILHA

Pilha* CriaPilha ()     CRIA A PILHA

No* ins_ini (No* t, int a)  AUXILIAR DA INSERÇÃO

void push (Pilha* p, int v) INSERÇÃO

No* ret_ini (No* l)         AUXILIAR DA REMOÇÃO

int pop (Pilha* p)          REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO

Pilha* liberaPilha (Pilha* p)      LIBERA A PILHA

void imprime (Pilha* p)     IMPRIMA A PILHA

int vaziaPilha(Pilha *p)	    VERIFICA SE A PILHA ESTÁ VAZIA, RETORNA 1

*/

typedef struct no {
    int info;
    struct no *prox;
}No;

typedef struct Pilha{
    No *Topo;
}Pilha;

Pilha* CriaPilha(void) {
    Pilha *p;
    p = (Pilha*)malloc(sizeof(Pilha));
    p->Topo = NULL;
    return p;
}

No* ins_ini (No* t,int a){
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t;
    return aux;
}

void Push (Pilha* p, int v)
{
    p -> Topo = ins_ini(p->Topo,v);
}

No* ret_ini (No* aux){
    No* p = aux->prox;
    free(aux);
    return p;
}

int Pop (Pilha* p){
    int v;
    if(vaziaPilha(p) == 1){
       printf("A Pilha esta Vazia");
       exit(1);
    }
    v = p->Topo->info;
    p -> Topo = ret_ini(p->Topo);
    return v;
}

Pilha* liberaPilha (Pilha* p){
    if(vaziaPilha(p) == 1){
       printf("A Pilha ja esta Vazia");
       exit(1);
    }
    No* aux;
    aux = p->Topo;
    while (p->Topo != NULL){
        p->Topo = p->Topo->prox;
        free(aux);
        aux = p->Topo;
    }
    free(p);
}

void Imprime (Pilha* p){
    if(vaziaPilha(p) == 1){
       printf("A Pilha esta Vazia");
       return;
    }
    No* aux = p->Topo;
    while (aux != NULL){
        printf("%d - ",aux->info);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

int vaziaPilha(Pilha *p){
    if(p->Topo == NULL){
        return 1;
    }else{
        return 0;
    }
}


#endif // PILHA_H_INCLUDED


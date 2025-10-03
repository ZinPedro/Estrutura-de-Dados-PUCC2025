#ifndef BIBLIOFILAEPILHA_H_INCLUDED
#define BIBLIOFILAEPILHA_H_INCLUDED

typedef struct no {
    int info;
    struct no *prox;
}No;

/* FUN��ES DE MANIPULA��O DE PILHA

Pilha* CriaPilha ()     CRIA A PILHA

No* ins_ini (No* t, int a)  AUXILIAR DA INSER��O

void push (Pilha* p, int v) INSER��O

No* ret_ini (No* l)         AUXILIAR DA REMO��O

int pop (Pilha* p)          REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO

Pilha* liberaPilha (Pilha* p)      LIBERA A PILHA

void imprime (Pilha* p)     IMPRIMA A PILHA

int vaziaPilha(Pilha *p)	    VERIFICA SE A PILHA EST� VAZIA, RETORNA 1

*/

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

/* FUN��ES DE MANIPULA��O DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA EST� VAZIA RETORNA 1 QUANDO EST� VAZIA

void InsereFila (Fila* f, int v) INSER��O

int RetiraFila (Fila* f) REMO��O

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/

typedef struct fila
{
    No * ini;
    No * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

No* ins_fim (No *fim, int A)
{
    No *p = (No*)malloc(sizeof(No));
    p->info = A;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista n�o estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int v)
{
    f->fim = ins_fim(f->fim,v);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

No* retira_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

int RetiraFila (Fila* f)
{
    int v;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        return 0; /* aborta programa */
    }
    v = f->ini->info;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL){ /* fila ficou vazia? */
        f->fim = NULL;
        printf(" Fila vazia.\n");
    }
    return v;
}

void imprimeFila (Fila* f)
{
    No* q;
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("%d - ",q->info);
    }
    printf("\n");
}


Fila* liberaFila (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

#endif // BIBLIOFILAEPILHA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
typedef struct Arvore_AVL
{
      int info;
      struct Arvore_AVL *esq;
      struct Arvore_AVL *dir;
      int FB;
}Avl;

Avl * criaNo(int num)
{
    Avl *p=(Avl*)malloc(sizeof(Avl));
    p->info=num;
    p->dir=NULL;
    p->esq=NULL;
    p->FB=0;
    return p;

}
Avl * rotacionarEsq(Avl *a,int *status)
{
    Avl *b,*c;
    b=a->dir;
    if(b->FB==1)//rota��o simples
    {
        printf("\n\nROTA��O SIMPLES -ESQUERDA \n\n");
        a->dir=b->esq;
        b->esq=a;
        a->FB=0;
        a=b;
    }
    else //rota��o dupla
    {
        printf("\n\nROTA��O DUPLA -ESQUERDA \n\n");
        c=b->esq;
        b->esq=c->dir;
        c->dir=b;
        a->dir=c->esq;
        c->esq=a;
        if(c->FB==1)
        {
            a->FB=-1;
        }
        else
        {
            a->FB=0;
        }
        if(c->FB==-1)
        {
            b->FB=1;
        }
        else
        {
            b->FB=0;
        }
        a=c;
    }
    a->FB=0;
    *status=1;
    return a;
}
Avl * rotacionarDir(Avl *a,int *status)
{
    Avl *b,*c;
    printf("\n Entrou Rota��o direita FB de a =%d",a->FB);
    b=a->esq;
    if(b->FB== -1)//rota��o simples
    {
        printf("\n\nROTA��O SIMPLES -DIREITA \n\n");
        a->esq=b->dir;
        b->dir=a;
        a->FB=0;
        a=b;
    }
    else //rota��o dupla
    {
        printf("\n\nROTA��O DUPLA -DIREITA \n\n");
        printf("\n FB de a =%d",a->FB);
        printf("\n FB de b =%d",b->FB);
        c=b->dir;
        printf("\n FB de c =%d",c->FB);
        b->dir=c->esq;
        c->esq=b;
        a->esq=c->dir;
        c->dir=a;
        if(c->FB== -1)
        {
            a->FB= 1;
        }
        else
        {
            a->FB=0;
        }
        if(c->FB== 1)
        {
            b->FB=-1;
        }
        else
        {
            b->FB=0;
        }
        a=c;
    }
    a->FB=0;
    *status=1;
    printf("\n FB de a =%d no= %d",a->FB,a->info);
    printf("\n FB de b =%d no= %d",b->FB,b->info);
    fflush(stdin);
    getchar();
    return a;
}


void insere(Avl **no, int num, int *status)
{
    if((*no)==NULL)
    {
        *no=criaNo(num);
        *status=0;

    }
    else
    {
        if((*no)->info==num)
        {
            printf("\n\n==> Elemento REPETIDO - TECLE ENTER");
            fflush(stdin);
            getchar();
        }
        else
        {
            if(num < (*no)->info)
            {
                printf("\n insere esquerda:\n\n");
                insere(&(*no)->esq,num,status);
                printf("status = %d\n",*status);
                if(*status==0)//true
                {
                    printf("%d FB = %d\n",(*no)->info,(*no)->FB);
                    switch((*no)->FB)
                    {
                        case 1:
                            (*no)->FB=0;
                              printf("mudou status = %d\n\n",*status);
                            *status=1;//false
                        break;
                        case 0:
                            printf("%d mudou FB para -1\n",(*no)->info);
                            (*no)->FB=-1;
                        break;
                        case -1:
                            printf("\n\n rotacionar direita\n");
                            (*no)=rotacionarDir((*no),status);
                        break;
                    }
                }
            }
          else // num > no->info => direita
          {
                insere(&(*no)->dir,num,status);
                printf("status = %d\n",*status);
                if(*status==0)//true
                {
                    printf("%d FB = %d\n",(*no)->info,(*no)->FB);
                    switch((*no)->FB)
                    {
                        case-1:
                            (*no)->FB=0;
                             printf("mudou status = %d\n\n",*status);
                            *status=1;//false
                        break;
                        case 0:
                            printf("%d mudou FB para 1\n",(*no)->info);
                            (*no)->FB=1;
                        break;
                        case 1:
                            printf("\n\nrotacionar esquerda\n");
                            (*no)=rotacionarEsq((*no),status);
                        break;
                    }
                }
            }
        }
    }
}

void imprimir_in_order(Avl *pai)
{
    if(pai->dir!=NULL)
    {
        imprimir_in_order(pai->dir);
    }
    printf(" %d", pai->info);
    if(pai->esq!=NULL)
    {
        imprimir_in_order(pai->esq);
    }
}

int main()
{
  Avl *raiz=NULL;
  int status=1; //false
  int resp,info,i;


  do
  {
      printf("\nDigite um numero - (0 para sair):");
      scanf("%d",&info);
      insere(&raiz,info,&status);
      printf("\n\n IMPRIMINDO IN ORDER\n");
      imprimir_in_order(raiz);
      printf("\n");

  }while(info!=0);

  printf("\n\n IMPRIMINDO IN ORDER\n");
  imprimir_in_order(raiz);

}

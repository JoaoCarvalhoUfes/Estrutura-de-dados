
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct celula
{
    produto *produto;
    tCelula *prox;
};

struct lista
{
    tCelula *prim;
    tCelula *ult;
};

tLista *criaLista()
{
    tLista *novaLista = (tLista *)malloc(sizeof(tLista));

    novaLista->prim = NULL;
    novaLista->ult = NULL;

    return novaLista;
}

tCelula *criaCelula()
{
    tCelula *novaCelula = (tCelula *)malloc(sizeof(tCelula));

    novaCelula->prox = NULL;

    novaCelula->produto = leProduto();

    return novaCelula;
}

void adicionaCelula(tLista *l, tCelula *c, int local)
{
    tCelula *aux = l->prim;

    while (aux != NULL)
    {
        if (comparaProduto(aux->produto, c->produto))
        {
            printf("Já existe um produto com esse codigo\n");
            return;
        }

        aux = aux->prox;
    }

    if (l->prim == NULL)
    {
        l->ult = c;
        l->prim = c;
    }
    else if (local == 1)
    {
        c->prox = l->prim;
        l->prim = c;
    }
    else if (local == 0)
    {
        l->ult->prox = c;
        l->ult = c;
    }

    return;
}

produto *retiraCelulaChave(tLista *l, int chave)
{
    if (comparaProdutoComId(l->prim->produto, chave) && comparaProdutoComId(l->ult->produto, chave))
    {
        produto *p = l->prim->produto;
        l->prim = NULL;
        l->ult = NULL;
        desalocaCelula(l->prim);

        return p;
    }
    else if (comparaProdutoComId(l->prim->produto, chave))
    {
        produto *p = l->prim->produto;
        tCelula *aux = l->prim->prox;
        desalocaCelula(l->prim);
        l->prim = aux;

        return p;
    }

    tCelula *aux = l->prim->prox;
    tCelula *aux2 = l->prim;

    while (aux != NULL)
    {

        if (comparaProdutoComId(aux->produto, chave))
        {
            produto *p = aux->produto;
            aux2->prox = aux->prox;
            if (aux2->produto == NULL)
                l->ult = aux2;

            desalocaCelula(aux);

            return p;
        }
        aux2 = aux;
        aux = aux->prox;
    }
    printf("não existe produto com esse codigo!!\n");
    return NULL;
}

void desalocaLista(tLista *);

void imprimeLista(tLista *l)
{
    tCelula *aux = l->prim;

    while (aux != NULL)
    {
        imprimeProduto(aux->produto);

        aux = aux->prox;
    }

    return;
}

void desalocaCelula(tCelula *)
{
    return;
}

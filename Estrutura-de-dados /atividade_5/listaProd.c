#include "listaProd.h"
#include <stdio.h>
#include <stdlib.h>

struct listaProd
{
    produto *prod;
    listaProd *prox;
    listaProd *ant;
};

typedef struct listaProd celula;

celula *criaLista()
{
    return NULL;
}

celula *adicionaProd(listaProd *l, produto *p)
{

    celula *novaCelula = (celula *)malloc(sizeof(celula));
    novaCelula->prod = p;
    novaCelula->prox = l;
    novaCelula->ant = NULL;
    if (l != NULL)
        l->ant = novaCelula;
    return novaCelula;
}

void imprimeLista(listaProd *l)
{
    celula *aux = l;

    if (l == NULL)
        return;
    do
    {
        imprimeProduto(aux->prod);
        aux = aux->prox;
    } while (aux != NULL);
}

listaProd *retiraProd(listaProd *l, int chave)
{
    celula *aux = l;

    if (l == NULL)
    {
        printf("produto não existe");
        return l;
    }
    do
    {
        if (comparaProdutoCmId(aux->prod, chave))
        {

            if (aux->ant != NULL && aux->prox == NULL)
                aux->ant->prox = aux->prox;
            else if (aux->ant == NULL && aux->prox != NULL)
            {
                l = aux->prox;
                aux->prox->ant = NULL;
            }
            else if (aux->ant != NULL && aux->prox != NULL)
            {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }

            desalocaProduto(aux->prod);
            aux = NULL;
            free(aux);
            aux = l;
            continue;
        }

        aux = aux->prox;
    } while (aux != NULL);

    return l;
}

void desalocaLista(listaProd *l)
{
    if (l != NULL)
    {
        celula *aux = l;

        if (l == NULL)
            return;
        do
        {
            desalocaProduto(aux->prod);
            aux = aux->prox;
        } while (aux != NULL);
    }
}
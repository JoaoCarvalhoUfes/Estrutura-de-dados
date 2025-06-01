#include "listaProd.h"
#include <stdio.h>

int main()
{

    listaProd *listaP = criaLista();
    listaP = adicionaProd(listaP, leProduto());
    listaP = adicionaProd(listaP, leProduto());
    listaP = adicionaProd(listaP, leProduto());
    listaP = adicionaProd(listaP, leProduto());
    listaP = adicionaProd(listaP, leProduto());
    listaP = adicionaProd(listaP, leProduto());
    listaP = adicionaProd(listaP, leProduto());

    imprimeLista(listaP);
    printf("qual o id do produto que deseja retirar\n");
    int id;
    scanf("%d%*c", &id);
    listaP = retiraProd(listaP, id);

    imprimeLista(listaP);

    desalocaLista(listaP);

    return 0;
}
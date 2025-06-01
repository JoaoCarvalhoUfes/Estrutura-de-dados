#include "lista.h"
#include <stdio.h>

int main()
{

    tLista *lista = criaLista();

    printf("digite os produtos\n");

    tCelula *c1 = criaCelula();
    tCelula *c2 = criaCelula();
    tCelula *c3 = criaCelula();
    tCelula *c4 = criaCelula();
    tCelula *c5 = criaCelula();

    adicionaCelula(lista, c2, 1);
    adicionaCelula(lista, c1, 1);
    adicionaCelula(lista, c3, 0);
    adicionaCelula(lista, c4, 0);
    adicionaCelula(lista, c5, 0);

    imprimeLista(lista);

    printf("Digite o codigo do produto que voce quer retirar\n");
    int codigo;
    scanf(" %d%*c", &codigo);
    produto *p = retiraCelulaChave(lista, codigo);

    imprimeLista(lista);
}
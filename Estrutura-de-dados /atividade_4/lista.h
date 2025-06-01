#ifndef lista_h
#define lista_h
#include "produto.h"

typedef struct lista tLista;
typedef struct celula tCelula;

tLista *criaLista();

tCelula *criaCelula();

void adicionaCelula(tLista *, tCelula *, int local);

produto *retiraCelulaChave(tLista *, int chave);

void desalocaLista(tLista *);

void imprimeLista(tLista *);

void desalocaCelula(tCelula *);

#endif

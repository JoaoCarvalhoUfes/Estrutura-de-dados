#ifndef lista_h
#define lista_h

#include "produto.h"

typedef struct listaProd listaProd;

listaProd *criaLista();
listaProd *adicionaProd(listaProd *, produto *);
void imprimeLista(listaProd *);
listaProd *retiraProd(listaProd *, int chave);
void desalocaLista(listaProd *);

#endif
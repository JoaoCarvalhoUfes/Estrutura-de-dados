#ifndef produto_h
#define produto_h

typedef struct produto produto;

produto *criaProduto();
produto *leProduto();
void imprimeProduto(produto *);
int comparaProdutoCmId(produto *, int);
void desalocaProduto(produto *);

#endif
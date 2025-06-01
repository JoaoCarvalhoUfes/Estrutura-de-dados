#ifndef produto_h
#define produto_h

typedef struct produto produto;

produto *criaProduto();
produto *leProduto();
void imprimeProduto(produto *);
int comparaProduto(produto *, produto *);
int comparaProdutoComId(produto *p1, int id);
void desalocaProduto(produto *);

#endif
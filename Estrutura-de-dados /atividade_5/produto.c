#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    int codigo;
    char* nome;
    float preco;
};

produto *criaProduto()
{
    return (produto *)malloc (sizeof(produto));
}
produto *leProduto()
{
    produto *novoP = criaProduto();
    printf("insira o id do produto:\n");
    int id;

    scanf("%d%*c", &id);

    printf("insira o nome do produto:\n");
    char nome[1000];

    scanf("%[^\n]%*c", nome);

    printf("insira o preco do produto:\n");
    float preco;

    scanf("%f%*c", &preco);
    
    novoP->codigo = id;
    novoP->nome = strdup(nome);
    novoP->preco = preco;

    return novoP;
}
void imprimeProduto(produto *p)
{
    printf("-----------------\n");
    printf("ID: %d\n", p->codigo);
    printf("Nome: %s\n", p->nome);
    printf("preco: %.02f\n", p->preco);
    printf("-----------------\n");

    return;
}

int comparaProdutoCmId(produto *p, int id)
{
    if(p->codigo == id)
        return 1;
    else 
        return 0;
}

void desalocaProduto(produto *p)
{
    if(p != NULL)
    {
        free(p->nome);
        p = NULL;
        free(p);
    }

    return;
}


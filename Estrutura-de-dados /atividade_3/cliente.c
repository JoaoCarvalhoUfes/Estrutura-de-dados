/**
 * Created by Joao Vitor Carvalho on 05/14/25.
 */

#include "matriz.h"
#include <stdio.h>

int main()
{
    printf("insira as dimensões da matriz 1:\n");
    int m, n;
    scanf("%d %d", &m, &n);
    Matriz *A = inicializaMatriz(m, n);

    // lendo os elementos da matriz
    for (int i = 0; i < recuperaNLinhas(A); i++)
    {
        for (int j = 0; j < recuperaNColunas(A); j++)
        {
            int elem;
            scanf("%d", &elem);
            modificaElemento(A, i, j, elem);
        }
        scanf("%*c");
    }

    printf("insira as dimensões da matriz 2:\n");

    scanf("%d %d", &m, &n);
    Matriz *B = inicializaMatriz(m, n);

    // lendo os elementos da matriz
    for (int i = 0; i < recuperaNLinhas(B); i++)
    {
        for (int j = 0; j < recuperaNColunas(B); j++)
        {
            int elem;
            scanf("%d", &elem);
            modificaElemento(B, i, j, elem);
        }
        scanf("%*c");
    }

    Matriz *At = transposta(A);

    Matriz *Bt = transposta(B);

    printf("primeira matriz:\n");
    imprimeMatriz(A);
    printf("transposta da primeira matriz:\n");
    imprimeMatriz(At);

    printf("transposta da segunda matriz:\n");
    imprimeMatriz(B);
    printf("transposta da segunda matriz:\n");
    imprimeMatriz(Bt);

    Matriz *multi = multiplicacao(A, B);

    printf("imprimindo o produto da primeira com a segunda matriz:\n");
    imprimeMatriz(multi);

    printf("primeira linha da primeira matriz:\n");
    imprimeLinha(A, 0);

    destroiMatriz(A);
    destroiMatriz(At);
    destroiMatriz(multi);

    return 0;
}
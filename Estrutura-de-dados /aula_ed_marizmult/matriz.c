
/**
 * matriz.c
 * TADmatriz
 *
 * Created by Joao Vitor Carvalho on 05/14/25.
 */
#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

struct matriz
{
    int *mat;
    int l;
    int c;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{
    Matriz *novaMatriz = (Matriz *)malloc(sizeof(Matriz));

    novaMatriz->c = ncolunas;
    novaMatriz->l = nlinhas;

    novaMatriz->mat = (int *)malloc(novaMatriz->c * novaMatriz->l * sizeof(int));

    for (int i = 0; i < novaMatriz->l; i++)
        for (int j = 0; j < novaMatriz->c; j++)
            novaMatriz->mat[i * novaMatriz->c + j] = 0;

    return novaMatriz;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
    mat->mat[linha * mat->c + coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz *mat, int linha, int coluna)
{
    return mat->mat[linha * mat->c + coluna];
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas(Matriz *mat)
{
    return mat->c;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas(Matriz *mat)
{
    return mat->l;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz *transposta(Matriz *mat)
{
    Matriz *transp = inicializaMatriz(mat->c, mat->l);

    for (int i = 0; i < mat->l; i++)
    {
        for (int j = 0; j < mat->c; j++)
            modificaElemento(transp, j, i, recuperaElemento(mat, i, j));
    }
    return transp;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{

    if (mat1->c != mat2->l)
    {
        printf("multiplicação inválida");
        exit(1);
    }
    Matriz *produto = inicializaMatriz(mat1->l, mat2->c);

    for (int i = 0; i < produto->l; i++)
    {

        for (int j = 0; j < produto->c; j++)
        {
            int soma = 0;
            for (int k = 0; k < mat1->c; k++)
            {
                soma += recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j);
            }
            modificaElemento(produto, i, j, soma);
        }
    }

    return produto;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz *mat)
{
    printf("\n");
    for (int i = 0; i < mat->l; i++)
    {
        printf("\t");
        for (int j = 0; j < mat->c; j++)
            printf("%d ", mat->mat[i * mat->c + j]);
        printf("\n");
    }
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha(Matriz *mat, int indice)
{
    if (indice > mat->l)
    {
        printf("indice maior que n de linhas");
        return;
    }
    for (int j = 0; j < mat->c; j++)
    {
        printf("%d ", mat->mat[mat->c + j]);
        printf("\n");
    }

    return;
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz(Matriz *mat)
{
    if (mat != NULL)
    {
        if (mat->mat != NULL)
        {
            free(mat->mat);
            mat->mat = NULL;
        }
        free(mat);
        mat = NULL;
    }
}

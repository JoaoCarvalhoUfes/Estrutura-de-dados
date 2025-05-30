#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415

void calc_esfera(float r, float *area, float *volume);

void raizes(float a, float b, float c, float *x1, float *x2);

int pares(int n, int *vet);

void inverte(int n, int *vet);

double avalia(double *poli, int grau, double x);

int main()
{
    float r, area, volume;
    printf("qual é o raio da esfera?\n");
    scanf("%f%*c", &r);

    calc_esfera(r, &area, &volume);
    printf("A esfera tem %.02f de area e %.02f de volume\n", area, volume);

    printf("escreva valores para a, b e c de uma função\n");
    float a, b, c, x1, x2;
    scanf("%f %f %f%*c", &a, &b, &c);

    raizes(a, b, c, &x1, &x2);
    printf("As raizes da função são %.02f e %.02f\n", x1, x2);

    printf("escreva um vetor de numeros inteiros (numero-enter-numero-enter...) quando parar digite alguma letra\n");
    int i = 0, cap = 10, n = 0;
    int *vetor = (int *)malloc(cap * sizeof(int));
    while (scanf("%d%*c", &vetor[i]) == 1)
    {
        n++;
        i++;
        if (n == cap - 1)
        {
            cap *= 2;
            vetor = (int *)realloc(vetor, cap * sizeof(int));
        }
    }
    scanf("%*c");

    printf("o vetor tem %d numeros pares\n", pares(n, vetor));

    inverte(n, vetor);

    printf("o primeiro numero no vetor invertido é %d e o ultimo é %d\n", vetor[0], vetor[n - 1]);

    double *poli;
    int grau;
    double x;

    printf("digite qual é o grau e o valor de x para a avaliação de polinomio\n");
    scanf("%d %lf", &grau, &x);

    poli = (double *)malloc((grau + 1) * sizeof(double));

    printf("digite o valor para cada elemento do polinomio(começando pelo de menor grau)\n");

    for (int j = 0; j <= grau; j++)
        scanf("%lf%*c", &poli[j]);

    printf("polinomio tem avaliação = %.02lf\n", avalia(poli, grau, x));
    free(poli);
    free(vetor);
}

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * pi * r * r;
    *volume = 4 * pi * r * r * r / 3;

    return;
}

void raizes(float a, float b, float c, float *x1, float *x2)
{
    float delta = pow(b, 2) - 4 * c * a;

    if (delta < 0)
    {
        *x1 = *x2 = 0;
        printf("A equação não possui raízes reais.\n");
        return;
    }
    *x1 = (-1 * b - sqrt(delta)) / (2 * a);
    *x2 = (-1 * b + sqrt(delta)) / (2 * a);

    return;
}

int pares(int n, int *vet)
{
    int pares = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(vet[i] % 2))
        {
            pares++;
        }
    }

    return pares;
}

void inverte(int n, int *vet)
{
    int vetAux[n];

    for (int i = 0; i < n; i++)
        vetAux[i] = vet[n - i - 1];

    for (int i = 0; i < n; i++)
        vet[i] = vetAux[i];

    return;
}

double avalia(double *poli, int grau, double x)
{
    double valor = 0;
    for (int i = 0; i <= grau; i++)
        valor += pow(x, i) * poli[i];

    return valor;
}
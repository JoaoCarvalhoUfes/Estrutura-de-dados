#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define pi 3.1415

void calc_esfera(float r, float *area, float *volume);

int raizes(float a, float b, float c, float *x1, float *x2);

int pares(int n, int *vet);

void inverte(int n, int *vet);

double avalia(double *poli, int grau, double x);

int main()
{
}

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * pi * r * r;
    *volume = 4 * pi * r * r * r / 3;

    return;
}

int raizes(float a, float b, float c, float *x1, float *x2)
{
    float delta = pow(b, 2) - 4*c*a;
    *x1 = (-1*b - sqrt(delta))/2*a;
    *x2 = (-1*b + sqrt(delta))/2*a;

    return;
}

int pares(int n, int *vet)
{
    int pares = 0;
    for(int i; i < n; i++)
        if(!vet[i]%2)
            pares++;

    return pares;
}

void inverte(int n, int *vet)
{
    int vetAux[n];
    
    for(int i; i < n; i++)
        vetAux[i] =vet[n-i-1]

    for(int i; i < n; i++)
        vet[i] = vetAux = [i];

return;
}

double avalia(double *poli, int grau, double x)
{
    double valor = 0;
   for(int i; i <= grau; i++)
        valor = pow(x, grau-i) * poli[grau-i];

    return;
}
#include <stdio.h>
#include <stdlib.h>

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
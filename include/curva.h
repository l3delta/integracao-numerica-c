#ifndef CURVA_H
#define CURVA_H

#include "intervalo.h"

typedef double (*Funcao)(double x);

typedef struct {
    Funcao funcao;
    Intervalo I;
} Curva;

double comprimento_curva(Curva C, int n);
double area_curva_por_retangulos(Curva C, int n);
double area_curva_por_trapezios(Curva C, int n);
double volume_solido_revolucao(Curva, int n);

#endif

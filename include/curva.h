#ifndef CURVA_H
#define CURVA_H

#include "intervalo.h"

typedef double (*Funcao)(double x);

typedef struct {
    Funcao funcao;
    Intervalo I;
} Curva;

/* 
 * Aproxima o comprimento da curva y = f(x) no intervalo [a,b]
 * usando uma aproximação poligonal com n subintervalos.
 */
double comprimento_curva(Curva C, int n);

/*
 * Aproxima a integral definida ∫_a^b f(x) dx
 * pelo método dos trapézios, com n subintervalos.
 */
double integral_definida_por_retangulos_esquerda(Curva C, int n);
double integral_definida_por_trapezios(Curva C, int n);

double volume_solido_revolucao(Curva, int n);

#endif

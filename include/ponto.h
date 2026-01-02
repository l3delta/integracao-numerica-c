#ifndef PONTO_H
#define PONTO_H

typedef struct {
    double x;
    double y;
} Ponto;

double distancia_entre_pontos(Ponto A, Ponto B);

#endif

#include <ponto.h>
#include <math.h>

double distancia_entre_pontos(Ponto A, Ponto B){
    return hypot(A.x - B.x, A.y - B.y);
}

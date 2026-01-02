#include <stdio.h>
#include "curva.h"
#include "math.h"
#include "constantes.h"

double f(double x){
    return sqrt(1-x*x);
}

int main(void) {

    Intervalo I = {-1,1};
    Curva C = {f,I};
    int n = 10000000;

    double a = comprimento_curva(C, n);
    //double b = area_curva_por_trapezios(C, n);
    //double c = volume_solido_revolucao(C, n);

    printf("Comprimento com %d subdivisões: %.10f. \n", n, a);
    printf("Aproximação para pi: %.10f. \n", PI);
    //printf("Área com %d trapézio: %.5f \n", n, b);
    //printf("Volume do sólido de revolução com %d troncos de cone: %.5f \n", n, c);

    return 0;
}

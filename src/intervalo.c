#include "intervalo.h"
#include <math.h>

double comprimento_intervalo(Intervalo I){
    return fabs(I.a - I.b);
}

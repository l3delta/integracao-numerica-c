#include "curva.h"
#include "ponto.h"
#include <math.h>
#include "constantes.h"

double comprimento_curva(Curva C, int n){
    
    double comprimento = 0.0;
    double dx = comprimento_intervalo(C.I)/(double) n;

    double x0, x1;
    x0 = C.I.a;

    for(int i = 0; i < n; i++){
        
        x1 = x0 + dx;
       
        if(i == n-1){
            x1 = C.I.b;
        } 

        Ponto P1 = {x0, C.funcao(x0)};      
        Ponto P2 = {x1, C.funcao(x1)};
        double d = distancia_entre_pontos(P1,P2);
        
        x0 = x1; 
        comprimento += d;
    }
    return comprimento;
}

double area_curva_por_retangulos(Curva C, int n){
     
    double area = 0.0;
    double dx = comprimento_intervalo(C.I)/(double) n;
   
    double x = C.I.a;
   
    for(int i = 0; i < n; i++){        
        double h = C.funcao(x);
        area += h*dx;
        x += dx;
    }
    return area;
}

double area_curva_por_trapezios(Curva C, int n){
    
    double area = 0.0;
    double dx = comprimento_intervalo(C.I)/(double) n;
   
    double x0, x1, b, B;
    x0 = C.I.a;
    b = C.funcao(x0);
    
    for(int i = 0; i < n; i++){        
        x1 = x0 + dx;
        B = C.funcao(x1);

        area += ((b+B)*dx)/2.0;
        x0 = x1;
        b = B;
    }

    return area;
}

double volume_solido_revolucao(Curva C, int n){

    double volume = 0.0;
    double dx = comprimento_intervalo(C.I)/(double) n;

    double x0, x1, r0, r1;
    x0 = C.I.a;
    r0 = fabs(C.funcao(x0));

    for(int i = 0; i < n; i++){
        x1 = x0+dx;
        r1 = fabs(C.funcao(x1));
        volume += (PI*dx/3.0)*(r0*r0+ r0*r1 + r1*r1);
        x0 = x1;
        r0 = r1;
    }

    return volume;
}

#include "curva.h"
#include "ponto.h"
#include <math.h>
#include "constantes.h"

double comprimento_curva(Curva C, int n){
   
    if(n <= 0){
        return NAN;
    } 
 
    if(!C.funcao){
        return NAN;
    }
  
    double comprimento = 0.0;
    double dx = (C.I.b - C.I.a)/(double) n;

    double x0, x1, y0, y1;
    
    x0 = C.I.a;
    y0 = C.funcao(x0);

    for(int i = 0; i < n; i++){
        
        x1 = x0 + dx;
       
        if(i == n-1){
            x1 = C.I.b;
        }
        y1 = C.funcao(x1);

        Ponto P1 = {x0, y0};      
        Ponto P2 = {x1, y1};
        double d = distancia_entre_pontos(P1,P2);
        
        x0 = x1;
        y0 = y1;
        comprimento += d;
    }
    return comprimento;
}

double integral_definida_por_retangulos_esquerda(Curva C, int n){
   
    if(n <= 0){
        return NAN;
    }
   
    if(!C.funcao){
        return NAN;
    }

    double area = 0.0;
    double dx = (C.I.b - C.I.a)/(double) n;
   
    for(int i = 0; i < n; i++){        
        double x = C.I.a + i*dx;
        double h = C.funcao(x);
        area += h*dx;
    }
    return area;
}

double integral_definida_por_trapezios(Curva C, int n){

    if(n <= 0){
        return NAN;
    }
     
    if(!C.funcao){
        return NAN;
    }

    double area = 0.0;
    double dx = (C.I.b - C.I.a)/(double) n;
   
    double x0, x1, b, B;
    x0 = C.I.a;
    b = C.funcao(x0);
    
    for(int i = 0; i < n; i++){
        
        x1 = x0 + dx;
        double h = dx;

        if(i == n-1){ 
            x1 = C.I.b;
            h = x1 - x0;
        }

        B = C.funcao(x1);

        area += ((b+B)*h)/2.0;
        x0 = x1;
        b = B;
    }

    return area;
}

double volume_solido_revolucao(Curva C, int n){

    if(n <= 0){
        return NAN;
    }
     
    if(!C.funcao){
        return NAN;
    }

    double volume = 0.0;
    double dx = (C.I.b - C.I.a)/(double) n;

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

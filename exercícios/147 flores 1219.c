#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

double area(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double rCInscrito(double area, double a, double b, double c) {
    return (2.0 * area) / (a + b + c);
}

double rCCircunscrito(double area, double a, double b, double c) {
    return (a * b * c) / (4.0 * area);
}

int main() {
    double a, b, c;
    
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double areaTri = area(a, b, c);
        
        double rInscrito = rCInscrito(areaTri, a, b, c);
        double areaInscrito = PI * rInscrito * rInscrito;
        
        double rCircunscrito = rCCircunscrito(areaTri, a, b, c);
        double areaCircunscrito = PI * rCircunscrito * rCircunscrito;
        
        double areaGirassois = areaCircunscrito - areaTri;
        double areaVioletas = areaTri - areaInscrito;
        double areaRosas = areaInscrito;
        
        printf("%.4lf %.4lf %.4lf\n", areaGirassois, areaVioletas, areaRosas);
    }
    
    return 0;
}

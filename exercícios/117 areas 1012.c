#include <stdio.h>

int main(void){
    double A, B, C;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
    
    printf("TRIANGULO: %.3lf\n", (A*C)/2);
    printf("CIRCULO: %.3lf\n", 3.14159*C*C);
    double area = ((A+B)*C)/2;
    printf("TRAPEZIO: %.3lf\n", area);
    printf("QUADRADO: %.3lf\n", B*B);
    printf("RETANGULO: %.3lf\n", A*B);
    
    return 0;
}

//Enzo Baldinotti Ravanelli//
#include <stdio.h>

int main(){
    int n1, n2, x1, x2;
    double valor1, valor2, total1, total2;
    
    scanf("%d %d", &n1, &x1);
    scanf("%lf", &valor1);
    scanf("%d %d", &n2, &x2);   
    scanf("%lf", &valor2);

    total1 = x1*valor1;
    total2 = x2*valor2;
    
    printf("VALOR A PAGAR: R$ %.2lf\n", total1+total2);

    return 0;
    
}

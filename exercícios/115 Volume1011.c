//Enzo Baldinotti Ravanelli//
#include <stdio.h>

int main(){
    double n;
    scanf("%lf",&n);
    double cubo = n *n *n;
    double vol =(4.0/3.0) * 3.14159 * cubo;
    printf("VOLUME = %.3lf\n", vol);

    return 0;
}

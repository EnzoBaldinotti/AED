//Enzo Baldinotti Ravanelli
#include <stdio.h>

int pot(int base, int exp){
    
    int resultado = 1;
    for (int i = 0; i < exp; i++) {
        resultado = resultado * base;
    }
    return resultado;
}

int main() {
    int x, n;

    scanf("%d", &x);

    for (int i = 0; i < x; i++){
        scanf("%d", &n);
        printf("%d\n", pot(2, n) - 1);
    }

    return 0;
}

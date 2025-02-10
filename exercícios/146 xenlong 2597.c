#include <stdio.h>
#include <math.h>

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        scanf("%d", &N); 
        
        int quadrados = (int)sqrt(N);
        int resultado = N - quadrados; 
        printf("%d\n", resultado);
    }

    return 0;
}

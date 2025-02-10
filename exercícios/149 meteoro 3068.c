#include <stdio.h>

int main() {
    int X1, Y1, X2, Y2, N, x, y;
    int caso = 1;

    while (1) {
        
        scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
        
        if (X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0) {
            break;
        }

        scanf("%d", &N);
        
        int dentro = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);

            if (x >= X1 && x <= X2 && y <= Y1 && y >= Y2) {
                dentro++;
            }
        }

    
        printf("Teste %d\n%d\n", caso, dentro);
        caso++;
    }

    return 0;
}

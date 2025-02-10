#include <stdio.h>
#include <math.h>

double distancia(int x1, int y1, int x2, int y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(){
    int C;
    scanf("%d", &C);

    while (C--) {
        int N, Xw, Yw;
        scanf("%d", &N);

        scanf("%d %d", &Xw, &Yw); 

        int bola_mais_proxima = 1;
        double menor = 1e9;
        for (int i = 1; i <= N; i++){
            int Xb, Yb;
            scanf("%d %d", &Xb, &Yb);

            double d = distancia(Xw, Yw, Xb, Yb);

            if (d < menor){
                menor = d;
                bola_mais_proxima = i;
            }
        }
        printf("%d\n", bola_mais_proxima);
    }

    return 0;
}

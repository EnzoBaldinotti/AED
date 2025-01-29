//Enzo Baldinotti Ravanelli
#include <stdio.h>

int main() {
    int t, pa, pb, anos;
    double g1, g2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
        anos = 0;

        while (pa <= pb) {
            pa += (int)(pa * (g1 / 100));
            pb += (int)(pb * (g2 / 100));
            anos++;

            if (anos > 100) {
                printf("Mais de 1 seculo.\n");
                break;
            }
        }

        if (anos <= 100) {
            printf("%d anos.\n", anos);
        }
    }

    return 0;
}

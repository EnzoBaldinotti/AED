#include <stdio.h>

#define max 1000

void insert(int campo[max][max], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            scanf("%d", &campo[i][k]);
        }
    }
}

int main() {
    int n, m;
    int campo[max][max];
    scanf("%d %d", &n, &m);

    insert(campo, n, m);

    for (int i = 1; i < n - 1; i++) {
        for (int k = 1; k < m - 1; k++) {
            if (campo[i][k] == 42 &&
                campo[i - 1][k] == 7 &&
                campo[i - 1][k - 1] == 7 &&
                campo[i - 1][k + 1] == 7 &&
                campo[i][k - 1] == 7 &&
                campo[i][k + 1] == 7 &&
                campo[i + 1][k - 1] == 7 &&
                campo[i + 1][k] == 7 &&
                campo[i + 1][k + 1] == 7) {

                printf("%d %d\n", i + 1, k + 1);
                return 0;
            }
        }
    }

    printf("0 0\n");
    return 0;
}

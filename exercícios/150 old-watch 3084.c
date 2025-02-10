#include <stdio.h>

int main() {
    int h, m;

    while (scanf("%d %d", &h, &m) != EOF) {
        int horas = h / 30;   
        int minutos = m / 6;     

        printf("%02d:%02d\n", horas, minutos);
    }

    return 0;
}

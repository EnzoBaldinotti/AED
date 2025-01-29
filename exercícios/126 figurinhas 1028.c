//Enzo Baldinotti Ravanelli

#include <stdio.h>

int mdc(int x, int y) {
    while (y != 0) {
        int aux = y;
        y = x % y;
        x = aux;
    }
    return x;
}


int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        int n1, n2;
        scanf("%d %d", &n1, &n2);

        printf("%d\n", mdc(n1, n2));
    }
    return 0;
}

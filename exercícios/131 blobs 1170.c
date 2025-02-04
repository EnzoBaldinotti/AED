#include <stdio.h>
#include <math.h>

int logg(double C){
    
    int dias = 0;
    while (C > 1){ 
        C /= 2;
        dias++;
    }

    return dias;
}

int main(){
    double C;
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lf", &C);
        printf("%d dias\n", logg(C));
    }

    return 0;
}

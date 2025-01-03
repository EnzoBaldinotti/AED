//Enzo Baldinotti Ravanelli// RA:176265
#include <stdio.h>

int main(){
    double n, m;
    char nome[21];
    
    scanf("%s", nome);

    scanf("%lf", &n);
    scanf("%lf", &m);

    double total = n + (m * 0.15);
    
    printf("TOTAL = R$ %.2lf", total);
    printf("\n");

    return 0;
}   

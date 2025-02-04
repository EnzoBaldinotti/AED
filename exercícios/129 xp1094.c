#include <stdio.h>

int main(){
    int N, quant, total = 0, coelhos = 0, ratos = 0, sapos = 0;
    char tipo;
    
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++){
        scanf("%d %c", &quant, &tipo);
        
        total += quant;
        if (tipo == 'C') coelhos += quant;
        else if (tipo == 'R') ratos += quant;
        else if (tipo == 'S') sapos += quant;   
    }
    
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", (coelhos * 100.0) / total);
    printf("Percentual de ratos: %.2f %%\n", (ratos * 100.0) / total);
    printf("Percentual de sapos: %.2f %%\n", (sapos * 100.0) / total);
    
    return 0;
}

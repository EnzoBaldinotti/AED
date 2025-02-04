#include <stdio.h>
#include <string.h>
#define max 101

int main(){
    char v[max];
    int N, resposta;
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    scanf("%d\n", &N);

    for(int i = 0; i < N; ++i){
        scanf("%s", &v);

        resposta = 0;
        int tamanho = strlen(v);
        for(int j = 0; j < tamanho ; j++){
            resposta += leds[v[j] - '0'];
        }

        printf("%d leds\n", resposta);
    }

    return 0;
}

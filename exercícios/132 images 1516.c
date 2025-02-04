#include <stdio.h>

int main() {
    int N, M, A, B;
    char imagem[50][50];
    
    scanf("%d %d", &N, &M);
    while (N && M) {
        for (int i = 0; i < N; i++) {
            scanf("%s", imagem[i]);
        }
        
        scanf("%d %d", &A, &B);
        
        int linha = A / N;
        int coluna = B / M;
        
        for (int i = 0; i < N; i++) {
            for (int r = 0; r < linha; r++) {
                for (int j = 0; j < M; j++) {
                    for (int c = 0; c < coluna; c++) {
                        printf("%c", imagem[i][j]);
                    }
                }
                printf("\n");
            }
        }
        printf("\n");
        
        scanf("%d %d", &N, &M);
    }
    
    return 0;
}

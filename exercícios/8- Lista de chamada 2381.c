//Enzo Baldinotti Ravanelli 
#include <stdio.h>
#include <string.h>

#define MAX 100
#define ALUN 22

void ordenar(char nome1[ALUN], char nome2[ALUN]) {
    char intermediario[ALUN];
    if (strcmp(nome1, nome2) > 0) {
        strcpy(intermediario, nome1);
        strcpy(nome1, nome2);
        strcpy(nome2, intermediario);
    }
}

int main() {
    char nome[MAX][ALUN];
    int n, k;
 
    scanf("%d %d", &n, &k);
    getchar(); 

    // Leitura dos nomes
    for (int i = 0 ; i < n ; i++) {
        fgets(nome[i], ALUN, stdin);
        int tamanho = strlen(nome[i]);

        if (nome[i][tamanho - 1] == '\n') {
            nome[i][tamanho - 1] = '\0';
        }
        
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ordenar(nome[i], nome[j]);
        }
    }
    
    printf("%s\n", nome[k - 1]);

    return 0;
}

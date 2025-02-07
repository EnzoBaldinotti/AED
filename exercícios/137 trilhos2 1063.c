#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char conteudo;
    struct celula *next;
} celula;

void push(celula **topo, char c) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = c;
    nova->next = *topo;
    *topo = nova;
}

char pop(celula **topo) {
    if (*topo == NULL) return '\0';
    celula *temp = *topo;
    char valor = temp->conteudo;
    *topo = temp->next;
    free(temp);
    return valor;
}

char peek(celula *top) {
    if (top == NULL) {
        return '\0'; 
    } else {
        return top->conteudo;  
    }
}

int vazia(celula *top) {
    return top == NULL;
}

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        char entrada[27], saida[27];  
        
        
        for (int i = 0; i < n; i++) {
            scanf(" %c", &entrada[i]);
        }
        entrada[n] = '\0';

        
        for (int i = 0; i < n; i++) {
            scanf(" %c", &saida[i]);
        }
        saida[n] = '\0';

        celula *stack = NULL;
        char movimentos[2 * n + 1];  
        int mov = 0;
        int entrada_idx = 0, saida_idx = 0;
        int impossivel = 0;

        while (saida_idx < n) {
        
            if (!vazia(stack) && peek(stack) == saida[saida_idx]) {
                pop(&stack);
                movimentos[mov++] = 'R';
                saida_idx++;
            } 
            
            else if (entrada_idx < n) {
                push(&stack, entrada[entrada_idx++]);
                movimentos[mov++] = 'I';
            } 
            
            else {
                impossivel = 1;
                break;
            }
        }

        movimentos[mov] = '\0';

        if (impossivel) {
            printf("%s Impossible\n", movimentos);
        } else {
            printf("%s\n", movimentos);
        }
    }

    return 0;
}

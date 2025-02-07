#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int conteudo;
    struct celula *next;
} celula;

void push(celula **topo, int n) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = n;
    nova->next = *topo;
    *topo = nova;
}

int pop(celula **topo) {
    if (*topo == NULL) {
        return -1;
    }
    celula *temp = *topo;
    int valor = temp->conteudo;
    *topo = temp->next;
    free(temp);
    return valor;
}

int peek(celula *top) {
    if (top != NULL) {
        return top->conteudo;
    } else {
        return -1;
    }
}

int vazia(celula *top) {
    return top == NULL;
}

int main() {
    int n;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            int *target = malloc(n * sizeof(int));
            celula *stack = NULL;

            scanf("%d", &target[0]);
            if (target[0] == 0) { 
                printf("\n");
                free(target);
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &target[i]);
            }

            int train = 1, valido = 1, termo = 0;

            while (termo < n) {
                while (train <= target[termo]) {
                    push(&stack, train++);
                }

                if (!vazia(stack) && peek(stack) == target[termo]) {
                    pop(&stack);
                    termo++;
                } else if (!vazia(stack) && peek(stack) > target[termo]) {
                    valido = 0;
                    break;
                } else {
                    valido = 0;
                    break;
                }
            }

            if (valido) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            while (!vazia(stack)) {
                pop(&stack);
            }

            free(target);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int conteudo;
    struct lista *next;
} celula;

void push(int n, celula **p) {
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = n;
    nova->next = NULL;

    if (*p == NULL) {
        *p = nova;
    } else {
        celula *atual = *p;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = nova;
    }
}

void print(celula **lista, int m) {
    for (int i = 0; i < m; i++) {
        printf("%d ->", i);
        celula *atual = lista[i];
        while (atual != NULL) {
            printf(" %d ->", atual->conteudo);
            atual = atual->next;
        }
        printf(" \\");
        if(i < m -1){
            printf("\n");
        }
    }
}

void liberar(celula **lista, int m) {
    for (int i = 0; i < m; i++) {
        celula *atual = lista[i];
        while (atual != NULL) {
            celula *temp = atual;
            atual = atual->next;
            free(temp);
        }
    }
}

int main(void) {
    int n, m, c;

    scanf("%d", &n);  
    

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &c);  
        
        celula **lista = malloc(m * sizeof(celula *));
        for (int j = 0; j < m; j++) {
            lista[j] = NULL;
        }

       
        for (int k = 0; k < c; k++) {
            int values;
            scanf("%d", &values);
            
            int h = values % m;  
            push(values, &lista[h]);
        }

        print(lista, m);
        liberar(lista, m);
        free(lista);

        if (i < n - 1) {
            printf("\n\n");
        }else{
            printf("\n");
        }
    }

    return 0;
}

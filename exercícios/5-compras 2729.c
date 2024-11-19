//Enzo Baldinotti Ravanelli RA:176265//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 21

typedef struct No {
    char item[MAX_NAME];
    struct No *proximo;
} No;

No* criarNo(char item[MAX_NAME]) {
    No* novoNo = (No*)malloc(sizeof(No));
    strncpy(novoNo->item, item, MAX_NAME - 1);
    novoNo->item[MAX_NAME - 1] = '\0'; // Garante que a string termina corretamente
    novoNo->proximo = NULL;
    return novoNo;
}

void removerLista(No *head) {
    No *atual = head->proximo;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    head->proximo = NULL;
}

void printLista(No *head) {
    No *atual = head->proximo;
    bool primeiro = true;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%s", atual->item);
        primeiro = false;
        atual = atual->proximo;
    }
    printf("\n");
}

bool itemUnico(No *head, char item[MAX_NAME]) {
    No *atual = head;
    while (atual != NULL) {
        if (strcmp(atual->item, item) == 0)
            return false;
        atual = atual->proximo;
    }
    return true;
}

void inserirOrdenado(No **head, char item[MAX_NAME]) {
    No *novoNo = criarNo(item);
    No *atual = *head;
    No *anterior = NULL;

    while (atual != NULL && strcmp(atual->item, item) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && strcmp(atual->item, item) == 0) {
        free(novoNo);
        return; // Item já existe, não adiciona duplicata
    }

    if (anterior == NULL) {
        novoNo->proximo = *head;
        *head = novoNo;
    } else {
        anterior->proximo = novoNo;
        novoNo->proximo = atual;
    }
}

int main() {
    int n;

    No head;
    strcpy(head.item, "Head");
    head.proximo = NULL;

    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    getchar();
    for (int i = 0; i < n; i++) {
        char linha[21000] = {0};
        fgets(linha, sizeof(linha) - 1, stdin);
        int linhaTamanho = strlen(linha);
        int contadorPalavra = 0;
        removerLista(&head);

        for (int j = 0; j < linhaTamanho; j++) {
            if (linha[j] == ' ' || linha[j] == '\0' || linha[j] == '\n') {
                if (contadorPalavra > 0) {
                    char palavra[MAX_NAME] = {0};
                    for (int z = 0; z < contadorPalavra; z++) {
                        palavra[z] = linha[j - contadorPalavra + z];
                    }
                    palavra[contadorPalavra] = '\0';
                    if (itemUnico(&head, palavra)) {
                        inserirOrdenado(&head.proximo, palavra);
                    }
                    contadorPalavra = 0;
                }
            } else {
                contadorPalavra++;
            }
        }
        printLista(&head);
    }

    return 0;
}

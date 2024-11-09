#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 50

typedef struct No {
    char nome[TAMANHO];
    struct No *proximo;
} No;


No* criar_no(char* nome) {
    No* novo_no = (No*)malloc(sizeof(No));
    strcpy(novo_no->nome, nome);
    novo_no->proximo = NULL;
    return novo_no;
}


void adicionar_amigo(No** lista, char* nome) {
    No* novo_no = criar_no(nome);
    if (*lista == NULL) {
        *lista = novo_no;
    } else {
        No* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
}


No* encontrar_amigo(No* lista, char* nome) {
    No* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}


void inserir_nova_lista(No** lista, No* nova_lista, char* referencia) {
    if (referencia == NULL || encontrar_amigo(*lista, referencia) == NULL) {
        
        No* atual = *lista;
        if (atual == NULL) {
            *lista = nova_lista;
        } else {
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = nova_lista;
        }
    } else {
        
        No* ref_no = encontrar_amigo(*lista, referencia);
        No* anterior = NULL;
        No* atual = *lista;
        while (atual != ref_no) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == NULL) {
            
            No* ultimo = nova_lista;
            while (ultimo->proximo != NULL) {
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = *lista;
            *lista = nova_lista;
        } else {
           
            No* ultimo = nova_lista;
            while (ultimo->proximo != NULL) {
                ultimo = ultimo->proximo;
            }
            anterior->proximo = nova_lista;
            ultimo->proximo = ref_no;
        }
    }
}


void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%s", atual->nome);
        if (atual->proximo != NULL) printf(" ");
        atual = atual->proximo;
    }
    printf("\n");
}


void liberar_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    char linha[TAMANHO * 10];
    char nome[TAMANHO];
    No *lista_amigos = NULL, *nova_lista = NULL;

    
    fgets(linha, sizeof(linha), stdin);
    char* token = strtok(linha, " \n");
    while (token != NULL) {
        adicionar_amigo(&lista_amigos, token);
        token = strtok(NULL, " \n");
    }

    
    fgets(linha, sizeof(linha), stdin);
    token = strtok(linha, " \n");
    while (token != NULL) {
        adicionar_amigo(&nova_lista, token);
        token = strtok(NULL, " \n");
    }

    
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    
    if (strcmp(nome, "nao") == 0) {
        inserir_nova_lista(&lista_amigos, nova_lista, NULL);
    } else {
        inserir_nova_lista(&lista_amigos, nova_lista, nome);
    }

    
    imprimir_lista(lista_amigos);

    
    liberar_lista(lista_amigos);

    return 0;
}

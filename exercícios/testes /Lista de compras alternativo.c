#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 99
    typedef struct celula
    {
        char conteudo[21];
        struct celula* next;
    }cel;

    cel *insert(char *compra){
        cel *nova = malloc(sizeof(cel));;
        strcpy(nova->conteudo, compra);
        nova->next=NULL;
        return nova;
}

    void lixo(cel *head){
        cel *atual = head;
        
        while (atual!=NULL)
        {            
            cel *lixo = atual;
            atual = atual->next;
            free(lixo); 
        }  
}

cel *ordenar(char* compra, cel *head){
    cel *atual = head;
    cel *anterior = NULL;
    while (atual!=NULL && strcmp(atual->conteudo, compra) < 0)
    {
        anterior = atual;
        atual = atual->next;
    }
    if(atual!=NULL && strcmp(atual->conteudo, compra) == 0){
        return head;
    }
    // Cria um novo nó
    cel* nova = insert(compra);

    // Insere no início da lista
    if (anterior == NULL) {
        nova->next = head;
        return nova;
    } else {
        anterior->next = nova;
        nova->next = atual;
        return head;

}
}
void printlista(cel *head){
     cel *atual = head;
     while (atual!=NULL)
     {
        printf("%s ", atual->conteudo);
        atual = atual->next;
    }
       printf("\n");
        
}


        int main(){
        int n;
        do{
            scanf("%d", &n);
        }while(n < 0 || n > 100);
        getchar();
        
        cel *listas[n];
        for (int i = 0; i < n ; i++)
        {
            listas[i] = NULL; // Inicializa a lista como vazia

            char linha[21000];
            fgets(linha, sizeof(linha), stdin);
            char *item = strtok(linha, " \n");
            while(item != NULL){
                listas[i] = ordenar(item, listas[i]);
                item = strtok(NULL, " \n");
            }

        }
        for (int i = 0 ; i < n ; i++){
            printlista(listas[i]);
            lixo(listas[i]);
        }
        return 0;
    }

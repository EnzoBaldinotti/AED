//Enzo Baldinotti Ravanelli
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1000


typedef struct lista{
    char conteudo;
    struct lista *next;
}celula;

void push(char n, celula *p){
    
    celula* nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = n;
    nova->next = p->next;
    p->next = nova;
    
}

void pop(celula *p) {
    if (p->next == NULL) {
        return;
    }
    celula *remover = p->next;
    p->next = remover->next;
    free(remover);
}

void verify(char *conta){
    int i = 0, qtd = 0;
    
    celula* head = malloc(sizeof(celula));
    head->next = NULL;

    while (conta[i] != '\0'){
        if (conta[i] == '<'){
            push('<', head);
        }else if (conta[i] == '>'){
            if (head->next != NULL){  
                pop(head);
                qtd++;    
            }
        }
        i++;    
    }

    while (head->next != NULL){
        pop(head);
    }
    free(head);

    printf("%d\n", qtd);
}


int main(void){

    int n, i = 0;
    char conta[max];
    
    scanf("%d", &n);
    getchar();

    while (i < n){
        
        fgets(conta, sizeof(conta), stdin);
        conta[strcspn(conta, "\n")] = '\0'; 
        
        if (strlen(conta) > 0){ 
            verify(conta);
        }
        
        i++;
    }

    return 0;    
}

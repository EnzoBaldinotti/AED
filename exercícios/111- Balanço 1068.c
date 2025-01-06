//Enzo Baldinotti Ravanelli//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

bool verify(char *conta){
    int i = 0;
    bool decisor = true;
    celula* head = malloc(sizeof(celula));
    head->next = NULL;

    while(conta[i] != '\0'){
        if(conta[i] == '('){
            push('(', head);
        }
       
        else if(conta[i] == ')'){
            if(head->next == NULL){  
            decisor = false;
            break;
            }
            pop(head);
        }
        i++;    
    }

    if(head->next!=NULL){
        decisor = false;
    }

    while(head->next != NULL){
        pop(head);
    }
    free(head);

    return decisor;
}


int main(void){

    char conta[max];
    
    while(fgets(conta, sizeof(conta), stdin)){
        
        conta[strcspn(conta, "\n")] = '\0';
        if(verify(conta)){
            
            printf("correct\n");
        }
        else{
            
            printf("incorrect\n");
        }
    
    }

    return 0;    
}

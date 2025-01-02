//Enzo Baldinotti Ravanelli// RA:176265//

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int conteudo;
    struct lista *next;
}celula;

void add(int n, celula *p){
    
    celula* nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = n;
    nova->next = p->next;
    p->next = nova;
}

void retirar(celula *head, int item){
    
    celula *p;
    celula *q;
    
    p = head;
    q = head->next;
    while(p != NULL && p->conteudo != item){
        q = p;
        p = p->next;
    }
    if(p != NULL){
        q->next = p->next;
        free(p);
    }
}

void print(celula *head){
    celula *p;
    for(p = head->next; p != NULL; p = p->next){
        if(p->next == NULL)
            printf("%d\n", p->conteudo);
        else
            printf("%d ", p->conteudo);
    }

}

int main(){
    int n, m, valorInsert, valorRemocao;

    celula *head = (celula *)malloc(sizeof(celula));
    head->next = NULL;
    celula* nova = head;
    scanf("%d", &n);
    
        for ( int i = 0; i < n; i++){
            
            scanf("%d", &valorInsert);
            add(valorInsert, nova); 
            nova = nova->next;   
        }

    scanf("%d", &m);

        for(int k = 0 ; k < m ; k++){
            
            scanf("%d", &valorRemocao);
            retirar(head, valorRemocao);
        
        }
    print(head);

    return 0;
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct pilhaNo {
  char valor;
  struct pilhaNo *abaixo;
} PilhaNo;

typedef struct {
  int tamanho;
  PilhaNo *topo;
} Pilha;

void push(Pilha *p, char valor) {
  PilhaNo *novoTopo = malloc(sizeof(PilhaNo));
  if (novoTopo == NULL) {
    fprintf(stderr, "Erro de alocação de memória!\n");
    exit(1);
  }
  novoTopo->valor = valor;
  novoTopo->abaixo = p->topo;
  p->topo = novoTopo;
  p->tamanho++;
}

void pop(Pilha *p) {
  if (p->tamanho > 0) {
    PilhaNo *velhoTopo = p->topo;
    p->topo = p->topo->abaixo;
    free(velhoTopo);
    p->tamanho--;
  }
}

char top(Pilha *p) {
  return p->topo ? p->topo->valor : '\0';
}

int empty(Pilha *p) {
  return p->tamanho == 0;
}

void inicializa(Pilha *p) {
  p->tamanho = 0;
  p->topo = NULL;
}

void destroi(Pilha *p) {
  while (!empty(p)) {
    pop(p);
  }
}

int precedencia(char operador) {
  switch (operador) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;  
    default: return 0;
  }
}

int as(char operador) {
  return (operador == '^') ? 1 : 0;
}

int main() {
  int N;
  Pilha p;
  char expressao[301];

  scanf("%d", &N);
  getchar(); 

  for (int k = 0; k < N; ++k) {
    scanf("%s", expressao); 

    inicializa(&p);

    int tam = strlen(expressao);
    for (int i = 0; i < tam; ++i) {
      char c = expressao[i];

      if (isalnum(c)) {
        printf("%c", c);
      } else if (c == '(') {
        push(&p, c);
      } else if (c == ')') {
        while (!empty(&p) && top(&p) != '(') {
          printf("%c", top(&p));
          pop(&p);
        }
        if (!empty(&p)) pop(&p);
      } else { 
        while (!empty(&p) && top(&p) != '(' &&
              (precedencia(top(&p)) > precedencia(c) ||
              (precedencia(top(&p)) == precedencia(c) && as(c) == 0))) {
          printf("%c", top(&p));
          pop(&p);
        }
        push(&p, c);
      }
    }

    while (!empty(&p)) {
      printf("%c", top(&p));
      pop(&p);
    }

    printf("\n");
    destroi(&p);
  }

  return 0;
}

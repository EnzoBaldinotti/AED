#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 26

typedef int vertex;

struct graph {
    int V;
    int A;
    int **adj;
};

typedef struct graph *Graph;

static int **MATRIXint(int r, int c, int val) {
    int **m = malloc(r * sizeof(int *));
    for (vertex i = 0; i < r; ++i)
        m[i] = malloc(c * sizeof(int));
    for (vertex i = 0; i < r; ++i)
        for (vertex j = 0; j < c; ++j)
            m[i][j] = val;
    return m;
}

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w) {
    if (G->adj[v][w] == 0) {
        G->adj[v][w] = 1;
        G->adj[w][v] = 1;
        G->A++;
    }
}

void DFS(Graph G, vertex v, int *visited, char *component, int *index) {
    visited[v] = 1;
    component[(*index)++] = 'a' + v;

    for (vertex w = 0; w < G->V; ++w)
        if (G->adj[v][w] == 1 && !visited[w])
            DFS(G, w, visited, component, index);
}

void sortComponent(char *component, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = i + 1; j < size; ++j)
            if (component[i] > component[j]) {
                char temp = component[i];
                component[i] = component[j];
                component[j] = temp;
            }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int numv, numa;
        scanf("%d %d", &numv, &numa);

        Graph G = GRAPHinit(numv);

        for (int h = 0; h < numa; ++h) {
            char v1, v2;
            scanf(" %c %c", &v1, &v2);

            if (v1 < 'a' || v1 > 'z' || v2 < 'a' || v2 > 'z') {
                printf("Caracteres inválidos!\n");
                continue;
            }

            vertex v = v1 - 'a';
            vertex w = v2 - 'a';
            GRAPHinsertArc(G, v, w);
        }

        int visited[MAX_VERTICES] = {0};
        int numComponents = 0;

        printf("Case #%d:\n", i + 1);

        for (vertex v = 0; v < G->V; ++v) {
            if (!visited[v]) {
                char component[MAX_VERTICES];
                int index = 0;

                DFS(G, v, visited, component, &index);
                sortComponent(component, index);

                for (int j = 0; j < index; ++j)
                    printf("%c,", component[j]);
                printf("\n");

                numComponents++;
            }
        }

        printf("%d connected components\n\n", numComponents);

        for (vertex j = 0; j < G->V; ++j)
            free(G->adj[j]);
        free(G->adj);
        free(G);
    }

    return 0;
}

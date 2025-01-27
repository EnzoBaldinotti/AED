//Enzo Baldinotti Ravanelli//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 51
#define bigger_max 2550

void Intercala(int p, int q, int r, char v[][max]) {
    int i, j, k;
    char (*w)[max] = malloc((r - p) * sizeof(char[max]));
    i = p; 
    j = q; 
    k = 0;

    while (i < q && j < r) {
        if (strlen(v[i]) >= strlen(v[j])) {
            strcpy(w[k++], v[i++]);
        } else {
            strcpy(w[k++], v[j++]);
        }
    }

    while (i < q) {
        strcpy(w[k++], v[i++]);
    }

    while (j < r) {
        strcpy(w[k++], v[j++]);
    }

    for (i = p, k = 0; i < r; i++, k++) {
        strcpy(v[i], w[k]);
    }

    free(w);
}

void Mergesort(int p, int r, char v[][max]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        Intercala(p, q, r, v);
    }
}

int main() {
    int n;
    char *token, strings[50][max], string[bigger_max]; 

    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0'; 

        token = strtok(string, " ");
        int k = 0;

      
        while (token != NULL) {
            strcpy(strings[k++], token);
            token = strtok(NULL, " ");
        }

       
        Mergesort(0, k, strings);

        
        for (int j = 0; j < k; j++) {
            printf("%s", strings[j]);
            if (j < k - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

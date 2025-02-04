#include <stdio.h>
#include <string.h>
#define max 10

int verif(char *rajesh, char *sheldon) {
    if (strcmp(rajesh, sheldon) == 0) return 0;
    
    if ((strcmp(rajesh, "tesoura") == 0 && (strcmp(sheldon, "papel") == 0 || strcmp(sheldon, "lagarto") == 0)) ||
        (strcmp(rajesh, "papel") == 0 && (strcmp(sheldon, "pedra") == 0 || strcmp(sheldon, "spock") == 0)) ||
        (strcmp(rajesh, "pedra") == 0 && (strcmp(sheldon, "tesoura") == 0 || strcmp(sheldon, "lagarto") == 0)) ||
        (strcmp(rajesh, "lagarto") == 0 && (strcmp(sheldon, "spock") == 0 || strcmp(sheldon, "papel") == 0)) ||
        (strcmp(rajesh, "spock") == 0 && (strcmp(sheldon, "tesoura") == 0 || strcmp(sheldon, "pedra") == 0))) {
        return 1; 
    }
    
    return -1; 
}

int main() {
    int n;
    char rajesh[max], sheldon[max];
    
    scanf("%d", &n);
    
    while (n--){
        scanf("%s %s", rajesh, sheldon);
        
        int resultado = verif(rajesh, sheldon);
        
        if (resultado == 0) printf("empate\n");
        else if (resultado == 1) printf("rajesh\n");
        else printf("sheldon\n");
    }
    
    return 0;
}

//Enzo Baldinotti Ravanelli//
#include <stdio.h>
#include <stdbool.h>

#define max 99

void direction(char atual, int *px, int *py){
    
    if(atual == '>'){
        (*px)++;
    } else if(atual == '<'){
        (*px)--;
    } else if(atual == 'v'){
        (*py)++;
    } else if(atual == '^'){
        (*py)--;
    }
}


bool map_verifier(char matriz[][max], int x, int y){
    
    int n = 0;
    int py = 0, px = 0;
    char atual = matriz[py][px];

    while(px >= 0 && px < x && py >= 0 && py < y && n < x * y){
        
        if(matriz[py][px] == '*'){
            return true;
        }
        else if(matriz[py][px] == '>'){
            atual = matriz[py][px];          
            direction(atual, &px, &py);
        }
        else if(matriz[py][px] == 'v'){
            atual = matriz[py][px];
            direction(atual, &px, &py);
        }
        else if(matriz[py][px] == '<'){
            atual = matriz[py][px];
            direction(atual, &px, &py);
        }
        else if(matriz[py][px] == '^'){
            atual = matriz[py][px];
            direction(atual, &px, &py);
        }
        else if(matriz[py][px] == '.'){
            direction(atual, &px, &py);
        }else {
            break;
        }
        n++;
    }

    return false;
}

int main(){
    int y, x;
    char matriz[max][max];

    scanf("%d", &x);
    scanf("%d", &y);
    
    getchar();

    for(int i = 0 ; i < y ; i++){
        for(int k = 0 ; k < x ; k++){
            scanf("%c", &matriz[i][k]);
        }
        getchar();
    }
    
    
    if(map_verifier(matriz, x, y)){
        printf("*\n");
    }else {
        printf("!\n");  
    }
    
    return 0;

}

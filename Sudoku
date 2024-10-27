#include <stdio.h>

    void matrizes(int k , int m[k][9][9]){
        
        for(int i = 0 ; i < k ; i++){
            for(int l = 0 ; l < 9 ; l++){
                for(int c = 0 ; c < 9; c++){
                    scanf("%d", &m[i][l][c]);
                }
            }        
        }
    }   
    

    int verificar_linha(int m[9][9]){//verificar a matriz 9x9 horizontalmente//
        
        for(int l = 0 ; l < 9 ; l++){
            int verificador[10] = {0};
            for(int c = 0 ; c < 9 ; c ++){
                int num = m[l][c];
                if(verificador[num] == 1 || m[l][c] < 1 || m[l][c] > 9){
                    return 0;
                    }
                verificador[num] = 1;
                }
            }
            
            return 1; 
        }
    
    
    int verificar_coluna(int m[9][9]){//verificar a matriz 9x9 verticalmente//
        
        for(int c = 0 ; c < 9 ; c++){
            int verificador[10] = {0};
            for(int l = 0 ; l < 9 ; l++){
                int num = m[l][c];
                if(verificador[num] == 1 || m[l][c] < 1 || m[l][c] > 9){
                    return 0;
                }
                verificador[num] = 1;
            }
        }
    
        return 1;

    }

    int verificar_subgrade(int m[9][9]) {
    
        for (int inicio_linha = 0 ; inicio_linha < 9 ; inicio_linha += 3){
            for (int inicio_coluna = 0 ; inicio_coluna < 9 ; inicio_coluna += 3){
                int verificador[10] = { 0 };
                for (int l = 0 ; l < 3 ; l++){
                    for (int c = 0 ; c < 3 ; c++){
                        int num = m[inicio_linha + l][inicio_coluna + c];
                        if (num < 1 || num > 9 || verificador[num] == 1){
                        return 0;
                    }
                    verificador[num] = 1;
                    }
                }
            }
        }
        
        return 1;
    
    }

    void verificar_sudoku(int k, int m[k][9][9]) {
        for (int i = 0; i < k; i++) {
            if (verificar_linha(m[i]) && verificar_coluna(m[i]) && verificar_subgrade(m[i])) {
                printf("Instancia %d\nSIM\n\n", i + 1);
            } else {
            printf("Instancia %d\nNAO\n\n", i + 1);
            }
        }
    }
   
    int main(){
        
        int n, k;
        scanf("%d", &n);
        k = n;
        int m[k][9][9];
        matrizes(n, m);
        verificar_sudoku(n, m);

        return 0;
    }

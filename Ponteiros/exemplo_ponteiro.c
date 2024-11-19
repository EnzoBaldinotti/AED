#include <stdio.h>

int main(){
    int var = 15;
    int *ptr;
    ptr = &var;

    printf("conteudo de var: %d\n", var);
    printf("endereço de var: %p\n", &var);
    printf("conteudo apontado por ptr: %d\n", *ptr);
    printf("endereço apontado por ptr: %p\n", ptr);
    printf("endereço de ptr: %p\n", &ptr);

    return 0;
}


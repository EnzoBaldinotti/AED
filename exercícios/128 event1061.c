#include <stdio.h>

int main() {
    int dia_inicio, dia_fim;
    int h1, m1, s1, h2, m2, s2;
    
    scanf("Dia %d", &dia_inicio);
    scanf("%d : %d : %d", &h1, &m1, &s1);
    
    
    scanf(" Dia %d", &dia_fim);
    scanf("%d : %d : %d", &h2, &m2, &s2);
    

    int inicio_segundos = dia_inicio * 86400 + h1 * 3600 + m1 * 60 + s1;
    int fim_segundos = dia_fim * 86400 + h2 * 3600 + m2 * 60 + s2;
    
    int duracao = fim_segundos - inicio_segundos;
    
    
    int dias = duracao / 86400;
    duracao %= 86400;
    
    int hr = duracao / 3600;
    duracao %= 3600;
    
    int min = duracao / 60;
    int seg = duracao % 60;
    
    
    printf("%d dia(s)\n", dias);
    printf("%d hora(s)\n", hr);
    printf("%d minuto(s)\n", min);
    printf("%d segundo(s)\n", seg);
    
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char jon[1002], medico[1002];

    scanf("%s", jon);
    scanf("%s", medico);

    if (strlen(jon) >= strlen(medico))
        printf("go\n");
    else
        printf("no\n");

    return 0;
}

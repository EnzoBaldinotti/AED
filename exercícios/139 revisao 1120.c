#include <stdio.h>
#include <string.h>

int main()
{
    char digito, numero[101];

    while (1)
    {

        scanf(" %c %s", &digito, numero);

        if (digito == '0' && strcmp(numero, "0") == 0)
        {
            break;
        }

        char resultado[101];
        int j = 0;
        for (int i = 0; i < strlen(numero); i++)
        {
            if (numero[i] != digito)
            {
                resultado[j++] = numero[i];
            }
        }
        resultado[j] = '\0';

        int k = 0;
        while (resultado[k] == '0' && k < strlen(resultado))
        {
            k++;
        }

        if (k == strlen(resultado))
        {
            printf("0\n");
        }
        else
        {

            printf("%s\n", resultado + k);
        }
    }

    return 0;
}

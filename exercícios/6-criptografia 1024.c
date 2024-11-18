//Enzo Baldinotti Ravanelli RA:176265//
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[1002], str1[1002];

    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin); 
        int l = strlen(str);

       
        if (str[l - 1] == '\n') {
            str[l - 1] = '\0';
            l--;
        }

        
        for (int k = 0; k < l; k++) {
            if ((str[k] >= 'A' && str[k] <= 'Z') || (str[k] >= 'a' && str[k] <= 'z')) {
                str[k] += 3;
            }
        }

        for (int j = 0; j < l; j++) {
            str1[j] = str[l - j - 1];
        }
        str1[l] = '\0'; 

        
        for (int h = l / 2; h < l; h++) {
            str1[h] -= 1;
        }

        
        printf("%s\n", str1);
    }

    return 0;
}

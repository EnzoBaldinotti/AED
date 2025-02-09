#include <stdio.h>

int main()
{
    int n, x, y, box;

    scanf("%d", &n);

    for(int i = 0 ; i < n; i++){
        scanf("%d %d", &x, &y);

        box = 1;
        while(x && y){
            if (x%10 != y%10){
                box = 0;
                break;
            }
            x /= 10;
            y /= 10;
        }

        if(y)
            box = 0;

        printf("%s\n", box ? "encaixa" : "nao encaixa");
    }

    return 0;
}

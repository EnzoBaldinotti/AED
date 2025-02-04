#include <string.h>
#include <stdio.h>
#define max 21

int main(){
    int N;
    char obi[max];

    scanf("%d\n", &N);

    for(int i = 0; i < N; ++i){
        scanf("%s", &obi);

        if(i)   printf(" ");
        if(strlen(obi) == 3){
            if(obi[0] == 'O' && obi[1] == 'B'){
                printf("OBI");
            }
            else if(obi[0] == 'U' && obi[1] == 'R'){ 
                printf("URI");
            }
            else printf("%s", obi);
        }else{
            printf("%s", obi);
        }
    }
    
    printf("\n");

    return 0;
}

//Enzo Baldinotti Ravanelli
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    
    int tot1 = (n1+n2+abs(n1-n2))/2;
    int tot2 = (tot1+n3+abs(tot1-n3))/2;
   
    printf("%d eh o maior\n", tot2);
    
    return 0;
}

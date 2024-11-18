#include <stdio.h>
 
int main() {
    int n, hrs;
    double sal;
    scanf("%d", &n);
    scanf("%d", &hrs);
    scanf("%lf", &sal);
    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2lf\n", sal * hrs);
    
    return 0;
}

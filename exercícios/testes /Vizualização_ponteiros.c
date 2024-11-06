#include <stdio.h>

    int main(){
        int x=1,y=3 ;
        int *px=&y, *py=&y;
        *px=*px+*py;
 
        printf("x=%d, y=%d\n", x, y);
        printf("*px=%d, *py=%d\n", *px, *py);
        printf("px=%p, py=%p\n", px, py);
        printf("&x=%p, &y=%p\n", &x, &y);
        printf("&x=%p, &y=%p\n", x, y);  
        printf("y=%d, x=%d\n", y, x);
    return 0;
} 

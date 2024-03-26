// Se introduc n numere. Gasiti cmmdc al acestor n numere, fara vectori
#include <stdio.h>

int main(){
    int n, x, y, r;
    scanf("%d", &n);
    scanf("%d%d", &x, &y);
    while(y){
        r = x % y;
        x = y;
        y = r;
    }
    n-=2;
    printf("%d\n", n);
    printf("%d\n", x);
    while(n > 0){
        scanf("%d", &y);
            while(y){
            r = x % y;
            x = y;
            y = r;
            }
        n--;
        printf("In urma acestui ciclu, n a devenit %d\n", n);
    }
    printf("%d\n", x);
    return 0;
    
}
#include <stdio.h>

int main() {
    int x, xx, n; //xx is a copy of x, n will be the number created by inverting x's digits
    n=0;
    scanf("%d", &x);
    xx = x;
    while(xx>0)
    {
        n=n*10+xx%10;
        xx/=10;
    }
    printf("%d\n", xx);
    printf("%d\n", n);
    if(x == n){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
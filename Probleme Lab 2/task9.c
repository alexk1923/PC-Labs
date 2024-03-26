//Sa se calculeze n!
#include <stdio.h>

int main(){
    int n, p;
    scanf("%d", &n);
    p=1;
    while(n>1){
        p=p*n;
        n--;
    }
    printf("%d\n", p);
    return 0;
}
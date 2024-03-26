#include <stdio.h>

int main(){
    int x, k;

    scanf("%d", &x);
    k=0;

    while(x){
        k++;
        x/=10;
    }

    printf("%d\n", k);

    return 0;

}
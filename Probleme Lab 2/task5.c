//Se introduc niste nr pozitive. Sa se afiseze toti divizorii nebanali si sa se precizeze la final cate numere prime sunt.
// Citirea se incheiei odata cu citirea unei valori negative.

#include <stdio.h>

int main(){
    int x, d, k; //k=nr of prime numbers
    short int is_div, is_prime;
    k=0;
    do{
            scanf("%d", &x);
            if(x>0) {
            is_prime = 1;
            for(d = 2; d < x; d++){
                if(x % d == 0){
                    printf("%d ", d);
                    is_prime=0;
                }
            }
            if(is_prime == 1)
            {
                k++;
            printf("PRIM");
            }
            printf("\n");
        }
    }
    while(x > 0);
    printf("S-au gasit %d numere prime\n", k);
    return 0;
 }

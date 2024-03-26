#include <stdio.h>

#define SET_SIZE 100                   // aceasta este o macrodefiniție (momentan o putem privi ca pe O CONSTANTA CARE ARE VALOAREA 100
typedef unsigned char SET[SET_SIZE];   // definesc tipul SET, care este un vector cu maxim 100 de elemente de tip unsigned char



void print_bits(unsigned int x)
{
    unsigned int mask = (1 << 31);
    for(int i = 0; i < 32; i++) {
        //printf("\n%d", mask);
        printf("%d", (x & mask)!=0);
        mask>>=1;
    }
}


int main(void)
{
    int n;
    int x;
    SET s[SET_SIZE];
    for (int i = 0; i < 8; i++)
    {
        
    }
    

    // scanf("%d", &n);
    // printf("%d ", pow2(n));

    //printf("%d ", flip_bits(x));
    print_bits(x);
    printf("\n%d", is_power2(x));
    //printf("%d\n", is_even(x));
}
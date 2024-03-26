#include <stdio.h>

int pow2(int n) {
    int x = 1;
    x = x << n;
    return x;
}

int flip_bits(int x)
{
    return ~x;
}

void print_bits(unsigned int x)
{
    unsigned int mask = (1 << 31);
    for(int i = 0; i < 32; i++) {
        //printf("\n%d", mask);
        printf("%d", (x & mask)!=0);
        mask>>=1;
    }
}

int is_even(int n)
{   
    int x = (n +1)>>1;
    int y = n >> 1;
    return (x == y);
}

int is_power2(int x)
{
    if(x == 1)
        return 1;
    if((x & (x - 1)) == 0)
        return 1;
    return 0;
}

int main(void)
{
    int n;
    int x;
    scanf("%d", &x);

    // scanf("%d", &n);
    // printf("%d ", pow2(n));

    //printf("%d ", flip_bits(x));
    print_bits(x);
    printf("\n%d", is_power2(x));
    //printf("%d\n", is_even(x));
}
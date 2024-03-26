#include <stdio.h>

void swap_int(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main(){
    int p = 3, q = 9;
    swap_int(&p, &q);
    printf("%d %d", p, q);
    return 0;
}
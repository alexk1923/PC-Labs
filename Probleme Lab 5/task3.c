#include <stdio.h>

void swap_ptr(int **p1, int **p2)
{
    int *tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

}

int main()
{
    int *p = (int *)0x123, *q = (int *)0x456;
    printf("Inainte de schimbare:\n%p %p\n", p, q);
    swap_ptr(&p, &q);
    printf("Dupa schimbare:\n%p %p", p, q);
    return 0;
}
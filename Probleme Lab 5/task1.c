#include <stdio.h>

void read_vect(int *n, int *v)
{
    scanf("%d", &n);

    for (int i = 0; i < *n; i++) {
        scanf("%d", &v[i]);
    }
    
}

int main()
{
    int a[100], dim;
    read_vect(&dim, a);

    for (int i = 0; i < dim; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
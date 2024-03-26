#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a, n;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
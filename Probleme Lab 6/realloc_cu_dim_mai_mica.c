#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *v, n;
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    if(!v)
        printf("ERoare");

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    printf("\n");

    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    printf("\nDupa realocare, vectorul devine: ");
    
    v = realloc(v, 4*sizeof(int));

    for(int i = 0; i < 4; i++)
        printf("%d ", v[i]);

    free(v);
    return 0;
}
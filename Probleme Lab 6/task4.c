#include <stdio.h>
#include <stdlib.h>

int **alloc_matrix_varlen(int n, int *m, int **a)
{
    int i;
    a = malloc(n*sizeof(int*));
    for(i = 0 ; i < n ; i++) {
        a[i] = malloc(m[i]*sizeof(int));
    }
    if(!a) {
        printf("Eroare");
    }
    return a;
}

void free_matrix_varlen(int n, int **a) {
    for(int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}


int main(void)
{
    int n, i, j, *m, **a;

    scanf("%d", &n);

    m = malloc(n*sizeof(int));

    if(!m) {
        printf("Eroare");
    }


    for(i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

    a = alloc_matrix_varlen(n, m, a);

    int count = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++)
            a[i][j] = count++;
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    free_matrix_varlen(n, a);
    free(m);

    return 0;
}

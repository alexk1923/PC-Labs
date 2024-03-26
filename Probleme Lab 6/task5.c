#include <stdio.h>
#include <stdlib.h>

int **alloc_matrix(int n, int m)
{
    int **mat;
    mat = malloc(n * sizeof(int *));
    if(mat == NULL) {
        printf("Eroare alocare memorie");
    }
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(m * sizeof(int));
        if(mat[i]==NULL) {
            printf("Eroare alocare memorie");
        }
    }
    return mat;

}

// funcția primește dimensiunile unei matrice și matricea alocată
// va citi elementele și le va salva în matrice 
void read_matrix(int n, int m, int **a)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
}

// funcția va afișa elementele matricei
void print_matrix(int n, int m, int **a)
{
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void free_matrix(int **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void show_addresses_dynamic(int n, int m, int **a) {
    int i, j, *p;
    for(i =0; i < n; i++){
        p = &a[i][0];
        for(j = 0; j < m; j++) {
            p++;
            printf("%p ", p);
        }
        printf("\n");
    }
}


void show_addresses_static(int n, int m, int a[5][5]) {
    int i, j, *p;
    for(i =0; i < n; i++){
        p = &a[i][0];
        for(j = 0; j < m; j++) {
            p++;
            printf("%p ", p);
        }
        printf("\n");
    }
}

int main(void)
{
    int i, j, n, m, *p, **a, static_mat[5][5];
    scanf("%d%d", &n, &m);

    a = alloc_matrix(n, m);

    // for(i = 0; i < n; i++)
    //     for(j = 0; j < m; j++)
    //         scanf("%d", &static_mat[i][j]);
    // printf("\nAti citit prima matrice\n");

    // read_matrix(n,m,a);
    printf("\nADresele primei matrici(statica):\n");
    show_addresses_static(n,m,static_mat);
    printf("\nADresele celei de-a doua matrici(dinamica):\n");
    show_addresses_dynamic(n,m,a);
    free_matrix(a, n, m);
    return 0;
}
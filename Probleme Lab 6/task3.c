#include <stdio.h>
#include <stdlib.h>

// funcția primește ca parametri dimensiunile unei matrice
// aloca tabloul și returnează pointerul
int **alloc_matrix(int n, int m)
{
    int **mat;
    mat = (int **)malloc(n* sizeof(int*));
    if(mat == NULL) {
        fprintf(stderr, "Eroare alocare memorie");
    }
    for (int i = 0; i < m; i++) {
        mat[i] = (int *)malloc(m*sizeof(int));
        if(mat[i]==NULL) {
            fprintf(stderr, "Eroare alocare memorie");
            exit(1);
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

// funcție care primește toate datele necesare pentru
// eliberarea unei matrice alocată cu alloc_matrix
//
// trebuie să deduceți semnătura
void free_matrix(int **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

int main(void)
{
    int **mat;
    int n, m;
    scanf("%d%d", &n, &m);
    mat = alloc_matrix(n, m);
    if(!mat) {
        return -1;
    }
    read_matrix(n, m, mat);
    print_matrix(n, m, mat);
    //free_matrix(mat, n, m);
}
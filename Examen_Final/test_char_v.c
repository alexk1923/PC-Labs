#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}prod;

int main()
{
    char name[250];
    prod *p = malloc(10 * sizeof(prod));
    scanf("%s", name);
    printf("%s", name);
    free(p);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, *v, a[100];
    FILE *fin;
    char filename[100];
    scanf("%s", filename);



    if((fin = fopen(filename, "r")) == NULL) {
        printf("Fisierul nu a putut fi creat / accesat");
    }

    i = 0;
    while(!feof(fin)) {
        fscanf(fin, "%d", &a[i++]);  
    }

    n = --i; //set size of array

    fseek(fin, 0 , SEEK_SET);

    v = malloc( n * sizeof(int));
    if(!v) {
        return -1;
        printf("EROARE BAI!");
    }

    i = 0;
    while(!feof(fin)) {
        fscanf(fin, "%d", &v[i++]);
    }

    fflush(fin);

    printf("%d\n", n);
    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    
    
    fclose(fin);
    return 0;
}
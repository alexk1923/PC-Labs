#include <stdio.h>

int main(void)
{
    int n, i, v[100];
    FILE *fin;
    char filename[100];
    scanf("%s", filename);

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    if((fin = fopen(filename, "wb")) == NULL) {
        printf("Fisierul nu a putut fi creat / accesat");
    }

    fwrite(v, sizeof(int), n, fin);
    
    fclose(fin);
    return 0;
}
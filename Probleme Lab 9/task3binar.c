#include <stdio.h>
#include <stdlib.h>

int print_file(char file[], int *nr, int **v)
{   
    FILE *fin;
  
    if((fin = fopen(file, "rb")) == NULL) {
        printf("Fisierul %s nu poate deschis\n", file);
        return -1;
    }

    fseek(fin, 0, SEEK_END);
    *nr = ftell(fin) / sizeof(int);
    int *w = malloc( *nr * sizeof(int));
    if(!w) {
        printf("Eroare!");
    }

    *v = w;

    fseek(fin, 0, SEEK_SET);

    

    while(!feof(fin)) {
        if( (fread(w, sizeof(int) , *nr, fin)) == 0) {
            //printf("EROARE BAI");
            return -1;
        }
    }


  
    fclose(fin);
    return 0;
}






int main(void)
{
    int n, i, a[100];
    int *v = NULL;
    //FILE *fin;
    char filename[100];
    scanf("%s", filename);


    print_file(filename, &n, &v);
   

    printf("%d\n", n);
 

    for(i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }
    
    
    free(v);
    //fclose(fin);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX_LINE 100
#define NMAX_MOVIES 100

typedef struct
{
    char nume[100];
    char tip[20];
    int nota;
} movie;


void swap_movies(movie *m, movie *n) {
    movie tmp = *m;
    *m = *n;
    *n = tmp;
}

int min(int x, int y)
{
    if(x > y)
        return y;
    return x;
}

void read_info(movie **m, char line[], int i)
{   
    
    const char *genres[15] = {"romance", "psihological", "action"};
    char *s;
    int index;

    for(int j = 0; j < 3; j++) {
        s = strstr(line, genres[j]);
        if(s) {
            index = j; //assign the found genre
            break;
        }
    }

    if(!s) {
        printf("No genres recognised");
        return;
    }

    memcpy((*m)[i].nume, line, (s - line)); //assign name
    (*m)[i].nume[s - line - 1] = '\0';

    strcpy((*m)[i].tip, genres[index]); //assign genre

    char *token = strtok(s, " ");
    (*m)[i].nota = atoi(strtok(NULL, " ")); //assign grade

}

void print_movies(const char *type, int nr, movie *m, int dim)
{   
    int k = 0;
    nr = min(nr,dim);
    if(!strcmp(type, "romance")) {
        for(int i = 0; i < dim && k < nr; i++)
            if(!strcmp(m[i].tip, type)) {
                printf("%s %d\n", m[i].nume, m[i].nota);
                k++;
            }
    } else if(!strcmp(type, "psihological")) {
        for(int i = 0; i < dim && k < nr; i++)
            if(!strcmp(m[i].tip, type)) {
                printf("%s %d\n", m[i].nume, m[i].nota);
                k++;
            }
    } else if(!strcmp(type, "action")) {
        for(int i = 0; i < dim && k < nr; i++)
            if(!strcmp(m[i].tip, type)) {
                printf("%s %d\n", m[i].nume, m[i].nota);
                k++;
            }
    } else if(!strcmp(type, "all"))
        for(int i = 0; i < dim && k < nr; i++) {
            printf("%s %d\n", m[i].nume, m[i].nota);
            k++;
        }
}

void sort_movies(movie **m, int dim)
{
    for(int i = 0; i < dim; i++)
        for(int j = i + 1; j < dim; j++)
            if((*m)[i].nota < (*m)[j].nota)
                swap_movies(&((*m)[i]), &((*m)[j]));
}

int main(int argc, char *argv[])
{
    FILE *fin;
    char *filename;

    if(argc < 4) {
        printf("Invalid parameters\n");
        return -1;
    }

    filename = strdup(argv[1]); //input file
    printf("%s\n", filename);

    movie *m;
    m = malloc(NMAX_MOVIES * sizeof(movie));

    fin = fopen(filename, "r");
    if(fin == NULL) {
        printf("Eroare citire fisier\n");
        return -1;
    }

    char line[NMAX_LINE];
    int i = 0;
    while(fgets(line, NMAX_LINE, fin)) { //read line by line until eof
        read_info(&m, line, i);
        i++;
    }

    int dim = i; //assign movie array size

    movie *tmp;
    tmp = realloc(m, i * sizeof(movie)); //resize movie array with correct size

    if(!tmp) {
        printf("malloc failed()");
        return -1;
    } else {
        m = tmp;
    } 

    //sort movie array
    sort_movies(&m, dim);

    char *type = strdup(argv[2]);
    int nr = atoi(argv[3]);
    print_movies(type, nr, m, dim);

    //free your ponies
    fclose(fin);
    free(m);
    free(filename);
    free(type);
   
    return 0;
}
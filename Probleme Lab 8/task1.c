#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUME 29
#define MAX_GRUPA 5

#define INPUT_LINE_SIZE 100

typedef struct{
    char nume[MAX_NUME + 1];
    char grupa[MAX_GRUPA + 1];
    double medie;
}student;


void print_stud(student s)
{
    printf("%s\t%s\t%lf\n", s.nume, s.grupa, s.medie);
}

int compare(const void *s1, const void *s2)
{   
    const student *stud1 = (const student *)s1;
    const student *stud2 = (const student *)s2;
    return strcmp(stud1->nume, stud2->nume);
}

int read_student(student* s, FILE *fin) {

    char line[INPUT_LINE_SIZE];
    if(!fgets(line, sizeof(line),fin)) {
        return 1;
    }

    if(!strchr(line, '\n')) {
        return 2;
    }

    int rc = sscanf(line, "%30s %6s %lf", s->nume, s->grupa, &s->medie);
    if(rc != 3)
        return 3;

    return 0;
}

int main(void)
{
    student *s;
    int n;
    
    char line[INPUT_LINE_SIZE];
    fgets(line, sizeof(line), stdin);

    int rc = sscanf(line, "%d", &n);
    if(rc != 1) {
        printf("Eroare citire numar studenti");
        exit(1);
    }

    s = malloc(n * sizeof(student));
    if(!s) {
        printf("Eroare");
        return -1;
    }


    for(int i = 0; i < n; i++) {
        rc = read_student(&s[i], stdin);

        //citire student esuata
        if(rc != 0) {
            printf("EROARE %d CITIRE STUDENT", rc);
            free(s);
            exit(1);
        } 
    }

    printf("%s", s[0].nume);
    printf("%d", compare(s, s+1));

    qsort(s, n, sizeof(student), compare);

    
    for(int i = 0; i < n; i++) {
        print_stud(s[i]);
    }
    


    return 0;
}
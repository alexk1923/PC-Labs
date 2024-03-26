#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUME 29
#define MAX_GRUPA 5

#define INPUT_LINE_SIZE 100

typedef struct{
    char *nume;
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
    fflush(stdout);

    if(!strchr(line, '\n')) {
        return 2;
    }

    char nume[MAX_NUME +1];

    int rc = sscanf(line, "%30s %6s %lf", nume, s->grupa, &s->medie);

    if(rc != 3) {
        printf("rc = %d != 3", rc);
        return 3;
    }

    s->nume = strdup(nume);

    if(!s->nume) {
        return -1;
    }

    return 0;
}

void free_students(int n, student *s)
{
    for(int i = 0; i < n; i ++) {
        free(s[i].nume);
    }
}


int main(void)
{
    student stud1, stud2;
    int n;
    
    
    int rc = read_student(&stud1, stdin);

        //citire student esuata
    if(rc != 0) {
        printf("EROARE %d CITIRE STUDENT", rc);
        exit(1);
    }

    print_stud(stud1);
    
    stud2.medie = stud1.medie;
    strcpy(stud2.grupa, stud1.grupa);
    stud2.nume = strdup(stud1.nume);

    free(stud2.nume);
    stud2.nume = strdup("Andrei");


    printf("Studentul 2 este: ");
    print_stud(stud2);

    free(stud1.nume);
    free(stud2.nume);

    return 0;
}
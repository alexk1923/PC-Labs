#include <stdio.h>

typedef struct{
    char nume[31];
    int varsta;
} student_t;

int main(void)
{
    FILE *fin;
    char file[100];
    student_t stud;
    scanf("%s  %30s %d", file, stud.nume, &stud.varsta);

    if((fin = fopen(file, "w"))==NULL) {
        printf("FIsierul %s nu poate fi accesat / creat\n", file);
        return -1;
    }

    fprintf(fin, "saved-name = %s\nsaved_age = %d", stud.nume, stud.varsta);
    fclose(fin);

    if((fin = fopen(file, "r"))==NULL) {
        printf("FIsierul %s nu exista", file);
        return -1;
    }
    

    fclose(fin);
    return 0;
}
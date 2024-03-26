#include <stdio.h>

typedef struct{
    char nume[31];
    int varsta;
} student_t;


int print_file(char file[])
{   
    FILE *fin;
    student_t stud;
    if((fin = fopen(file, "rb")) == NULL) {
        printf("FIsierul %s nu poate deschis\n", file);
        return -1;
    }

    while(!feof(fin)) {
        if((fread(&stud, sizeof(student_t), 1 , fin)) == 0)
            return -1;
        printf("saved_name = %s\nsaved_age = %d\n",stud.nume, stud.varsta);
    }
    fclose(fin);
    return 0;
}

int main(void)
{
    FILE *fin;
    char file[100];
    student_t stud;
    scanf("%s  %30s %d", file, stud.nume, &stud.varsta);

    if((fin = fopen(file, "ab")) == NULL) {
        printf("FIsierul %s nu poate fi accesat / creat\n", file);
        return -1;
    }

    fwrite(&stud,  sizeof(student_t), fin);
    fclose(fin);

    print_file(file);
    return 0;
}
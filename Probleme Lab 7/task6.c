#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *nume;
    char *prenume;
    int varsta;
}student;

void swap_students(student *s1, student *s2) {

    char *aux = s1->nume;
    s1->nume = s2->nume;
    s2->nume = aux;

    aux = s1->prenume;
    s1->prenume = s2->prenume;
    s2->prenume = aux;

    int aux_int = s1->varsta;
    s1->varsta = s2->varsta;
    s2->varsta = aux_int;
}

void sorting_by_option(int opt, int n, student *v)
{
    switch(opt) {
    case 1:
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(strcmp(v[i].nume, v[j].nume) > 0)
                    swap_students(&v[i], &v[j]);
            }
        }
        break;
    case 2:
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(strcmp(v[i].prenume, v[j].prenume) < 0)
                    swap_students(&v[i], &v[j]);
            }
        }
        break;
    case 0:
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(v[i].varsta  < v[j].varsta)
                    swap_students(&v[i], &v[j]);
                else if(v[i].varsta == v[j].varsta)
                    if(strcmp(v[i].nume, v[j].nume) > 0)
                        swap_students(&v[i], &v[j]);
                    else if(strcmp(v[i].nume, v[j].nume) == 0)
                        if(strcmp(v[i].prenume, v[j].prenume) < 0)
                        swap_students(&v[i], &v[j]);
            }
        }
        break;
    default:
        break;
    }
}

void free_students(student *v, int n)
{
    for(int i = 0; i < n; i++) {
        free(v[i].nume);
        free(v[i].prenume);
    }
    free(v);
}

int main(void)
{
    int n, i, opt;
    student *v;
    scanf("%d", &n);

    v = malloc(n * sizeof(student));

    //scanf("%d", &opt);
    char firstname[100];
    char lastname[100];
    int age;

    for(i = 0; i < n; i++) {
        //printf("i = %d\n", i);
        scanf("%s%s%d", firstname, lastname, &age);
        v[i].nume = strdup(firstname);
        v[i].prenume = strdup(lastname);
        v[i].varsta = age;
    }

    for(i = 0; i < n; i++) {
        printf("%s %s %d\n", v[i].nume, v[i].prenume, v[i].varsta);
    }

    //swap_students(&v[1], &v[2]);


    scanf("%d", &opt);
    sorting_by_option(opt, n, v);

    printf("After sorting:\n");

    for(i = 0; i < n; i++) {
        printf("%s %s %d\n", v[i].nume, v[i].prenume, v[i].varsta);
    }
    free_students(v, n);
    return 0;
}
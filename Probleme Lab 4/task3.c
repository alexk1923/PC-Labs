#include <stdio.h>
#define MAX 100

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void selectionSort(int n, int v[]){

    int min_index;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for(int j = i+1; j< n; j++){
            if(v[min_index] > v[j]){
                min_index = j;
            }
        }
        swap(&v[i], &v[min_index]);
    }
}

int main(){

    int v[MAX], i, n;


    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }


    selectionSort(n, v);

    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    return 0;
}
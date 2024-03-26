#include <stdio.h>
#define MAX 100

int find_array(int n, int v[], int x){
    for (int i = 0; i < n ; i++){
        if(v[i] == x)
            return i;
    }
    return -1;
}

int main(){
    int v[MAX], i, n;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n%d\n", find_array(n, v, 24));
    
    return 0;
}
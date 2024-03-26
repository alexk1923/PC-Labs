#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *v, capacity = 1, size = 0;
    v = malloc(capacity * sizeof(int));
    while(x!= -1) {
        scanf("%d", &x);
        if(x == -1)
            break;
        else {
            if(size == capacity) {
                if(capacity == 0)
                    ++capacity;
                else {
                    capacity*=2;
                }
                
            }
            v = realloc(capacity * sizeof(int));
        }
    }
    if(size < capacity) {
         v = realloc(capacity * sizeof(int));
    }
    return 0;
}
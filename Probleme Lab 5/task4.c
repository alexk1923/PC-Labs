//NEREZOLVATA DE MINE. VEZI RASPUNSURI
#include <stdio.h>

void my_memcpy(void *dst, const void *src, int num)
{
    printf("%d\n", num);
    printf("Adresa pointerului src este: %p\n", src);
}

int main()
{
        // exemplu cu int
    int a = 123; // initializat
    int b; 	       // neinitializat
    printf("Adresa lui a este: %p\n", &a);
    my_memcpy(&b, &a, sizeof(a));
    // print b

    /*
    // exemplu cu vector de int
    int src[100] = {1, 2, 3}; // initializat
    int dst[100];                 // neinitializat
    my_memcpy(dst, src, sizeof(src));
    // afisare elemente din vector destinatie

    // exemplu cu vector de double
    int n;
    double src[100];
    // scanf n, src => initializare
    double dst[100];                 // neinitializat
    my_memcpy(dst, src, n * sizeof(double));
    // afisare elemente din vector destinatie'
    */
    return 0;
}
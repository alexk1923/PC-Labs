/*Sa se det numarul prim cel mai apropiat de un numar X, citit de la tastatura.
Daca exista 2 numere care indeplinesc aceasta proprietate, se vor afisa aman2
*/

#include <stdio.h>

int is_prime(int a){
    int d, ok;
    ok = 1;
    for(d=2; d*d<=a && ok==1; d++){
        if(a % d == 0){
            ok = 0;
        }
    }
    return ok;
}

int print_closest_prime(int a){
    
    int i, ok = 0;
    if(is_prime(a)){
        return 0;
    }
    else{
        for(i=1; i < a-1 && ok==0; i++){
            if(is_prime(a+i)){
                printf("%d\n", a+i);
                ok = 1;
            }

            if(is_prime(a-i)){
                printf("%d\n", a-i);
                ok = 1;
            }
        }
    }
    
}
    
           
    

int main(){
    int x;
    scanf("%d", &x);
    print_closest_prime(x);

}
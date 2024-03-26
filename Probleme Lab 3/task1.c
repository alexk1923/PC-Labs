#include <stdio.h>

int power_iterative(int a, int b){
    while(b>0){
        a=a*a;
        b--;
    }
    return a;
}

int power_recursive(int a, int b){
    if(b==1){
        return a;
    }
    else
    {
        return a*power_recursive(a, b-1);
    }
    
}

int power(int a, int b){
    if(b==1){
        return a;
    }
    else{
        if(b%2 == 0)
            return power(a*a, b/2);
        else
        {
            return a * power(a, b-1);
        }
        
    }
    
}


int main(){
    int p1 = power_iterative(2, 3);
    int p2 = power_recursive(7, 3);
    int bonus = power(2, 5);
    printf("%d %d %d", p1, p2, bonus);
    return 0;
}
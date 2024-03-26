#include <stdio.h>


int is_palindrome(int a){
    int  p, copie;
    copie = a;
    p = 0;
    while(copie!=0){
        p=p*10+copie%10;
        copie/=10;
    }
    if(a == p){
        return 1;
    }
    else{
        return 0;
    }
}

int next_palindrome(int a){
    if(is_palindrome(a)){
        return a;
    }
        else
        {
            return next_palindrome(a+1);
        }
        
}
int main(){

    int x;
    scanf("%d", &x);
    printf("%d\n", next_palindrome(x));
    return 0;
}
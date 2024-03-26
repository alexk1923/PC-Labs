#include <stdio.h>

int main(){
    int n,m, mm; //mm copy of m, used to reverse m's digits to obtain the correct number
    m=0;
    scanf("%d", &n);
    while(n > 0){
        m=m*10 + n/10%10;
        n=n/100;
    }
    mm = 0;
    while(m>0)
    {
        mm=mm*10+m%10;
        m/=10;
    }
    printf("%d\n", mm);
    return 0;
}
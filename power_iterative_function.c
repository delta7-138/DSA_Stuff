#include <stdio.h>
#include <stdlib.h>
long long power(int x , int a){
    long long y = 1;
    while(a>0){
        if(a%2==1){
            y = y * x;
        }
        x = x * x;
        a = a/2;
    }
    return y;
}
int main(){
    int a , x;
    scanf("%d %d" , &x , &a);

    long long ans = power(x , a);
    printf("%lld\n" , ans);
    return 0;
}
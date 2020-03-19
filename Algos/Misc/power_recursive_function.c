#include <stdio.h>
#include <stdlib.h>
long long power(int x , int a){
    if(a==0){
        return 1;
    }
    else if(a%2==0){
        return power(x * x , a/2);
    }
    else{
        return x*power(x * x , a/2);
    }
}
int main(){
    int x , a;
    scanf("%d %d" , &x , &a);
    long long ans = power(x , a);

    printf("%lld\n" , ans);
    return 0;
}
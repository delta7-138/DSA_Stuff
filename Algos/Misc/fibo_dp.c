#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000
int fib(int n){
    int fibo_arr[LARGE];
    fibo_arr[0] = 0;
    fibo_arr[1] = 1;

    for(int i = 2; i<=n; i++){
        fibo_arr[i] = fibo_arr[i-1] + fibo_arr[i-2];
    }

    return fibo_arr[n];
}
int main(){
    int n;
    scanf("%d" , &n);

    printf("%d\n" , fib(n));
    return 0;
}
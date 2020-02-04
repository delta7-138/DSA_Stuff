#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
int main(){
    int n;
    scanf("%d" , &n);
    int arr_inp[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    int count_arr[10] = {0};
    int prefix_sum[10] = {0};
    for(int i = 0; i<10 ; i++){
        count_arr[arr_inp[i]]++;
    }

    prefix_sum[0] = count_arr[0];
    for(int i = 1; i<10; i++){
        prefix_sum[i] = prefix_sum[i-1] + count_arr[i-1];
    }

    for(int i = 0; i<10; i++){
        printf("%d %d\n" , count_arr[i] , prefix_sum[i]);
    }
    return 0; 
}
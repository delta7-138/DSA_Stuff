#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000
int main(){
    int arr_inp[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    int count_arr[10] = {0};
    for(int i = 0; i<n; i++){
        count_arr[arr_inp[i]]++;
    }

    // int prefix_sum_arr[10] = {0};
    // prefix_sum_arr[0] = count_arr[0];
    // for(int i = 1; i<10; i++){
    //     prefix_sum_arr[i] = prefix_sum_arr[i-1] + count_arr[i]; 
    // }

    // for(int i = 0; i<n; i++){
    //     printf("%d\n" , prefix_sum_arr[i]);
    // }

    for(int i = 0; i<10; i++){
        while(count_arr[i]!=0){
            printf("%d " , i);
            count_arr[i]--;
        }
    }
    return 0;
}
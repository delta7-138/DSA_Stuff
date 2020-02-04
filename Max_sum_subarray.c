#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000
int main(){
    int arr_inp[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    int max_sum_now = 0 , max_sum_end = 0;
    for(int i = 0; i<n; i++){
        max_sum_end = max_sum_end + arr_inp[i];
        if(max_sum_end<0){
            max_sum_end = 0;
        }
        if(max_sum_end>max_sum_now){
            max_sum_now = max_sum_end;
        }
    }
    printf("%d\n" , max_sum_now);
    return 0;
}
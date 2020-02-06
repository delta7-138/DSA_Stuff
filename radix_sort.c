#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000
int main(){
    int arr_inp[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp);
    }

    int arr_ans[LARGE] = {0};
    int count_arr[10] = {0};
    while(arr_inp[0]!=0){
        for(int i = 0; i<n; i++){
            count_arr[(arr_inp[i]%10)]++;
        }
    }
}
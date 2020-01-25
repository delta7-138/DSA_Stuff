#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000
int arr_ans[LARGE];
void merge(int arr[] , int l , int u, int mid){
    int start = l , end = mid + 1, p = 0;
    
    while(start<=mid && end<=u){
        if(arr[start]<=arr[end]){
            arr_ans[p] = arr[start];
            start++; 
            p++;
        }else{
            arr_ans[p] = arr[end];
            end++;
            p++;
        }
    }

    while(start<=mid){
        arr_ans[p] = arr[start];
        start++;
        p++;
    }
    while(end<=u){
        arr_ans[p] = arr[end];
        end++;
        p++;
    }

    p = 0;
    start = l;

    while(start<=u){
        arr[start] = arr_ans[p];
        start++;
        p++;
    }

    // for(int i = 0; i<6; i++){
    //     printf("%d " , arr_ans[i]);
    // }printf("\n");
}
int merge_sort(int arr[] , int l , int u){
    if(l<u){
        int mid = (l + u)/2;

        merge_sort(arr , l , mid);
        merge_sort(arr , mid + 1 , u);

        merge(arr , l , u , mid);
    }
}
int main(){
    int num_inp;
    scanf("%d" , &num_inp);

    int arr_inp[LARGE];

    for(int i = 0; i<num_inp; i++){
        scanf("%d" , &arr_inp[i]);
    }
    printf("\n");
    merge_sort(arr_inp, 0 , num_inp-1);
    for(int i = 0; i<num_inp; i++){
        printf("%d\n" , arr_ans[i]);
    }
    return 0;
}
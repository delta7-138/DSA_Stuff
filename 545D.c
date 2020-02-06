#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000
long arr_ans[LARGE] = {0};
void merge(long arr[] , int l , int u, int mid){
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
long merge_sort(long arr[] , int l , int u){
    if(l<u){
        int mid = (l + u)/2;

        merge_sort(arr , l , mid);
        merge_sort(arr , mid + 1 , u);

        merge(arr , l , u , mid);
    }
}
int main(){
    long arr_inp[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%ld" , &arr_inp[i]);
    }

    merge_sort(arr_inp , 0 , n-1);

    long prefix_sum[LARGE] = {0};
    prefix_sum[0] = arr_inp[0];

    int ctr_ans = 1;
    
    for(int i = 1; i<n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr_inp[i];
        //printf("%ld\n" , prefix_sum[i]);
    }

    for(int i = 1 , j = 0; i<n; i++ , j++){
        if(prefix_sum[j]<=arr_inp[i]){
            ctr_ans++;
            //printf("hi 1\n");
        }else if(prefix_sum[j]>arr_inp[i] && j>=1 && (prefix_sum[j]-prefix_sum[j-1]<arr_inp[i] - arr_inp[i-1])){
            ctr_ans++;
            //printf("hi 2\n");
        }
    }
    printf("%d" , ctr_ans);
    return 0;
}
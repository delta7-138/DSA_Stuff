#include <stdio.h>
#define LARGE 100000
int arr_ans[LARGE] = {0};
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
    int arr_inp[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }
    
    merge_sort(arr_inp , 0 , n-1);

    int min_diff = 100000;
    for(int i = 1; i<n; i++){
        //printf("%d\n" , arr_inp[i]);
        if(min_diff>arr_inp[i] - arr_inp[i-1]){
            min_diff = arr_inp[i] - arr_inp[i-1];
        }
    }
    printf("%d\n" , min_diff);
    return 0;
}



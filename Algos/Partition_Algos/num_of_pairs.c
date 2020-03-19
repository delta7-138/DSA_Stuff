#include <stdio.h>
#define LARGE 10000
int arr_temp[LARGE] = {0};
int merge(int arr_inp[] , int low , int mid , int upp){
    int start = low , end =  mid + 1 , p = 0;
    while(start<=mid && end<=upp){
        if(arr_inp[start]<=arr_inp[end]){
            arr_temp[p] = arr_inp[start];
            start++;
            p++;
        }else{
            arr_temp[p] = arr_inp[end];
            end++;
            p++;
        }
    }

    while(start<=mid){
        arr_temp[p] =arr_inp[start];
        start++;
        p++;
    }

    while(end<=upp){
        arr_temp[p] = arr_inp[end];
        end++;
        p++;
    }

    start = low;
    p = 0;

    while(start<=upp){
        arr_inp[start] = arr_temp[p];
        start++;
        p++;
    }
    // for(int i = 0; i<5; i++){
    //     printf("%d " , arr_inp[i]);
    // }printf("\n");
}
int merge_sort(int arr_inp[] , int low , int upp){
    if(low<upp){
        int mid = (low + upp)/2;

        merge_sort(arr_inp ,  low , mid);
        merge_sort(arr_inp , mid + 1 , upp);

        merge(arr_inp , low , mid , upp);
    }
}
int main(){
    int arr_inp[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }
    int k;
    scanf("%d" , &k);
    merge_sort(arr_inp, 0 , n-1);
    
    int l = 0 , r = 1 , ctr = 0;
    while(l<=n-1 && r<=n-1){
        int diff = arr_inp[r] - arr_inp[l];
        if(diff<k){
            r++;
        }else if(diff==k){
            ctr++;
            l++;
        }else{
            l++;
        }
    }
    printf("%d\n" , ctr);
    return 0;
}

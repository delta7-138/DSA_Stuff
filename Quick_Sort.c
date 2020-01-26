#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
int swap(int *a , int *b){
    int *tmp = a;
    *a = *b;
    *b = *tmp;
}
int partition(int arr[] , int l , int u , int piv){
    int start = l , end = u, k;
    while(start<=end){
        while(start<=end && arr[start]<=piv){
            start++;
        }
        while(start<=end && arr[end]>piv){
            end--;
        }
        if(start<=end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    k = start-1;
    arr[l-1] = arr[k];
    arr[k] = piv;

    // for(int i = 0; i<6; i++){
    //     printf("%d " , arr[i]);
    // }printf("\n");
    // return k;
}
int rand_quick_sort(int arr[] , int l , int u){
    if(l<u){
        // int p = (rand() % (u - l + 1)) + l;
        // printf("%d\n" , p);
        // int temp = arr[p];
        // arr[p] = arr[l];
        // arr[l] = temp;

        int k = partition(arr , l+1 , u , arr[l]);

        rand_quick_sort(arr , l , k-1);
        rand_quick_sort(arr , k + 1 , u);
    }
}
int main(){
    int arr_inp[LARGE];
    int num_inp;
    scanf("%d" , &num_inp);

    for(int i = 0; i<num_inp; i++){
        scanf("%d" , &arr_inp[i]);
    }
    rand_quick_sort(arr_inp , 0 , num_inp-1);

    for(int i = 0; i<num_inp; i++){
        printf("%d " , arr_inp[i]);
    }printf("\n");
    return 0;
}
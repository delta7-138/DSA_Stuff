#include <stdio.h>
#define LARGE 10000
int partition(int arr[],  int low , int upp , int piv){
    int start = low , end = upp;
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
    int k = start-1;
    arr[low-1] = arr[k];
    arr[k] = piv;

    return k;
}
int Find_Rank(int arr[] , int l , int u , int r){
    if(l<u){
        int k = partition(arr , l+1 , u , arr[l]);
        if(r==u-k + 1)
            return arr[k];
        else if(r<u-k+1){
            return Find_Rank(arr , k+1 , u , r);
        }
        else{
            return Find_Rank(arr , l , k , r);
        }
    }return -1;
}
int main(){
    int arr[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    int r;
    scanf("%d" , &r);

    printf("%d\n" , Find_Rank(arr , 0 , n-1 , r));
}
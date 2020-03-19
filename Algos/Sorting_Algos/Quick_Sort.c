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
int quick_sort(int arr[] , int low , int upp){
    if(low<upp){
        int p = partition(arr , low+1 , upp , arr[low]);
        quick_sort(arr , low , p-1);
        quick_sort(arr , p+1 , upp);
    }
}
int main(){
    int arr[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    quick_sort(arr , 0 , n-1);

    //printing sorted array
    for(int i = 0; i<n; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
    return 0;
}

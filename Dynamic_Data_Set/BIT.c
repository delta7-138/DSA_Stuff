//Binary Indexed Trees
// Used to compute Range Sums while preserving both memory and time
// Pre Processing time complexity O(nlogn)
// RSQ Time complexity is O(logn)
// Test Case : 9
// 4
// 3
// 2
// -1
// -2
// 6
// -3
// 7
// 4

#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
void increase(int arr[] , int i , int x, int n){
    while(i<=n){
        arr[i] = arr[i] + x;
        i = i + (i&(-i));
    }
}

int prefix_sum(int arr[] , int i , int n){
    int sum = 0;
    while(i>0){
        sum = sum + arr[i];
        i = i - (i & (-i));
    }
    return sum;
}

int main(){
    int n;
    scanf("%d" , &n);

    int arr_inp[LARGE];

    for(int i = 1; i<=n; i++){
        arr_inp[i] = 0;
    }
    int inp;
    for(int i = 1; i<=n; i++){
        scanf("%d" , &inp);
        increase(arr_inp , i , inp , n);
    }

    // int i;
    // scanf("%d" , &i);

    // printf("%d\n" , prefix_sum(arr_inp , i , n));

    int lb , ub;
    printf("Enter the lower bound for Range Sum Query : ");
    scanf("%d" , &lb);
    printf("Enter the upper bound for Range Sum Query : ");
    scanf("%d" , &ub);

    int ans = prefix_sum(arr_inp , ub , n) - prefix_sum(arr_inp , lb-1 , n);

    printf("%d\n" , ans);
    return 0;
}
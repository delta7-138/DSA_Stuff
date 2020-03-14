#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
void build_tree(int segment_tree[] , int arr[] , int n){
    for(int i = 0; i<n; i++){
        segment_tree[n + i - 1] = i;
    }

    for(int i = n-2; i>=0; i--){
        //printf("%d %d \n" , arr[segment_tree[2 * i + 1]] , arr[segment_tree[2 * i + 2]]);
        if(arr[segment_tree[2 * i + 1]]>arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
    }
}

void update_node(int segment_tree[] , int arr[] , int i ,  int x , int n){
    arr[i] = x;

    i = (n-1 + i - 1)/2;

    while(i>=0){
        if(arr[segment_tree[2 * i + 1]]>arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
        //printf("%d\n" , i);

        i = (i-1)/2;
        if(i<1){
            break;
        }
    }
}

int RMQ(int seg_tree[] , int arr_inp[] , int i , int j , int s , int e , int n , int p){
    if(j<s || e<i){
        return n;
    }else if(i<=s && j>=e){
        return seg_tree[p];
    }
    int m = (s + e)/2;
    int l1 = RMQ(seg_tree , arr_inp, i , j , s , m , n , 2 *p + 1);
    int l2 = RMQ(seg_tree , arr_inp , i , j , m+1 , e , n , 2 * p + 2);

    if(arr_inp[l1]<arr_inp[l2]){
        return l1;
    }else{
        return l2;
    }
}

int main(){
    int n;
    scanf("%d" , &n);

    int arr_inp[LARGE] = {0};
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    for(int i = n; i<LARGE ; i++){
        arr_inp[i] = 1000;
    }

    int seg_tree[LARGE * 2 + 1];
    build_tree(seg_tree , arr_inp , n);

    // for(int i = 0; i<2 * n-1; i++){
    //     printf("%d " , seg_tree[i]);
    // }printf("\n");
    printf("Enter lower bound of Range : ");
    int lb;
    scanf("%d" , &lb);
    printf("Enter upper bound of Ramge : ");
    int ub;
    scanf("%d" , &ub);

    int ans = arr_inp[RMQ(seg_tree , arr_inp , lb , ub , 0 , n-1 , n , 0)];

    printf("%d" , ans);

    return 0;
    
}
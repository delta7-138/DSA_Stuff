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

int main(){
    int n;
    scanf("%d" , &n);

    int arr_inp[LARGE] = {0};
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    
    int seg_tree[LARGE * 2 + 1] = {0};
    build_tree(seg_tree , arr_inp , n);

    for(int i = 0; i<2 * n-1; i++){
        printf("%d " , seg_tree[i]);
    }printf("\n");

    update_node(seg_tree , arr_inp , 6 , 14 , n);

    for(int i = 0; i<2 * n-1; i++){
        printf("%d " , seg_tree[i]);
    }printf("\n");
    return 0;
}
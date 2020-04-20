#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LARGE 10000
int power(int x , int a){
    long long y = 1;
    while(a>0){
        if(a%2==1){
            y = y * x;
        }
        x = x * x;
        a = a/2;
    }
    return y;
}

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
        if(i<1){
            break;
        }
        i = (i-1)/2;
    }
}

int next_Right_min(int arr[] , int seg_arr[] , int i , int n){

    int p = 0 , s = 0 , e = n-1 , m = 0 , j = n;
    //printf("\n");
    //printf("\n%d " , p);
    while(p<n-1){
        m = (s + e)/2;
        //printf("%d " , p);
        if(i<=m){
            if(arr[seg_arr[2*p + 2]]<arr[i]){
                j = 2*p + 2;
            }
            p =2 * p + 1;
            e = m;
        }else{
            p = 2 * p + 2;
            s = m + 1;
        }
        //printf("%d %d\n" , p , j);
        //printf("%d " , j);
    }
    //printf("%d" , j);

    while(j<n-1){
        if(arr[seg_arr[2 * j + 1]]<arr[i]){
            j = 2 * j + 1;
        }else{
            j = 2 * j + 2;
        }
    }
    //printf("%d\n" , j);
    return seg_arr[j];
}

int next_Right_max(int arr[] , int seg_arr[] , int i , int n){

    int p = 0 , s = 0 , e = n-1 , m = 0 , j = n;
    //printf("\n");
    //printf("\n%d " , p);
    while(p<n-1){
        m = (s + e)/2;
        //printf("%d " , p);
        if(i<=m){
            if(arr[seg_arr[2*p + 2]]>=arr[i]){
                j = 2*p + 2;
            }
            p =2 * p + 1;
            e = m;
        }else{
            p = 2 * p + 2;
            s = m + 1;
        }
        //printf("%d %d\n" , p , j);
        //printf("%d " , j);
    }
    //printf("%d" , j);

    while(j<n-1){
        if(arr[seg_arr[2 * j + 1]]>=arr[i]){
            j = 2 * j + 1;
        }else{
            j = 2 * j + 2;
        }
    }
    //printf("%d\n" , j);
    return seg_arr[j];
}

int main(){
    int n;
    scanf("%d" , &n);

    int arr_inp[LARGE];

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }
    int size = n;
    //Segment of code to add dummy variables
    if(log2(n) - n!=0){
        n = power(2 , (int)(ceil(log2(n))));
    }
    
    for(int i = size; i<LARGE; i++){
        arr_inp[i] = 1000;
    }
    
    int seg_tree[LARGE * 2 + 1] = {0};
    build_tree(seg_tree , arr_inp , n);

    printf("Enter index : ");
    int ind;
    scanf("%d" , &ind);

    // for(int i = 0; i<2 * n- 1; i++){
    //     printf("%d " , seg_tree[i]);
    // }

    printf("%d" , arr_inp[next_Right_min(arr_inp ,seg_tree , ind , n)]);
    return 0;

}
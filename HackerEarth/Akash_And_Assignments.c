#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LARGE 1000000

int power(int x , int a){
    int y = 1;
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

int main(){
    int n;
    scanf("%d" , &n);

    int q;
    scanf("%d" , &q);
    char str[LARGE];
    scanf("%s" , str);

    int arr_eq[LARGE];
    for(int i = 0; i<n; i++){
        arr_eq[i] = (int)(str[i]);
    }

    for(int i = n; i<LARGE; i++){
        arr_eq[i] = 1000;
    }

    //Segment of code the push in the dummy values
    if(log2(n)-n!=0){
        n = power(2 , (int)(ceil(log2(n))));        
    }

    //printf("%d" , n);
    int seg_arr[LARGE];

    build_tree(seg_arr , arr_eq , n);

    int op;
    int ind , lb , ub , k;

    char c;

    for(int i = 0; i<q; i++){
        scanf("%d" , &op);
        switch(op){
            case 0:
            scanf("%d" , &ind);
            scanf("%c" , &c);
           // update_node(seg_arr , arr_eq , ind , (int)(c) , n);
            break;

            case 1:
            scanf("%d" , &lb);
            scanf("%d" , &ub);
            scanf("%d" , &k);
            break;
        }
    }    
    return 0;
}
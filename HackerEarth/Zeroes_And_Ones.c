#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000000
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

void traverse_tree(int arr_inp[] , int n){
    for(int i = 1; i<=n; i++){
        printf("%d " , arr_inp[i]);
    }printf("\n");
}

int main(){
    int n;
    scanf("%d" , &n);
    int arr_inp[LARGE];
    for(int i = 1; i<=n; i++){
        arr_inp[i] = 0;
    }

    for(int i = 1; i<=n; i++){
        increase(arr_inp , i , 1 , n);
    }

    int t;
    scanf("%d" , &t); 

    int op, data, flag = 0 , index = 1 , lb , ub;
    for(int i = 0; i<t; i++){
        scanf("%d" , &op);
        scanf("%d" , &data);
        switch(op){
            case 0:
            increase(arr_inp , data+1 , -1 , n);
            //traverse_tree(arr_inp , n);
            break;

            case 1:
            //traverse_tree(arr_inp , n);
            lb = 1;
            ub = n;
            index = 1;
            flag = 0;
            while(lb<=ub){
                int mid = (lb + ub)/2;
                if(prefix_sum(arr_inp , mid  , n)>data){
                    ub = mid - 1;
                }else if(prefix_sum(arr_inp , mid , n)<data){
                    lb = mid + 1;
                }else{
                    index = mid;
                    break;
                }
            }
            printf("%d\n" , index);
            break;
        }
    }
    return 0;
}
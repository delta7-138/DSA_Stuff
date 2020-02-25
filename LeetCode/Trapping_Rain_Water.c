#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
int pop(int stack[] , int *top){
    *top = *top - 1;
    return stack[*top + 1];
}

int push(int stack[] , int *top , int x){
    stack[++(*top)] = x;
}

void traverse_stack(int stack[] , int top){
    for(int i = 0; i<=top; i++){
        printf("%d " , stack[i]);
    }
    printf("\n");
}

int min(int a , int b){
    if(a<b){
        return a;
    }
    return b;
}

int main(){
    int arr_inp[LARGE] = {0};

    int left_max[LARGE];
    int right_max[LARGE];

    int n;
    scanf("%d" , &n);
    

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    int top_left = -1 , top_right = -1;
    int left_pointer = 0 , right_pointer = n-1;

    while(left_pointer<=n-1 && right_pointer>=0){
        if(top_left<0 || arr_inp[left_pointer]>=left_max[top_left]){
            push(left_max , &top_left , arr_inp[left_pointer]);
        }else{
            push(left_max , &top_left , left_max[top_left]);
        }

        if(top_right<0 || arr_inp[right_pointer]>=right_max[top_right]){
            push(right_max , &top_right  , arr_inp[right_pointer]);
        }else{
            push(right_max , &top_right , left_max[top_right]);
        }

        left_pointer++;
        right_pointer--;
    }

    //traverse_stack(left_max , top_left);
    //traverse_stack(right_max , top_right);

    int sum_ans = 0;
    for(int i = 0; i<n; i++){
       sum_ans = sum_ans + min(left_max[i] , right_max[i]) - arr_inp[i];
    }

    printf("%d" , sum_ans);
    return 0;
}
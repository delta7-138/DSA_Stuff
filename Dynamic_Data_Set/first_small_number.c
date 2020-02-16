#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000

int pop(int stack[] , int *top){
    *top = *top - 1;
    return stack[*top + 1];
}

int push(int stack[] , int *top , int x){
    stack[++(*top)] = x;
}

void traverse_stack(int stack[] , int top){
    for(int i = 0; i<=top; i++){
        printf("%d\n" , stack[i]);
    }
}

int main(){
    int stack[LARGE] = {0};
    int top = -1;

    int arr_inp[LARGE];
    int n, ind;
    scanf("%d" , &n);
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    int arr_ans[LARGE];
    for(int i = 0; i<n; i++){
        if(top<0){
            push(stack , &top , i);
        }else if(arr_inp[stack[top]]<arr_inp[i]){
            push(stack , &top , i);
        }else{
            while(top>=0 && arr_inp[stack[top]]>=arr_inp[i]){
                ind = pop(stack , &top);
                arr_ans[ind] = i;
            }
            push(stack , &top , i);
        }
    }
    for(int i = 0; i<n; i++){
        if(arr_ans[i]==0){
            printf("-1 ");
            continue;
        }
        printf("%d ", arr_ans[i]);
    }printf("\n");
    
    return 0;
}
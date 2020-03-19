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
    int stack[LARGE];
    int n;

    printf("Enter initial stack size : \n");
    scanf("%d" , &n);
    for(int i = 0; i<n; i++){
        scanf("%d" , &stack[i]);
    }
    int num_op;
    printf("Enter number of operations : \n");
    scanf("%d" , &num_op);
    
    int top = n-1;
    int op, data;
    for(int ctr = 0; ctr<num_op; ctr++){
        printf("Enter your choice : \n");
        printf("1. pop\n");
        printf("2. push\n");

        scanf("%d" , &op);
        switch(op){
            case 1: 
            pop(stack , &top);
            break;

            case 2:
            scanf("%d" , &data);
            push(stack , &top , data);
            break;

            default:
            traverse_stack(stack , top);        
        }
        traverse_stack(stack , top);
    }
    return 0;
}
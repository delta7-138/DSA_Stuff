#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

//stack functions
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

int main(){
    int n;
    scanf("%d" , &n);
    
    int pushed[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &pushed[i]);
    }

    int popped[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &popped[i]);
    }

    int top_pushed = -1 , top_popped = -1;
    int pushed_stack[LARGE] = {0};
    int popped_stack[LARGE] = {0};

    for(int i = 0; i<n; i++){
        push(popped_stack , &top_popped , popped[n - i - 1]);
    }
    
    int i = 0;
    do{
        while(pushed_stack[top_pushed]!=popped_stack[top_popped] && i<n){
            push(pushed_stack , &top_pushed , pushed[i]);
            i++;
        }
        

        //traverse_stack(pushed_stack , top_pushed);

        if(pushed_stack[top_pushed]==popped_stack[top_popped]){
            pop(popped_stack , &top_popped);
            pop(pushed_stack , &top_pushed);
        }else{
            break;
        }
        //traverse_stack(popped_stack , top_popped);

    }while(top_pushed>-1 && top_popped>-1);

    if(top_pushed<0 && top_popped<0){
        printf("true\n");
    }else{
        printf("false\n");
    }

    return 0;
}
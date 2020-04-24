#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGE 10000

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

struct Node *node_stack[LARGE];
int stack_top = -1;
//Stack functions 

struct Node *pop(struct Node *stack[] , int *top){
    *top = *top - 1;
    return stack[*top + 1];
}

struct Node *push(struct Node *stack[] , int *top ,struct Node *x){
    stack[++(*top)] = x;
}

void traverse_stack(struct Node *stack[] , int top){
    for(int i = 0; i<=top; i++){
        if(stack[i]){
            printf("%d " , stack[i]->data);
        }
    }printf("\n");
}

int string_to_int(char *str){
    int ans = 0;
    int fleg = 0;
    int len = strlen(str);

    if(str[0]=='-'){
        fleg++;
    }

    for(int i = 0; i<len; i++){
        if(i==0 && fleg){
            continue;
        }
        ans = ans * 10 + str[i] - '0';
    }
    if(fleg){
        ans = -ans;
    }
    return ans;
}

void pop_instack(struct Node *root){
    if(root){
        pop_instack(root->lc);
        push(node_stack , &stack_top , root);
        pop_instack(root->rc);
    }
}

void inorder_traversal(struct Node *root){
    if(root){
        inorder_traversal(root->lc);
        printf("%d " , root->data);
        inorder_traversal(root->rc);
    }
}

int main(){
    int n;
    scanf("%d" , &n);

    struct Node *tree[LARGE];
    printf("Enter the level order traversal of the binary search tree : \n");

    for(int i = 0; i<n; i++){
        char inp[LARGE];
        scanf("%s" , inp);
        if(strcmp(inp , "null")==0){
            tree[i] = NULL;
        }else{
            tree[i] = (struct Node *)malloc(sizeof(struct Node));
            tree[i]->data = string_to_int(inp);
        }
    }

    for(int i = 0; i<n; i++){
        if(tree[i]){
            tree[i]->lc = tree[2 * i + 1];
            tree[i]->rc = tree[2 * i + 2];
        }
    }
    pop_instack(tree[0]);
    struct Node *arr[] = {NULL , NULL};

    //-2 0 1 4 5 6 ; 4 0 1 -2 5 6 
     int ctr = 0, ind = 0;
    for(int i = 0; i<stack_top; i++){

         if(node_stack[i]->data > node_stack[i+1]->data){
             if(ctr==1){
                 arr[1] = node_stack[i+1];
             }else{
                 arr[0] = node_stack[i];
                 ind = i;
                 ctr++;
             }
         }
     }

    traverse_stack(node_stack , stack_top);
    if(arr[0]==NULL || arr[1] == NULL){
         struct Node *tempnode = node_stack[ind+1];

         int temp = tempnode->data;
         tempnode->data = arr[0]->data;
         arr[0]->data = temp;
     }else{
         int temp = arr[0]->data;
         arr[0]->data = arr[1]->data;
         arr[1]->data = temp;
     }

    inorder_traversal(tree[0]);
    printf("\n");
    return 0;
}
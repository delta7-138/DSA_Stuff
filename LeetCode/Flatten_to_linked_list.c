#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LARGE 1000

//Only for CBT plus uses recursive calling 
struct Node{
    char data[LARGE];
    struct Node *par;
    struct Node *lc;
    struct Node *rc;
    int level;
    int height;
};

//Stack Functions 
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

//Tree Functions
void preorder_traversal(struct Node *node){
    if(node){
        if(strcmp(node->data , "null")!=0){
            printf("%s " , node->data); 
        }
        preorder_traversal(node->lc);
        preorder_traversal(node->rc);
    }//printf("\n");
}

void postorder_traversal(struct Node *node){
    if(node){
        postorder_traversal(node->lc);
        postorder_traversal(node->rc);
        printf("%d " , node->data);
    }//printf("\n");
}

void inorder_traversal(struct Node *node){
    if(node){
        inorder_traversal(node->lc);
        printf("%d " , node->data);
        inorder_traversal(node->rc);
    }//printf("\n");
}

int main(){
    struct Node *tree[LARGE]; 
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        tree[i] = (struct Node *)malloc(sizeof(struct Node));
        scanf("%s" , tree[i]->data);
    }

    for(int i = 0; i<n; i++){
        if(i!=0){
            tree[i]->par = tree[(i-1)/2];
        }else{
            tree[i]->par = NULL;
        }
        tree[i]->lc = tree[2 * i + 1];
        tree[i]->rc = tree[2 * i + 2];
    }

    preorder_traversal(tree[0]);
    return 0;
}
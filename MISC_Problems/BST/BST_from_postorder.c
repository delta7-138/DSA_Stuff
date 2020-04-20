#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

//Defintion of node in a BST can be modified to contain parent pointer or other data
struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

//Function to create a new node 
struct Node *createnode(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->lc = NULL;
    newnode->rc = NULL;

    return newnode;
}

struct Node *insert(struct Node *root , int data){
    if(root==NULL){
        root = createnode(data);
        return root;
    }

    if(root->data>data){
        root->lc = insert(root->lc , data);
        return root;
    }
    if(root->data<data){
        root->rc = insert(root->rc , data);
        return root;
    }
    return root;
}

void preorder_traversal(struct Node *node){
    if(node){
        printf("%d " , node->data);
        preorder_traversal(node->lc);
        preorder_traversal(node->rc);
    }
}

void inorder_traversal(struct Node *node){
    if(node){
        inorder_traversal(node->lc);
        printf("%d " , node->data);
        inorder_traversal(node->rc);
    }
}

//Stack functions
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
    printf("Enter the number of elements : \n");
    int n;
    scanf("%d" , &n);

    printf("Enter the postorder traversal : \n");
    int stack_elements[LARGE];

    int top_stack = -1;
    int inp;

    for(int i = 0; i<n; i++){
        scanf("%d" , &inp);
        push(stack_elements , &top_stack , inp);
    }
    
    struct Node *root = NULL;

    while(top_stack>=0){
        root = insert(root , stack_elements[top_stack]);
        pop(stack_elements , &top_stack);
    }

    printf("Preorder Traversal : ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder Traversal : ");
    inorder_traversal(root);
    printf("\n");
    return 0;
}


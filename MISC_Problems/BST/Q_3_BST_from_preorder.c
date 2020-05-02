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

void inorder_traversal(struct Node *node){
    if(node){
        inorder_traversal(node->lc);
        printf("%d " , node->data);
        inorder_traversal(node->rc);
    }//printf("\n");
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

int main(){
    printf("Enter the number of nodes : \n");
    int n;
    scanf("%d" ,&n);

    int preorder[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &preorder[i]);
    }

    struct Node *root = NULL;
    for(int i = 0; i<n; i++){
        root = insert(root , preorder[i]);
    }
    inorder_traversal(root);
    return 0;
}
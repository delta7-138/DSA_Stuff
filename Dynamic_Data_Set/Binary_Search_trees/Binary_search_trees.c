//Program to implement a BST 
// addition deletion all takes o(h) where h is the height of the tree
// h could be O(logn) in case of a balanced binary tree
// For which AVL trees are used this is an example of a normal BST
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
}

int main(){
    int n;
    scanf("%d" , &n);

    int arr_inp[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    struct Node *root = NULL;
    for(int i = 0; i<n; i++){
        root = insert(root , arr_inp[i]);
    }

    printf("%d\n" , root->data);
    return 0;
}
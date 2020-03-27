#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

struct Node *createnode(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->lc = NULL;
    newnode->rc = NULL;

    return newnode;
}

struct Node *create_tree(struct Node *root , int data){
    if(root==NULL){
        return createnode(data);
    }else{
        if(root->data<data){
            root->lc = create_tree(root->lc , data);
        }
        if(root->data>data){
            root->rc = create_tree(root->rc , data);
        }
        return root;
    }
}

int main(){
    int n;
    scanf("%d" , &n);

    int data;
    scanf("%d" , &data);

    struct Node *head = NULL;
    head = create_tree(head , data);

    for(int i = 1; i<n; i++){
        
    }
}
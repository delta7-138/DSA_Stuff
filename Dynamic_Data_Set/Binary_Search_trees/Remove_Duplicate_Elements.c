/* Program to Remove duplicate elements from an array
it does so in O(nh) time since it takes O(h) for addition and O(n) for all nodes where h is the height of the tree
it ignores the element if it is equal to the key of the root
Therefore it 
*/
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

void inorder_traversal(struct Node *node){
    if(node){
        inorder_traversal(node->lc);
        if(node->data!=0){
            printf("%d " , node->data);
        }
        inorder_traversal(node->rc);
    }//printf("\n");
}

int main(){
    int n;
    scanf("%d" , &n);

    int arr[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    struct Node *root = (struct Node *)malloc(sizeof(struct Node));

    for(int i = 0; i<n; i++){
        root = insert(root , arr[i]);
    }

    inorder_traversal(root);

    return 0;
}
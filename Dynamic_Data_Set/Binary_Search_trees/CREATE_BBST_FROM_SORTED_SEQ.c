#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

struct Node{
    int key;
    struct Node *lc;
    struct Node *rc;
};

struct Node *newnode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->lc = NULL;
    node->rc = NULL;
    node->key = data;

    return node;
}

struct Node *Create_BBST(int arr[], int low , int upp){
    struct Node *root = NULL;
    if(low<=upp){
        int mid = (low + upp)/2;

        root = newnode(arr[mid]);

        root->lc = Create_BBST(arr , low , mid-1);
        root->rc = Create_BBST(arr , mid + 1 , upp);
    }    
    return root;
}

void preorder_traversal(struct Node *node){
    if(node){
        printf("%d " , node->key); 
        preorder_traversal(node->lc);
        preorder_traversal(node->rc);
    }//printf("\n");
}


int main(){
    printf("Enter the number of entries : ");
    int n;
    scanf("%d" , &n);

    int arr[LARGE];
    struct Node *root = NULL;
    printf("Enter entries in sorted order : ");

    for(int i = 0; i<n ; i++){
        scanf("%d" , &arr[i]);
    }

    root = Create_BBST(arr , 0 , n-1);
    printf("%d\n" , root->key);   

    preorder_traversal(root);
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000

//Only for CBT plus uses recursive calling 
struct Node{
    int data;
    struct Node *par;
    struct Node *lc;
    struct Node *rc;
    int level;
    int height;
};

void preorder_traversal(struct Node *node){
    if(node){
        printf("%d " , node->data); 
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
        scanf("%d" , )
    }
}
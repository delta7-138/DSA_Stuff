#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000
struct Node{
    int data;
    struct Node *par;
    struct Node *lc;
    struct Node *rc;
    int level;
    int height;
};

//Tree Functions
void preorder_traversal(struct Node *tree[]){

}

void postorder_traversal(struct Node *tree[]){

}

void inorder_traversal(struct Node *tree[]){

}

int main(){
    struct Node *tree[LARGE]; 
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        tree[i] = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d" , &(tree[i]->data));
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

    return 0;
}   
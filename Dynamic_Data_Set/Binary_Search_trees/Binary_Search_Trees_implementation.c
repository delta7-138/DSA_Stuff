#include <stdio.h>
#include <stdlib.h>
struct Node{
    int key;
    struct Node *lc;
    struct Node *rc;
    struct Node *par; 
};

struct Node *insert(struct Node *root , int key){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if(root==NULL){
        new_node->par = NULL;
        new-node->lc = NULL;
        new_node->rc = NULL;
        new_node->key = key;
        return new_node;
    }
    while((root->lc)!=NULL && (root->rc)!=NULL)){
        if((root->lc)->key>key
    }
}
int main(){
    
}
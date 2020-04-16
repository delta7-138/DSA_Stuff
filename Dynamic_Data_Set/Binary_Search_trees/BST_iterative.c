#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

struct Node{
    int key;
    struct Node *lc;
    struct Node *rc;
    struct Node *par;
};

//Utility Functions 

struct Node *newnode(int key){
    struct Node *newn = (struct Node *)malloc(sizeof(struct Node));
    newn->key = key;
    newn->lc = NULL;
    newn->rc = NULL;
    newn->par = NULL;

    return newn;
}

struct Node *search(struct Node *root , int key){
    struct Node *tmp = root;

    while(tmp!=NULL){
        if(tmp->key==key){
            return tmp;
        }else if(tmp->key>key){
            tmp = tmp->lc;
        }else{
            tmp = tmp->rc;
        }
    }
    return NULL;
}

struct Node *insert(struct Node **root , int key){

}

int main(){
    return 0;
}
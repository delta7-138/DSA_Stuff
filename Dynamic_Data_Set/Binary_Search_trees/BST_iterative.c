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

struct Node *insert(struct Node **node , int key){
    if(*node==NULL){
        *node = newnode(key);
        return *node;
    }

    else{
        int flag = 1;
        struct Node *temp = *node;

        while(flag){
            if(temp->data > key){
                if(temp->lc!=NULL){
                    temp = temp->lc;
                }else{
                    temp->lc = newnode(key);
                    temp->lc->par = temp;
                    return temp->lc;

                    flag = 0;
                }
            }else if(temp->data < key){
                if(temp->rc!=NULL){
                    temp = temp->rc;
                }else{
                    temp->rc = newnode(key);
                    temp->rc->par = temp;
                    return temp->rc;

                    flag = 0;
                }
            }
        }
    }


}

int main(){
    return 0;
}
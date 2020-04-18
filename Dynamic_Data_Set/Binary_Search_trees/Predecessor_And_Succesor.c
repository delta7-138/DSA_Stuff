#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
    struct Node *par;
};

struct Node *newnode(int key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->lc = NULL;
    node->rc = NULL;
    node->par = NULL;

    return node;
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

struct Node *Predecessor(struct Node *node){
    if(node==NULL){
        return node;
    }else{
        if(node->lc){
            node = node->lc;
            while(node->rc){
                node = node->rc;
            }
            return node;
        }
        else{
            while(node->par){
                if(node->par->rc==node){
                    return node->par;
                }else{
                    node = node->par;
                }
            }
            return node->par;
        }
    }
}

struct Node *Successor(struct Node *node){
    if(node==NULL){
        return node;
    }else{
        if(node->rc){
            node = node->rc;
            while(node->lc){
                node = node->lc;
            }
            return node;
        }else{
            while(node->par){
                if(node->par->lc==node){
                    return node->par;
                }else{
                    node = node->par;
                }
            }
            return node->par;
        }
    }
}

struct Node *search(struct Node *root , int data){
    if(root==NULL){
        return NULL;
    }

    if(root->data > data){
        return search(root->lc , data);
    }
    
    if(root->data < data){
        return search(root->rc , data);
    }

    if(root->data==data){
        return root;
    }
}

int main(){
    int n;
    scanf("%d" , &n);

    int arr[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    struct Node *root = NULL;

    for(int i = 0; i<n; i++){
        insert(&root , arr[i]);    
    }

    int num;
    scanf("%d" , &num);

    struct Node *node = search(root , num);

    struct Node *pred = Predecessor(node);
    struct Node *succ = Successor(node);

    printf("Predecessor : %d\n" , pred->data);
    printf("Successor   : %d" , succ->data);
    return 0;
}

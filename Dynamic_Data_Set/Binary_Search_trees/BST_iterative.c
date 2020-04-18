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
            if(temp->key > key){
                if(temp->lc!=NULL){
                    temp = temp->lc;
                }else{
                    temp->lc = newnode(key);
                    temp->lc->par = temp;
                    return temp->lc;

                    flag = 0;
                }
            }else if(temp->key < key){
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
void *DeleteNode(struct Node **root , struct Node *node){
    if(node->lc!=NULL && node->rc!=NULL){
        struct Node *temp = node->lc;

        while(temp->rc!=NULL){
            temp = temp->rc;
        }
        node->key = temp->key;
        node = temp;
    }
    struct Node *par = node->par, *child;
    if(node->lc!=NULL){
        child = node->lc;
    }else{
        child = node->rc;
    }

    if(*root==node){
        *root = child;
    }
    if(child!=NULL){
        child->par = par;
    }
    if(par!=NULL){
        if(par->lc==node){
            par->lc = child;
        }else{
            par->rc = child;
        }
    }

    free(node);
}

void Delete(struct Node **root , int data){
    struct Node *temp = *root;

    while(temp!=NULL){
        if(temp->key==data){
            DeleteNode(root , temp);
        }else if(temp->key>data){
            temp = temp->lc;
        }else{
            temp = temp->rc;
        }
    }
}

void preorder_traversal(struct Node *node){
    if(node){
        printf("%d " ,node->key);
        preorder_traversal(node->rc);
        preorder_traversal(node->lc);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d" , &n);

    int arr[LARGE];

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    struct Node *root = NULL;

    for(int i = 0; i<n; i++){
        insert(&root , arr[i]);
    }

    int op;
    int key;

    int q;
    printf("Enter number of queries: ");
    printf("\n1 for add and 2 for delete\n");

    scanf("%d" , &q);

    for(int i = 0; i<q; i++){
        scanf("%d" , &op);
        switch(op){
            case 1:
            scanf("%d" , &key);
            insert(&root , key);
            break;

            case 2:
            scanf("%d" , &key);
            Delete(&root , key);
            break;
        }
        preorder_traversal(root);
        printf("\n");
    }
    return 0;
}
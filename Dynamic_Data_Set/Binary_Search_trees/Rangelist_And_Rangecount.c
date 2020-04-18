#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

//Defintion of node in a BST can be modified to contain parent pointer or other data
struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

//Definition of Linked List of Nodes
struct LinNode{
    struct Node *node; 
    struct LinNode *next;
};

//Function to create a new node 
struct Node *createnode(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->lc = NULL;
    newnode->rc = NULL;

    return newnode;
}

//Function to give inorder successor
struct Node *minNode(struct Node *node){
    struct Node *tmp = node;
    while(tmp!=NULL && tmp->lc!=NULL){
        tmp = tmp->lc;
    }

    return tmp;
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

struct Node *delete(struct Node *root , int data){
    if(root==NULL){
        return NULL;
    }

    if(data<root->data){
        root->lc = delete(root->lc , data);
    }else if(data>root->data){
        root->rc = delete(root->rc , data);
    }else{
        //If node has one child or no children 
        if(root->lc==NULL){
            struct Node *tmp = root->rc;
            free(root);
            return tmp;
        }else if(root->rc==NULL){
            struct Node *tmp = root->lc;
            free(root);
            return tmp;
        }
        //If node has two children 
        struct Node *tmp = minNode(root->rc);
        root->data = tmp->data;
        root->rc = delete(root->rc ,  tmp->data);
    }
    return root;
}

void inorder_traversal(struct Node *node){
    if(node){
        inorder_traversal(node->lc);
        printf("%d " , node->data);
        inorder_traversal(node->rc);
    }//printf("\n");
}

void preorder_traversal(struct Node *node){
    if(node){
        printf("%d " , node->data);
        preorder_traversal(node->lc);
        preorder_traversal(node->rc);
    }
}

//Linked List Functions

void traverse_list(struct LinNode *List){
    while(List!=NULL){
        printf("%d-->" , List->node->data);
        List = List->next;
    }
    printf("NULL\n");
}

//RANGELIST AND RANGECOUNT FUCNTIONS

void Rangelist(struct Node *root , struct LinNode **List,  int l , int r){
    if(root){
        if(root->data>r){
            Rangelist(root->lc , List , l , r);
        }else if(root->data<l){
            Rangelist(root->rc , List , l , r);
        }else{
            Rangelist(root->rc , List , l , r);

            struct LinNode *newnode = (struct LinNode *)malloc(sizeof(struct LinNode));
            newnode->node = root;
            newnode->next = *List;
            *List = newnode;

            Rangelist(root->lc , List , l , r);
        }
    }
}

int RangeCount(struct Node *root , int l , int r){
    if(root){
        if(root->data>r){
            return RangeCount(root->lc , l , r);
        }else if(root->data<l){
            return RangeCount(root->rc , l , r);
        }

        return (1 + RangeCount(root->lc , l , r) + RangeCount(root->rc , l , r));
    }
    return 0;
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
        root = insert(root , arr[i]);
    }

    int low , upp;
    printf("Enter upper bound and lower bound to find Rangelist and Rangecount : ");
    scanf("%d" , &low);
    scanf("%d" , &upp);

    struct LinNode *List = NULL;
    Rangelist(root , &List , low , upp);
    int count = RangeCount(root , low , upp);

    traverse_list(List);
    printf("%d\n" , count);

    return 0;
}
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

struct Node *LCA(struct Node *root , struct Node *l , struct Node *r){

    if(root->data<l->data){
        return LCA(root->rc , l , r);
    }
    else if(root->data>r->data){
        return LCA(root->lc , l , r);
    }

    return root;
}

int main(){
    int n;
    scanf("%d" , &n);

    int arr[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    struct Node *root = NULL;;
    for(int i = 0; i<n; i++){
        root = insert(root , arr[i]);
    }

    int num1 , num2;
    scanf("%d" , &num1);
    scanf("%d" , &num2);

    struct Node *l = search(root , num1);
    struct Node *r = search(root , num2);

    struct Node *LCA_node = LCA(root , l , r);
    printf("%d\n" , LCA_node->data);

    return 0;
}
    

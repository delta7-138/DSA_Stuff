//Program to implement a BST 
// addition deletion all takes o(h) where h is the height of the tree
// h could be O(logn) in case of a balanced binary tree
// For which AVL trees are used this is an example of a normal BST
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

void inorder_traversal(struct Node *node){
    if(node){
        inorder_traversal(node->lc);
        printf("%d " , node->data);
        inorder_traversal(node->rc);
    }//printf("\n");
}

int main(){
    int n;
    printf("Enter number of nodes : \n");
    scanf("%d" , &n);

    int arr_inp[LARGE];
    printf("Enter the nodes \n");
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr_inp[i]);
    }

    struct Node *root = NULL;
    for(int i = 0; i<n; i++){
        root = insert(root , arr_inp[i]);
    }

    printf("%d\n" , root->data);

    int op;
    int data;

    while(1){
        printf("Enter the option : \n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. search\n");
        printf("4. quit\n");

        scanf("%d" , &op);
        switch(op){
            case 1:
            scanf("%d" , &data);
            insert(root , data);
            break;

            case 2:
            scanf("%d" , &data);
            delete(root , data);
            break;

            case 3:
            scanf("%d" , &data);
            if(search(root , data)==NULL){
                printf("404\n");
            }else{
                printf("200 %d\n" , data);
            }
            break;
            
            case 4:
            printf("quiting...\n");
            break;

            default:
            continue;
        }
        inorder_traversal(root);
        printf("\n");
        if(op==4){
            break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
    int height;
};

struct Node *minNode(struct Node *node){
    struct Node *tmp = node;
    while(tmp!=NULL && tmp->lc!=NULL){
        tmp = tmp->lc;
    }

    return tmp;
}

struct Node *newnode(int data){
    struct Node *newn = (struct Node *)malloc(sizeof(struct Node));
    newn->data = data;
    newn->lc = NULL;
    newn->rc = NULL;
    newn->height = 1;

    return newn;
}

int max(int a , int b){
    return (a>b)?a:b;
}

int height(struct Node *node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}

int balanceOf(struct Node *node){
    if(node==NULL){
        return 0;
    }
    return (height(node->lc) - height(node->rc));
}

struct Node *right_rotate(struct Node *y){
    struct Node *x = y->lc;
    struct Node *T2 = x->rc;

    x->rc = y;
    y->lc = T2;

    x->height = 1 + max(height(x->lc) , height(x->rc));
    y->height = 1 + max(height(y->lc) , height(y->rc));

    return x;
}

struct Node *left_rotate(struct Node *x){
    struct Node *y = x->rc;
    struct Node *T2 = y->lc;

    y->lc = x;
    x->rc = T2;

    x->height = 1 + max(height(x->lc) , height(x->rc));
    y->height = 1 + max(height(y->lc) , height(y->rc));

    return y;
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
        root = newnode(data);
        return root;
    }

    if(root->data>data){
        root->lc = insert(root->lc , data);
    }
    else if(root->data<data){
        root->rc = insert(root->rc , data);
    }else
        return root;

    root->height = 1 + max(height(root->lc) , height(root->rc));//updating the height

    int balance = balanceOf(root);//Finding the balance 

    //Left Left Case
    /*
            x
           /        z is the subtree where it is added, x is where imbalance occurs for the first time
          y
         /
        z
    */         
    if(balance>1 && (root->lc)->data<data){
        return right_rotate(root);
    }
    
    //Left Right Case
    /*    
            x
           /
          y
          \
           z
    */
    if(balance>1 && (root->lc)->data>data){
        root->lc = left_rotate(root->lc);
        return right_rotate(root);
    }

    //Right Right Case
    /* 
            x
             \
             y
             \
             z
    */
    if(balance<-1 && (root->rc)->data<data){
        return left_rotate(root);
    }

    //Right Left Case
    /*
            x
             \
             y
            /
            z
    */
    if(balance<-1 && (root->rc)->data>data){
        root->rc = right_rotate(root->rc);
        return left_rotate(root);
    }

    return root;
}

void preorder_traversal(struct Node *node){
    if(node){
        printf("%d " , node->data); 
        preorder_traversal(node->lc);
        preorder_traversal(node->rc);
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
    
    //preorder_traversal(root);
    //printf("\n");
    //inorder_traversal(root);

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

            case 3:
            scanf("%d" , &data);
            if(search(root , data)==NULL){
                printf("404\n");
            }else{
                printf("200 %d\n" , data);
            }
            break;

            case 4:
            printf("quitting...\n");
            break;

            default:
            continue;
        }
        printf("Preorder traversal : ");
        preorder_traversal(root);
        printf("\nInorder traversal : ");
        inorder_traversal(root);
        printf("\n");
        if(op==4){
            break;
        }
    }
    return 0;
}



#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

//Defintion of node in a BST can be modified to contain parent pointer or other data
struct Node{
    int data;
    int height;
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

//Binary Search Tree Functions
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

struct Node *insert(struct Node *root , int data){
    if(root==NULL){
        root = createnode(data);
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
    if(balance>1 && (root->lc)->data<data){
        return right_rotate(root);
    }
    
    //Left Right Case
    if(balance>1 && (root->lc)->data>data){
        root->lc = left_rotate(root->lc);
        return right_rotate(root);
    }

    //Right Right Case
    if(balance<-1 && (root->rc)->data<data){
        return left_rotate(root);
    }

    //Right Left Case
    if(balance<-1 && (root->rc)->data>data){
        root->rc = right_rotate(root->rc);
        return left_rotate(root);
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

int Find_Max_Along_Path(struct Node *root , struct Node *A  , struct Node *B){
    int max_num = 0;
    
    struct Node *LCA_node = LCA(root , A , B);
    max_num = LCA_node->data;
    //printf("%d" , max_num);
    if(LCA_node==A){
        struct Node *tmp = LCA_node;

        if(LCA_node->data > B->data){
            tmp = tmp->lc;
            return LCA_node->data;
        }else{
            tmp = tmp->rc;
        }
        if(tmp==B){
            return B->data;
        }
        while(tmp && tmp!=B){

            if(tmp->data>B->data){
                tmp = tmp->lc;
            }else if(tmp->data<B->data){
                tmp = tmp->rc;
            }
            if(tmp->data>max_num){
                max_num = tmp->data;
            }            
        }
        return max_num;

    }else if(LCA_node==B){
        struct Node *tmp = LCA_node;

        if(LCA_node->data> A->data){
            return LCA_node->data;
        }else{
            tmp = tmp->rc;
        }
        if(tmp==A){
            return A->data;
        }
        while(tmp && tmp!=A){

            if(tmp->data>A->data){
                tmp = tmp->lc;
            }else if(tmp->data<A->data){
                tmp = tmp->rc;
            }
            if(tmp->data>max_num){
                max_num = tmp->data;
            }            
        }
        return max_num;
    }

    struct Node *tmp = LCA_node;
    struct Node *node_r;

    if(A->data > B->data){
        node_r = A;
    }else{
        node_r = B;
    }

    while(tmp && tmp!=node_r){  

        if(tmp->data>node_r->data){
            tmp = tmp->lc;
        }else if(tmp->data<node_r->data){
            tmp = tmp->rc;
        }

        if(tmp->data>max_num){
            max_num = tmp->data;
        }
    }
    return max_num;
}

int Find_Min_Along_Path(struct Node *root , struct Node *A , struct Node *B){
    struct Node *LCA_node = LCA(root , A , B);

    int min_num = LCA_node->data;

    if(LCA_node==A){

        struct Node *tmp = LCA_node;
        if(LCA_node->data < B->data){
            return LCA_node->data;
        }else{
            tmp = tmp->lc;    
        }
        if(tmp==B){
            return B->data;
        }
        while(tmp && tmp!=B){
            if(tmp->data > B->data){
                tmp = tmp->lc;
            }else if (tmp->data < B->data){
                tmp = tmp->rc;
            }

            if(tmp->data < min_num){
                min_num = tmp->data;
            }
        }
        return min_num;
    }


    if(LCA_node==A){

        struct Node *tmp = LCA_node;
        if(LCA_node->data < B->data){
            return LCA_node->data;
        }else{
            tmp = tmp->lc;    
        }
        if(tmp==A){
            return A->data;
        }
        while(tmp && tmp!=A){
            if(tmp->data > A->data){
                tmp = tmp->lc;
            }else if (tmp->data < A->data){
                tmp = tmp->rc;
            }

            if(tmp->data < min_num){
                min_num = tmp->data;
            }
        }
        return min_num;
    }

    struct Node *node_l;
    struct Node *tmp = LCA_node;

    if(A->data > B->data){
        node_l = B;
    }else{
        node_l = A;
    }

    while(tmp && tmp!=node_l){

        if(tmp->data > node_l->data){
            tmp = tmp->lc;
        }else if(tmp->data < node_l->data){
            tmp = tmp->rc;
        }

        if(tmp->data < min_num){
            min_num = tmp->data;
        }
    }
    return min_num;
}

void preorder_traversal(struct Node *root){
    if(root){
        printf("%d " , root->data);
        preorder_traversal(root->lc);
        preorder_traversal(root->rc);
    }
}

int main(){
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d" , &n);

    int arr[LARGE];

    printf("Enter the values : \n");
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    printf("inserting them one by one in a tree...\n");

    struct Node *root = NULL;
    for(int i = 0; i<n; i++){
        root = insert(root , arr[i]);
    }
    printf("Preorder traversal : \n");
    preorder_traversal(root);
    printf("\ndone\n");

    int num1 , num2;

    printf("Enter the two keys of the nodes : \n");
    scanf("%d" , &num1);
    scanf("%d" , &num2);

    if(num1>num2){
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    struct Node *A = search(root , num1);
    struct Node *B = search(root , num2);

    if(num1!=num2){
        printf("Maximum : %d\n" , Find_Max_Along_Path(root , A , B));
        printf("Minimum : %d\n" , Find_Min_Along_Path(root , A , B));
    }else{
        printf("Maximum : %d\n" , A->data);
        printf("Minimum : %d\n" , B->data);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

struct Node{
    int key , value , sum , max , min, height;
    struct Node *lc;
    struct Node *rc;
};

struct Node *newnode(int data , int value){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = data;
    node->value = value;

    return node;
}

void NodeUpdate(int arr[] , struct Node *node){
    if(node){
        node->min = node->key;
        node->max = node->key;
        node->sum = node->value;

        if(node->lc){
            if(arr[node->lc->min] < arr[node->min]){
                node->min = node->lc->min;
            }
            if(arr[node->lc->max] > arr[node->max]){
                node->max = node->lc->max;
            }
            node->sum = node->sum + node->lc->sum;
        }

        if(node->rc){
            if(arr[node->rc->min] < arr[node->min]){
                node->min = node->rc->min;
            }
            if(arr[node->rc->max] > arr[node->max]){
                node->max = node->rc->max;
            }
            node->sum = node->sum + node->rc->sum;
        }
    }
}

struct Node *Create_BBST(int arr[], int low , int upp){
    struct Node *root = NULL;
    if(low<=upp){
        int mid = (low + upp)/2;

        root = newnode(mid , arr[mid]);

        root->lc = Create_BBST(arr , low , mid-1);
        root->rc = Create_BBST(arr , mid + 1 , upp);

        NodeUpdate(arr , root);
    }    
    return root;
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

//Function to give inorder successor
struct Node *minNode(struct Node *node){
    struct Node *tmp = node;
    while(tmp!=NULL && tmp->lc!=NULL){
        tmp = tmp->lc;
    }

    return tmp;
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

struct Node *delete(struct Node *root , int ind , int arr[]){
    if(root==NULL){
        return NULL;
    }

    if(ind<root->key){
        root->lc = delete(root->lc , ind , arr);
    }else if(ind>root->key){
        root->rc = delete(root->rc , ind , arr);
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
        root->key = tmp->key;
        root->rc = delete(root->rc ,  tmp->key , arr);
    }
    
    if(root==NULL){
        return root;
    }

    root->height = 1 + max(height(root->lc) , height(root->rc));

    int balance = balanceOf(root);

      // Left Left Case 
    if (balance > 1 && balanceOf(root->lc) >= 0) 
        return right_rotate(root); 
  
    // Left Right Case 
    if (balance > 1 && balanceOf(root->lc) < 0) 
    { 
        root->lc =  left_rotate(root->lc); 
        return right_rotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && balanceOf(root->rc) <= 0) 
        return left_rotate(root); 
  
    // Right Left Case 
    if (balance < -1 && balanceOf(root->rc) > 0) 
    { 
        root->rc = right_rotate(root->rc); 
        return left_rotate(root); 
    }
    NodeUpdate(arr , root); 
    return root;
}

int RangeCount(struct Node *root , int l , int r){
    if(root){
        if(root->key>r){
            return RangeCount(root->lc , l , r);
        }else if(root->key<l){
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
    int ind_arr[LARGE];

    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
        ind_arr[i] = i;
    }

    struct Node *root = Create_BBST(arr , 0 , n-1);
    int cost_deletion = 0;
    int size = n;
    while(root){
        cost_deletion = cost_deletion + RangeCount(root , root->min , size) - 1;
        root = delete(root , root->min , arr);
    }
    printf("%d\n" , cost_deletion);
    return 0;
}
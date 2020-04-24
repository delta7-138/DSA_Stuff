#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

struct Node{
    int key , value , sum , max , min;
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

int main(){
    int n;
    scanf("%d" , &n);

    int arr[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%d" , &arr[i]);
    }

    struct Node *root = Create_BBST(arr , 0 , n-1);
    printf("%d %d %d\n" , arr[root->max] , arr[root->min] , root->sum);
    return 0;
}
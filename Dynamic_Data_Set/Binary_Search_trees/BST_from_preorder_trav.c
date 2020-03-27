//Program to contruct a BST from given preorder traversal 
//This is the recursive approach
//It uses min_int max_int approach to construct the tree in O(n) time
//Assumption is made that all elements are distinct

#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

struct Node *new_node(int data){
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = data;
    new->lc = NULL;
    new->rc = NULL;

    return new;
}

struct Node *Construct_BST(int pre_order[] , int *preindex , int key , int min , int max , int size){
    //Base Case for resursion
    if(*preindex>=size){
        return NULL;
    }

    struct Node *root = NULL;


    if(key>min && key<max){
        root = new_node(key);
        *preindex = *preindex + 1;

        if(*preindex<size){
            //To build left_subtree
            root->lc = Construct_BST(pre_order , preindex , pre_order[*preindex] , min , key , size);
            //To build right_subtree
            root->rc = Construct_BST(pre_order , preindex , pre_order[*preindex] , key , max , size);
        }
    }

    return root;
}
struct Node *construct_tree(int pre[] , int size){
    int preind = 0;
    return Construct_BST(pre , &preind , pre[0] , 0 , 10000 , size);
}

void inorder_traversal(struct Node *node){
    if(node){
        inorder_traversal(node->lc);
        printf("%d " , node->data);
        inorder_traversal(node->rc);
    }//printf("\n");
}

int main(){
    int n, size;
    scanf("%d" , &n);

    int pre_order[LARGE];
    size = n;
    for(int i = 0; i<n; i++){
        scanf("%d" , &pre_order[i]);
    }

    int pre_index = 0;
    struct Node *temp = Construct_BST(pre_order , &pre_index , pre_order[0] , 0 , 10000 , n);
    //struct Node *head = construct_tree(pre_order , n);//Here we sre taking min as 0 and max as 10000
    inorder_traversal(temp);

    return 0;    
}
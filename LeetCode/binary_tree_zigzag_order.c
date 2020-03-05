#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGE 1000

//Only for CBT plus uses recursive calling 
struct Node{
    char data[LARGE];
    struct Node *par;
    struct Node *lc;
    struct Node *rc;
    int level;
    int height;
};

int stoi(char str[]){
    int len = strlen(str);
    int num = 0;
    for(int i = 0; i<len; i++){
        num = num * 10 + (str[i] - '0');
    }
    return num;
}
//Stack Functions 
int pop(int stack[] , int *top){
    *top = *top - 1;
    return stack[*top + 1];
}

int push(int stack[] , int *top , int x){
    stack[++(*top)] = x;
}

void traverse_stack(int stack[] , int top){
    for(int i = 0; i<=top; i++){
        printf("%d\n" , stack[i]);
    }
}

//Tree Functions
void preorder_traversal(struct Node *node){
    if(node){
        printf("%d " , node->data); 
        preorder_traversal(node->lc);
        preorder_traversal(node->rc);
    }//printf("\n");
}

void postorder_traversal(struct Node *node){
    if(node){
        postorder_traversal(node->lc);
        postorder_traversal(node->rc);
        printf("%d " , node->data);
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
    struct Node *tree[LARGE]; 
    int n;
    scanf("%d" , &n);
    char str_inp[LARGE];

    for(int i = 0; i<n; i++){
        tree[i] = (struct Node *)malloc(sizeof(struct Node));
        scanf("%s" , str_inp);
        if(strcmp(str_inp , "null")!=0){
            strcpy(tree[i]->data , str_inp);
        }else{
            tree[i] = NULL;
        }
    }

    for(int i = 0; i<n; i++){
        if(i==0){
            tree[i]->level = 0;
        }
        if(i!=0 && tree[i]!=NULL){
            tree[i]->par = tree[(i-1)/2];
        }else if(tree[i]!=NULL){
            tree[i]->par = NULL;
        }
        tree[i]->level = (tree[i]->par)->level + 1;
        if(tree[i]!=NULL){
            tree[i]->lc = tree[2 * i + 1];
            tree[i]->rc = tree[2 * i + 2];
        }
    }

    int stack[LARGE];
    int top_stack = -1;

    for(int i = 0; i<n; i++){
        if(tree[i] && (tree[i]->level)%2!=0){
            if(tree[i]){
                push(stack , &top_stack , stoi(tree[i]->data));    
            }
        }
    }
    for(int i = 0; i<n; i++){
        
    }
    printf("\n");
    return 0;
}



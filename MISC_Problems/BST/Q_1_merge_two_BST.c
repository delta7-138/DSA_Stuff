#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
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
struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

struct Node *createnode(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->lc = NULL;
    newnode->rc = NULL;

    return newnode;
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

void push_in_stack(int stack[] , int *top , struct Node *root){
    if(root){
        push_in_stack(stack , top , root->lc);
        push(stack , top , root->data);
        push_in_stack(stack , top , root->rc);
    }
}

void merge_two_stacks(int stack_main[] , int stack_1[] ,  int stack_2[] , int n1 , int n2 , int *top_main){
    int p1 = 0 , p2 = 0;
    while(p1<n1 && p2<n2){
        if(stack_1[p1]<stack_2[p2]){
            push(stack_main , top_main , stack_1[p1]);
            p1++;
        }else{
            push(stack_main , top_main , stack_2[p2]);
            p2++;
        }
    }

    while(p1<n1){
        push(stack_main , top_main , stack_1[p1]);
        p1++;
    }

    while(p2<n2){
        push(stack_main , top_main , stack_2[p2]);
        p2++;
    }

}

struct Node *Create_BBST(int arr[], int low , int upp){
    struct Node *root = NULL;
    if(low<=upp){
        int mid = (low + upp)/2;

        root = createnode(arr[mid]);

        root->lc = Create_BBST(arr , low , mid-1);
        root->rc = Create_BBST(arr , mid + 1 , upp);
    }    
    return root;
}

void inorder_traversal(struct Node *root){
    if(root){
        inorder_traversal(root->lc);
        printf("%d " , root->data);
        inorder_traversal(root->rc);
    }
}

void preorder_traversal(struct Node *root){
    if(root){
        printf("%d " , root->data);
        preorder_traversal(root->lc);
        preorder_traversal(root->rc);
    }
}

int main(){
    int n1;
    int n2;
    printf("Enter the number of elements in first tree : ");
    scanf("%d" , &n1);
    printf("Enter the number of elements in second tree : ");
    scanf("%d" , &n2);

    int inp;
    struct Node *root_1 = NULL , *root_2 = NULL;
    
    printf("Enter the elements of tree 1: \n");
    for(int i = 0; i<n1; i++){
        scanf("%d" , &inp);
        root_1 = insert(root_1 , inp);
    }

    printf("Enter the elements in tree 2 : \n");
    for(int i = 0; i<n2; i++){
        scanf("%d" , &inp);
        root_2 = insert(root_2 , inp);
    }

    int top_1 = -1 , top_2 = -1 , top_main = -1;
    int stack_1[LARGE] , stack_2[LARGE] , main_stack[LARGE];

    push_in_stack(stack_1 , &top_1 , root_1);
    push_in_stack(stack_2 , &top_2 , root_2);

    merge_two_stacks(main_stack , stack_1 , stack_2 , n1 , n2 , &top_main);
    //traverse_stack(main_stack , top_main);

    struct Node *root_main = NULL;
    root_main = Create_BBST(main_stack , 0 , n1 + n2 - 1);

    printf("Inorder traversal : ");
    inorder_traversal(root_main);
    printf("\n");
    printf("Preorder traversal : ");
    preorder_traversal(root_main);
    printf("\n");
    return 0;
}
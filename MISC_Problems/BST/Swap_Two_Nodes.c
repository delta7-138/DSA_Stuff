#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGE 10000

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

int string_to_int(char *str){
    int ans = 0;
    int fleg = 0;
    int len = strlen(str);

    if(str[0]=='-'){
        fleg++;
    }

    for(int i = 0; i<len; i++){
        if(i==0 && fleg){
            continue;
        }
        ans = ans * 10 + str[i] - '0';
    }
    if(fleg){
        ans = -ans;
    }
    return ans;
}

void inorder_traversal(struct Node *root){
    if(root){
        inorder_traversal(root->lc);
        printf("%d " , root->data);
        inorder_traversal(root->rc);
    }
}

int main(){
    int n;
    scanf("%d" , &n);

    char inp[LARGE];

    struct Node *tree[LARGE];
    printf("Enter the level order traversal of the binary search tree : \n");

    for(int i = 0; i<n; i++){
        scanf("%s" , inp);
        if(strcmp(inp , "null")==0){
            tree[i] = NULL;
        }else{
            tree[i]->data = string_to_int(inp);
        }
    }

    for(int i = 0; i<n; i++){
        if(tree[i]){
            tree[i]->lc = tree[2 * i + 1];
            tree[i]->rc = tree[2 * i + 2];
        }
    }

    inorder_traversal(tree[0]);
    printf("\n");
    return 0;
}
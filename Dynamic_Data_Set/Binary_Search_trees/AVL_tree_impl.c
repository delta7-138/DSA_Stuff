#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
    int height;
};

struct Node *newnode(int data){
    struct Node *newn = (struct Node *)malloc(sizeof(struct Node));
    newn->data = data;
    newn->lc = NULL;
    newn->rc = NULL;
    newn->height = -1;

    return newn;
}




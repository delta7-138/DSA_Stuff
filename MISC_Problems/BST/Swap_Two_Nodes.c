#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
};

struct Node *node1 = NULL , *node2 = NULL;


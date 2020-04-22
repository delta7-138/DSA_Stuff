#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000

struct listnode{
    int i;
    struct listnode *next;
};

struct edgenode{
    int i , j;
    struct edgenode *next;
};

struct listnode *addatbeg(struct listnode **head , int i){
    struct listnode *newnode = (struct listnode *)malloc(sizeof(struct listnode));
    newnode->i = i;
    newnode->next = *head;
    *head = newnode;

    return newnode;
}

struct edgenode *addedge(struct edgenode **head , int i , int j){
    struct edgenode *newnode = (struct edgenode *)malloc(sizeof(struct edgenode));

    newnode->i = i;
    newnode->j = j;
    newnode->next = *head;
    *head = newnode;

    return newnode;
}

void traverse_ad_list(struct listnode *list[] , int size){
    for(int i = 0; i<size; i++){
        struct listnode *temp = list[i];

        printf("%d-->" , i);
        while(temp!=NULL){
            printf("%d-->" , temp->i);
            temp = temp->next;
        }printf("NULL\n");
    }
}

void traverse_edgelist(struct edgenode *root){
    struct edgenode *temp = root;
    while(temp!=NULL){
        printf("(%d , %d)-->" , temp->i , temp->j);
        temp = temp->next;
    }printf("NULL\n");
}

int main(){
    int n;
    scanf("%d" , &n);

    int adjacency_matrix[LARGE][LARGE];
    struct listnode *adjacency_list[LARGE];
    struct edgenode *edgelist = NULL;

    for(int i = 0; i<LARGE; i++){
        adjacency_list[i] = NULL;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n/10; j++){
            int k = rand()%n;

            if(adjacency_matrix[i][k]==0 && i!=k){
                adjacency_matrix[i][k] = 1;
                adjacency_list[i] = addatbeg(&adjacency_list[i] , k);
                edgelist = addedge(&edgelist , i , k);
            }
        }
    }
    traverse_ad_list(adjacency_list , n);
    traverse_edgelist(edgelist);
    return 0;
}
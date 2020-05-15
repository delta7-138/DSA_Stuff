#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000

//Stack functions 
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

int stack[LARGE];
int top_stack = -1, count = 0;

//ad-list struct
struct listnode{
    int i;
    float weight;
    struct listnode *next;
}

struct listnode *newedge(struct listnode **head , int i , float weight){
    struct listnode *temp = (struct listnode *)malloc(sizeof(struct listnode));
    temp->i = i;
    temp->weight = weight;

    temp->next = head;
    *head = *temp;

    return temp;
}

void DFSvisit(struct listnode *list[] , int D[] , int F[] , int V[] , int phi[] , int n){
    for(int i = 0; i<n; i++){
        D[i] = 0;
        F[i] = 0;
        V[i] = 0;
        phi[i] = -2;
    }
    count = 1;
    
}

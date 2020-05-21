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

//ad-list struct
struct listnode{
    int i;
    float weight;
    struct listnode *next;
};

struct listnode *newedge(struct listnode **head , int i , float weight){
    struct listnode *temp = (struct listnode *)malloc(sizeof(struct listnode));
    temp->i = i;
    temp->weight = weight;

    temp->next = *head;
    *head = temp;

    return temp;
}

void DFSvisit(struct listnode *list[] , int D[] , int F[] , int V[] , int phi[] , int n){
    for(int i = 0; i<n; i++){
        D[i] = 0;
        F[i] = 0;
        V[i] = 0;
        phi[i] = -2;
    }
    int stack[LARGE];
    int top_stack = -1;

    int count = 1;
    for(int i = 0; i<n; i++){
        //traverse_stack(stack , top_stack);
        if(V[i]==0){
            push(stack , &top_stack , i);
            phi[i] = -1;

            while(top_stack>=0){
                int u = pop(stack , &top_stack);
                if(V[u]==0){
                    V[u] = 1;
                    D[u] = count++;
                    push(stack , &top_stack , u);

                    struct listnode *temp = list[u];
                    while(temp!=NULL){
                        if(V[temp->i]==0){
                            push(stack , &top_stack , temp->i);
                            phi[temp->i] = u; 
                            temp = temp->next; 
                        }
                    }
                }
                else if(F[u]==0){
                    F[u] = count++;
                }
            }
        }
    }
}

int main(){
    int m, n;
    printf("Enter the number of edges : ");
    scanf("%d" , &m);
    printf("Enter the number of nodes : ");
    scanf("%d" , &n);

    int i , j;
    float w;
    int D[LARGE] , F[LARGE] , V[LARGE] , phi[LARGE];
    struct listnode *list[LARGE];
    printf("Enter the edges in the form (i , j): \n");
    
    for(int k = 0; k<m; k++){
        scanf("%d %d" , &i , &j);
        scanf("%f" , &w);
        newedge(&list[k] , j , w);
    }

    DFSvisit(list , D , F , V , phi , n);
    for(int i = 0; i<n; i++){
        printf("%d %d %d %d\n" , i , D[i] , F[i] , phi[i]);
    }
    return 0;
}
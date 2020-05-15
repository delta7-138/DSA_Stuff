#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000

struct listnode{
    int i;
    float weight;
    struct listnode *next;
};

struct listnode *addatbeg(struct listnode **head , int i , float weight){
    struct listnode *newnode = (struct listnode *)malloc(sizeof(struct listnode));
    newnode->i = i;
    newnode->next = *head;
    newnode->weight = weight;
    *head = newnode;

    return newnode;
}

void DFS(struct listnode *list[] , int phi[] , int n , int s){
    int V[LARGE];
    for(int i = 0; i<n; i++){
        phi[i] = -2;
        V[i] = 0;
    }
    struct listnode *head = (struct listnode *)malloc(sizeof(struct listnode));
    head->i = s;
    head->next = NULL;
    phi[s] = -1;
    struct listnode *h1 , *t1;

    while(head!=NULL){
        if(V[head->i]==0){
            V[head->i] = 1;
            t1 = list[head->i];

            if(t1){
                h1 = head;
                head = head->next;

                while(t1!=NULL){
                    if(V[t1->i]==0){
                        head = addatbeg(&head , t1->i , 0);

                        phi[t1->i] = h1->i;
                        t1 = t1->next;
                    }else{
                        t1 = t1->next;
                    }
                }
            }else{
                head = head->next;
            }
        }else{
            head = head->next;
        }
    }
}

int main(){
    printf("Enter the number of edges in the graph : \n");
    int m;
    scanf("%d" , &m);
    printf("Enter the number of nodes in the graph : \n");
    int n;
    scanf("%d" , &n);

    struct listnode *list[LARGE];
    printf("Enter the edges in the form (i, j): \n");

    int i , j;
    float w;
    for(int k = 0; k<m; k++){
        scanf("%d %d" , &i , &j);
        scanf("%f" , &w);

        addatbeg(&list[i] , j , w);
    }

    int phi[LARGE];
    DFS(list , phi , n , 0);
    for(int i = 0; i<n; i++){
        printf("%d %d\n" , i , phi[i]);
    }
    return 0;
}
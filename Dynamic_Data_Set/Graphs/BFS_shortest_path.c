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

void BFS(struct listnode *list[] , int phi[] , int n , int s){
    int v[LARGE] , L[LARGE];
    for(int i = 0; i<n; i++){
        phi[i] = -2;
        v[i] = 0;
        L[i] = LARGE;
    }
    struct listnode *head = (struct listnode *)malloc(sizeof(struct listnode));
    head->i = s;
    head->next = NULL;
    v[s] = 1;
    phi[s] = -1;
    L[s] = 0;
    struct listnode *tail = head;
    struct listnode *temp;

    while(head){
        temp = list[head->i];
        while(temp){
            if(v[temp->i]==0){
                tail->next = (struct listnode *)malloc(sizeof(struct listnode));
                tail = tail->next;
                tail->next = NULL;
                tail->i = temp->i;
                v[tail->i] = 1;
                phi[tail->i] = head->i;
                L[temp->i] = L[head->i] + 1;
            }
            temp = temp->next;
        }
        head = head->next;
    }

    for(int i = 0; i<n; i++){
        if(phi[i] >=0){
            printf("%d %d\n" , i , L[i]);
        }
    }
}

int main(){
    printf("Enter the number of edges : ");
    int m, n;
    scanf("%d" , &m);

    printf("Enter the number of nodes : ");
    scanf("%d" , &n);
    int i , j, s;
    float w;

    struct listnode *list[LARGE];
    for(int k = 0; k<m; k++){
        scanf("%d %d" , &i , &j);
        scanf("%f" , &w);

        addatbeg(&list[i] , j , w);
    }

    printf("Enter the value of source node : ");
    scanf("%d" , &s);
    int phi[LARGE];
    BFS(list , phi , n , s);
    return 0;   
}
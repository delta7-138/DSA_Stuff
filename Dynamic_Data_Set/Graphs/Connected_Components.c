#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000

int conn_dict[LARGE];

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

int BFS(struct listnode *list[]  , int n , int s){
    int v[LARGE];
    int count = 0;
    for(int i = 0; i<n; i++){
        v[i] = 0;
        conn_dict[i] = 0;
    }
    struct listnode *head = (struct listnode *)malloc(sizeof(struct listnode));
    head->i = s;
    head->next = NULL;
    v[s] = 1;

    struct listnode *tail = head;
    struct listnode *temp;

    for(int i = 0; i<n; i++){
        if(conn_dict[i]==0){
            s = i;
            conn_dict[s] = count++;
            struct listnode *head = (struct listnode *)malloc(sizeof(struct listnode));
            head->i = s;
            head->next = NULL;
            v[s] = 1;

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
                        conn_dict[temp->i] = count;
                    }
                    temp = temp->next;
                }
                head = head->next;
            }
        }
    }
    return count;
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

    int count = BFS(list , n , s);
    printf("%d" , count);
    return 0;
}

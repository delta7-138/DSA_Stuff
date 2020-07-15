#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000

long long ans = 0;
int num_nodes[LARGE];
long long val[LARGE];
struct listnode{
    int i;
    struct listnode *next;
};

struct listnode *addatbeg(struct listnode **head , int i){
    struct listnode *newnode = (struct listnode *)malloc(sizeof(struct listnode));
    newnode->i = i;
    newnode->next = *head;
    *head = newnode;

    return newnode;
}

void BFS(struct listnode *list[], int n , int s){
    int v[LARGE] , L[LARGE];
    for(int i = 0; i<n; i++){
        v[i] = 0;
        L[i] = 1;
    }
    struct listnode *head = (struct listnode *)malloc(sizeof(struct listnode));
    head->i = s;
    head->next = NULL;
    v[s] = 1;

    int flag = 0;
    L[s] = 1;
    struct listnode *tail = head;
    struct listnode *temp;

    while(head){
        temp = list[head->i];
        if(temp && temp->i==0 && v[temp->i]==0){
            if(num_nodes[temp->i]<2 && flag==0){
                    tail->next = (struct listnode *)malloc(sizeof(struct listnode));
                    tail = tail->next;
                    tail->next = NULL;
                    tail->i = n+1;
                    v[tail->i] = 1;
                    L[n+1] = L[head->i] + 1;
            }else{
                if(num_nodes[temp->i]<3 && flag==0){
                    tail->next = (struct listnode *)malloc(sizeof(struct listnode));
                    tail = tail->next;
                    tail->next = NULL;
                    tail->i = n+1;
                    v[tail->i] = 1;
                    L[n+1] = L[head->i] + 1;
                }
            }
        }
        ans = ans + val[temp->i] * L[temp->i];
        
        while(temp){
            if(v[temp->i]==0){
                tail->next = (struct listnode *)malloc(sizeof(struct listnode));
                tail = tail->next;
                tail->next = NULL;
                tail->i = temp->i;
                v[tail->i] = 1;
                L[temp->i] = L[head->i] + 1;
            }
            temp = temp->next;
        }
        head = head->next;
    }

    // for(int i = 0; i<n; i++){
    //     if(phi[i] >=0){
    //         printf("%d %d\n" , i , L[i]);
    //     }
    // }
}

int main(){
    int n;
    scanf("%d" , &n);
    long long x;
    scanf("%lld" , &x);

    struct listnode *list[LARGE];
    for(int i = 0; i<n; i++){
        scanf("%lld" , &val[i]);
    }
    val[n+1] = x;
    int i , j;
    for(int i = 0; i<n-1; i++){
        scanf("%d %d" , &i , &j);
        addatbeg(&list[i-1] , j-1);
        addatbeg(&list[j-1] , i-1);
    }
    BFS(list , n ,0);
    printf("%lld" , ans);
    return 0;
}
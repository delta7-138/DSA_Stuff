#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LARGE 100000
struct listnode{
    int i;
    int time;

    struct listnode *next;
};

struct listnode *newedge(struct listnode **head , int i , int time){
    struct listnode *node = (struct listnode *)malloc(sizeof(struct listnode));
    node->i = i;
    node->time  = time;

    node->next = *head;
    *head = node;
    return node;
}

void traverse_ad_list(struct listnode *list[] , int size){
    for(int i = 0; i<size; i++){
        struct listnode *temp = list[i];

        printf("%d : " , i);
        while(temp!=NULL){
            printf("(%d , %d)-->" , temp->i , temp->time);
            temp = temp->next;
        }printf("NULL\n");
    }
}

//Heap Functions
void BottomUpHeap(int H[] , int A[] , int B[] , int i){
  int p = (i-1)/2;
  while(p>=0 && H[p]>H[i]){
    int temp = H[p];
    H[p] = H[i];
    H[i] = temp;

    int t = A[p];
    A[p] = A[i];
    A[i] = t;

    B[A[i]] = i;
    B[A[p]] = p;

    p = (i-1)/2;
  }
}

void TopDownHeap(int H[] , int A[] , int B[] , int i , int n){
  int l = 0;
  while(2 * i + 2<n){

    if(H[2 * i + 2]>H[2 * i + 1]){
      l = 2 * i + 1;
    }else{
      l = 2 * i + 2;
    }

    if(H[l]<H[i]){
      int temp = H[l];
      H[l] = H[i];
      H[i] = temp;

      int t = A[i];
      A[i] = A[l];
      A[l] = t;

      B[A[i]] = i;
      B[A[l]] = l;

      i =l;
    }else{
      break;
    }
  }
}

void DecreaseKey(int H[] , int A[] , int B[] , int i , int x){
  H[i] = x;
  BottomUpHeap(H , A , B, i);
}

void DeleteMin(int H[] , int A[] , int B[] , int *n){
  *n = *n-1;
  int temp;
  int t;

  temp = H[*n];
  H[*n] = H[0];
  H[0] = temp;

  t = A[0];
  A[0] = A[*n];
  A[*n] = t;

  B[A[*n]] = *n;
  B[A[0]] = 0;

  TopDownHeap(H , A , B , 0 , *n);
}

void LevelOrderTraversal(int H[] , int A[] ,  int n){
  for(int i = 0; i<n; i++){
    printf("%d %d %d\n" , i , A[i] , H[i]);
  }
}

int Prim_Min(int H[] , struct listnode *list[] , int s , int n){
  int A[LARGE] ,B[LARGE] , V[LARGE] , phi[LARGE];
  int u = n , v = n , m = n;
  struct listnode *node;
  int min_st = 0;

  for(int i = 0; i<n; i++){
    A[i] = i;
    B[i] = i;
    phi[i] = -2;
    V[i] = 0;
    H[i] = INT_MAX;
  }

  phi[s] = -1;
  H[0] = 0;
  A[0] = s;
  A[s] = 0;
  B[s] = 0;
  B[0] = s;
  
  for(int i = 0; i<n; i++){
    u = A[0];
    V[u] = 1;
    node = list[u];
    
    DeleteMin(H , A , B , &m);

    while(node!=NULL){
      v = node->i;

      if(V[v]==0 && H[B[v]] > H[B[u]] + node->time){
        DecreaseKey(H , A , B , B[v] , H[B[u]] + node->time);
        phi[v] = u;
      }

      node = node->next;
    }
  }
   u = A[0];
   node = list[u];
    int ans  = H[0];
   if(node && H[B[node->i]]==INT_MAX && H[B[node->i]] > H[B[u]] + node->time){
       ans = ans + node->time;
   }
  LevelOrderTraversal(H , A , n);
  return ans;
}

int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize){
    
    struct listnode *list[100000];
    for(int i = 0; i<n; i++){
        if(manager[i]>=0){
            newedge(&list[manager[i]] , i , informTime[manager[i]]);
        }
    }
    traverse_ad_list(list , n);
    int H[100000];
    int ans = Prim_Min(H , list , headID , n);
    return ans;
}

int main(){
    int manager[LARGE];
    int informTime[LARGE];
    int n;
    int managerSize;
    int informTimeSize;
    int headID;
    scanf("%d %d %d %d" , &n , &managerSize , &informTimeSize , &headID);
    for(int i = 0; i<managerSize; i++){
        scanf("%d" , &manager[i]);
    }

    for(int i = 0; i<informTimeSize; i++){
        scanf("%d" , &informTime[i]);
    }
    int ans = numOfMinutes(n , headID , manager ,managerSize ,  informTime , informTimeSize);
    return 0;
}
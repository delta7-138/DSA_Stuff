#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LARGE 100000

struct listnode{
    int i;
    long long weight;
    struct listnode *next;
};

//Graph functions
struct listnode *newedge(struct listnode **head , int i , long long weight){
    struct listnode *node = (struct listnode *)malloc(sizeof(struct listnode));
    node->i = i;
    node->weight  = weight;

    node->next = *head;
    *head = node;
    return node;
}

void traverse_ad_list(struct listnode *list[] , int size){
    for(int i = 1; i<=size; i++){
        struct listnode *temp = list[i];

        printf("%d : " , i);
        while(temp!=NULL){
            printf("(%d , %lld)-->" , temp->i , temp->weight);
            temp = temp->next;
        }printf("NULL\n");
    }
}

//Heap functions
void LevelOrderTraversal(long long H[] , int A[] ,  int n){
  for(int i = 0; i<n; i++){
    printf("%d %d %lld\n" , i , A[i] , H[i]);
  }
}

void BottomUpHeap(long long H[] , int A[] , int B[] , int i){
  int p = (i-1)/2;
  while(p>=0 && H[p]>H[i]){
    long long temp = H[p];
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

void TopDownHeap(long long H[] , int A[] , int B[] , int i , int n){
  int l = 0;
  while(2 * i + 2<n){

    if(H[2 * i + 2]>H[2 * i + 1]){
      l = 2 * i + 1;
    }else{
      l = 2 * i + 2;
    }

    if(H[l]<H[i]){
      long long temp = H[l];
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

void DecreaseKey(long long H[] , int A[] , int B[] , int i , long long x){
  H[i] = x;
  BottomUpHeap(H , A , B, i);
}

void DeleteMin(long long H[] , int A[] , int B[] , int *n){
  *n = *n-1;
  long long temp;
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

int Dijkstra(long long H[] , struct listnode *list[] , int s , int n , int end){
  int A[LARGE] ,B[LARGE] , V[LARGE] , phi[LARGE];
  int u = n , v = n , m = n;
  struct listnode *node;

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
  
  for(int i = 0; i<n && H[0]<INT_MAX; i++){
    u = A[0];
    V[u] = 1;
    node = list[u];
    
    DeleteMin(H , A , B , &m);

    while(node!=NULL){
      v = node->i;

      if(V[v]==0 && H[B[v]] > H[B[u]] + node->weight){
        DecreaseKey(H , A , B , B[v] , H[B[u]] + node->weight);
        phi[v] = u;
      }

      node = node->next;
    }
  }
  //LevelOrderTraversal(H , A , n);
  return B[end];
}

int main(){
    int n,m;
    scanf("%d %d" , &n ,&m);
    struct listnode *list[LARGE];    
    int ki;
    long long ti;
    long long arr_ti[LARGE];

    for(int i = 0; i<m; i++){
        scanf("%d %lld" ,&ki , &ti);
        arr_ti[i] = i;

        int *ui_list = (int *)malloc(sizeof(int) * ki);
        long long *wi_list = (long long *)malloc(sizeof(long long) * ki-1);
        for(int var = 0; var<ki; var++){
            scanf("%d" , ui_list + var);
        }
        for(int var = 0; var<ki-1; var++){
            scanf("%lld" , wi_list + var);
        }

        for(int var = 0; var<ki-1; var++){
            newedge(&list[ui_list[var]-1] , ui_list[var + 1] - 1 , wi_list[var]);
        }
        //traverse_ad_list(list , n);
        free(ui_list);
        free(wi_list);
    }

    int start , end;
    scanf("%d %d" , &start , &end);

    long long H[LARGE];
    int coord = Dijkstra(H , list , start-1 , n , end-1);

    long long ans = H[coord];
    if(ans==INT_MAX){
        printf("-1");
    }else{
        printf("%lld", ans);
    }
    return 0;
}
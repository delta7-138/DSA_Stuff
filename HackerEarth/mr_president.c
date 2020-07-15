#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LARGE 100000

struct listnode{
    int i;
    int weight;
    struct listnode *next;
};

//Graph functions
struct listnode *newedge(struct listnode **head , int i , int weight){
    struct listnode *node = (struct listnode *)malloc(sizeof(struct listnode));
    node->i = i;
    node->weight  = weight;

    node->next = *head;
    *head = node;
    return node;
}

//Auxiliary Graph functions
void traverse_ad_list(struct listnode *list[] , int size){
    for(int i = 0; i<size; i++){
        struct listnode *temp = list[i];

        printf("%d : " , i);
        while(temp!=NULL){
            printf("(%d , %d)-->" , temp->i , temp->weight);
            temp = temp->next;
        }printf("NULL\n");
    }
}

//Heap functions
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

void max_topdownheapify(int H[] , int i , int n){
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
      i =l;

    }else{
      break;
    }
  }
}

void build_heap(int H[] , int n){
  for(int i = 0; i<n; i++){
    max_topdownheapify(H , i , n);
  }
}

int simp_deletemax(int H[] , int *n){
  *n = *n - 1;
  int t = H[*n];
  H[*n] = H[0];
  H[0] = t;

  max_topdownheapify(H , 0 , *n);
  return H[*n];
}

//Auxiliary functions
void LevelOrderTraversal(int H[] , int A[] , int phi[] ,  int n){
  for(int i = 0; i<n; i++){
    printf("%d %d %d %d\n" , i , A[i] , H[i] , phi[A[i]]);
  }
}

void simp_level_order(int H[] , int n){
  for(int i = 0; i<n; i++){
    printf("%d " , H[i]);
  }
  printf("\n");
}

//Prims algorithm for minimum spanning tree
int Prims_Min(int H[] , struct listnode *list[] , int s , int n , long long k){
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
  
  for(int i = 0; i<n && H[0]<INT_MAX; i++){
    u = A[0];
    V[u] = 1;
    node = list[u];
    
    DeleteMin(H , A , B , &m);

    while(node!=NULL){
      v = node->i;

      if(V[v]==0 && H[B[v]] >= H[B[u]] + node->weight){
        DecreaseKey(H , A , B , B[v] , H[B[u]] + node->weight);
        phi[v] = u;
      }

      node = node->next;
    }
    //LevelOrderTraversal(H , A , m);
    //printf("\n");

  }

  int ctr = 0;
  int H_road[LARGE];

  for(int i = n-1; i>=0; i--){
    if(phi[i]>=0){
      struct listnode *node = list[phi[i]];

      //printf("%d %d\n" , i , phi[i]);
      while(node!=NULL){
        if(node->i==i){
          min_st = min_st + node->weight;
          H_road[ctr] = node->weight;
          ctr++;
          break;
        }
        node = node->next;
      }
    }else if(H[0]==INT_MAX){
      return -1;
    }
  }
  build_heap(H_road , n);
  //simp_level_order(H_road , n);

  int trans_num = 0;
  int num_frou = n;
  
  while(num_frou>=0 && min_st>k){
    int temp = simp_deletemax(H_road , &num_frou);
    min_st = min_st - temp + 1;

    if(min_st<=k){
      break;
    }
    trans_num = trans_num + 1;
  }

  return trans_num;
}
 
int main(){
    int n , m;
    long long k;
    scanf("%d %d %lld" , &n , &m , &k);

    struct listnode *list[LARGE];
    int a , b;
    int c;

    for(int i = 0; i<m; i++){
        scanf("%d %d %d" , &a , &b , &c);
        newedge(&list[a-1] , b-1 , c);
        newedge(&list[b-1] , a-1 , c);
    }
    //traverse_ad_list(list , n);

    int H[LARGE];
    int ans = Prims_Min(H , list , 0 , n , k);

    printf("%d" , ans);
    return 0;
}
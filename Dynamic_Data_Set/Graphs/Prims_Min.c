/*
0 1
1
0 2
8
1 3
4
1 2
3.4
2
4
6.8
4 3
7.2
4 1
3.5
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LARGE 10000

//Graph functions
struct listnode{
    int i;
    float weight;

    struct listnode *next;
};

struct listnode *newedge(struct listnode **head , int i , float weight){
    struct listnode *node = (struct listnode *)malloc(sizeof(struct listnode));
    node->i = i;
    node->weight  = weight;

    node->next = *head;
    *head = node;
    return node;
}

void traverse_ad_list(struct listnode *list[] , int size){
    for(int i = 0; i<size; i++){
        struct listnode *temp = list[i];

        printf("%d : " , i);
        while(temp!=NULL){
            printf("(%d , %f)-->" , temp->i , temp->weight);
            temp = temp->next;
        }printf("NULL\n");
    }
}

//Heap functions
void LevelOrderTraversal(float H[] , int A[] ,  int n){
  for(int i = 0; i<n; i++){
    printf("%d %d %f\n" , i , A[i] , H[i]);
  }
}

void BottomUpHeap(float H[] , int A[] , int B[] , int i){
  int p = (i-1)/2;
  while(p>=0 && H[p]>H[i]){
    float temp = H[p];
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

void TopDownHeap(float H[] , int A[] , int B[] , int i , int n){
  int l = 0;
  while(2 * i + 2<n){

    if(H[2 * i + 2]>H[2 * i + 1]){
      l = 2 * i + 1;
    }else{
      l = 2 * i + 2;
    }

    if(H[l]<H[i]){
      float temp = H[l];
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

void DecreaseKey(float H[] , int A[] , int B[] , int i , float x){
  H[i] = x;
  BottomUpHeap(H , A , B, i);
}

void DeleteMin(float H[] , int A[] , int B[] , int *n){
  *n = *n-1;
  float temp;
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

float Prim_Min(float H[] , struct listnode *list[] , int s , int n){
  int A[LARGE] ,B[LARGE] , V[LARGE] , phi[LARGE];
  int u = n , v = n , m = n;
  struct listnode *node;
  float min_st = 0.0;

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
    //LevelOrderTraversal(H , A , m);
    //printf("\n");

  }
    for(int i = 0; i<n; i++){
        min_st = min_st + H[B[i]];
    }
  printf("The shortest distances from node %d are : \n" , s);
  for(int i = 0; i<n; i++){
    printf("%d %f %d\n" ,i , H[B[i]] , phi[i]);
  }

  return min_st;
}
  

int main(){
    int n, m, s;
    printf("Enter the number of nodes : \n");
    scanf("%d" , &n);
    printf("Enter the number of edges : \n");
    scanf("%d" , &m);
    
    struct listnode *list[LARGE];
    int i, j;
    float w;

    printf("Enter the edges in the form (i, j):\n");
    for(int k = 0; k<m; k++){
        scanf("%d %d" , &i , &j);
        scanf("%f" , &w);
        newedge(&list[i] , j , w);
    }

    printf("Enter the source value : \n");
    scanf("%d" , &s);

    traverse_ad_list(list , n);
    //int A[LARGE] , B[LARGE] , phi[LARGE];
    float H[LARGE];
    float ans = Prim_Min(H , list , s , n); 
    
    printf("%f\n" , ans);
    return 0;
}
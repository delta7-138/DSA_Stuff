#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000
//Heap functions 

void Level_Order_Traversal(int heap[] , int n){
    for(int i = 0; i<n; i++){
        printf("%d " , heap[i]);
    }printf("\n");
}

void Bottom_up_heapify(int heap[] , int i){
    int p = (i-1)/2;
    while(p>=0 && heap[i]<heap[p]){
        int tmp = heap[i];
        heap[i] = heap[p];
        heap[p] = tmp;

        i = p;
        p = (i-1)/2;
    }
}

void Build_Heap(int heap[] , int size){
    for(int i = 0; i<size; i++){
        Bottom_up_heapify(heap , i);
    }
}

void Top_Down_heapify(int heap[] , int size , int i){
    int l;
    while(2 * i + 2<size){
        if(heap[2 * i + 1]<=heap[2 * i + 2]){
            l = 2  * i + 1;
        }else{
            l = 2 * i + 2;
        }

        if(heap[i]>heap[l]){
            int tmp = heap[l];
            heap[l] = heap[i];
            heap[i] = tmp;

            i = l;
        }else{
            break;
        }
    }
}

int Delete_min_node(int heap[] , int *size){
    int min = heap[0];
    heap[0] = heap[*size - 1];
    *size = *size - 1;

    Top_Down_heapify(heap , *size , 0);
    //Level_Order_Traversal(heap , *size);
    return min;
}

int main(){
    int heap[LARGE] = {0};
    int n;
    int init_size = n;
    scanf("%d" , &n);
    for(int i = 0; i<n; i++){
        scanf("%d" , &heap[i]);
    }

    Build_Heap(heap , n);

    //Level_Order_Traversal(heap , n);
    
    while(n>0){
        printf("%d " , Delete_min_node(heap , &n));
        //Level_Order_Traversal(heap , n);
    }
    
    printf("\n");
    return 0;
}
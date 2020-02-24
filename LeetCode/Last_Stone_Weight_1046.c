#include <stdio.h>
#include <stdlib.h>
#define LARGE 100

void Bottom_up_heapify(int heap[] , int i){
    int p = (i-1)/2;
    while(p>=0 && heap[p]<heap[i]){
        int tmp = heap[i];
        heap[i] = heap[p];
        heap[p] = tmp;

        i = p;
        p = (i-1)/2;
    }
}

void Top_Down_heapify(int heap[], int i , int size){
    int l = 0;
    while((2 * i + 2)<size){
        if(heap[2 * i + 1]>heap[2 * i + 2]){
            l = 2 * i + 1;
        }else{
            l = 2 * i + 2;
        }

        if(heap[i]<heap[l]){
            int tmp = heap[l];
            heap[l] = heap[i];
            heap[i] = tmp;

            i = l;
        }else{
            break;
        }
    }
}

void Level_Order_Traversal(int heap[] , int n){
    for(int i = 0; i<n; i++){
        printf("%d " , heap[i]);
    }
    printf("\n");
}

int delete_max_node(int heap[] , int *size){
    int max_data = heap[0];
    heap[0] = heap[*size - 1];
    *size = *size - 1;

    Top_Down_heapify(heap , 0 , *size);
    return max_data;
}

int add_node(int heap[] , int *size , int data){
    heap[*size] = data;
    *size = *size + 1;

    Bottom_up_heapify(heap , *size - 1);
}

int main(){
    int heap_inp[LARGE];
    int n;
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &heap_inp[i]);
    }

    for(int i = 0; i<n; i++){
        Bottom_up_heapify(heap_inp , i);
    }

    //Level_Order_Traversal(heap_inp , n);
    int max_node_1 , max_node_2;

    while(n>1){
        max_node_1 = delete_max_node(heap_inp , &n);
        max_node_2 = delete_max_node(heap_inp , &n);

        int new_node = max_node_1 - max_node_2;
        //printf("%d\n" , n);
        add_node(heap_inp , &n , new_node);
    }

    printf("%d\n" , heap_inp[n-1]);
    return 0;
}
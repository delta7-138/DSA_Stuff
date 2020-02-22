#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
struct Node{
    int data;
    int lc_ind;
    int rc_ind; 
    int p_ind;
};

//Heap Functions

void Bottom_Up_Heapify(struct Node heap[] , int i){
    int p = heap[i].p_ind;
    while(p>=0 && heap[p].data>heap[i].data){
        int tmp = heap[i].data;
        heap[i].data = heap[p].data;
        heap[p].data = tmp;

        i = p;
        p = (i-1)/2;
    }
}

void Top_Down_Heapify(struct Node heap[] , int i , int n){
    int l = 0;
    while(2 * i + 2<n){
        if(heap[2 * i + 1].data>heap[2 * i + 2].data){
            l = 2 * i + 2;
        }else{
            l = 2 * i + 1;
        }

        if(heap[i].data>heap[l].data){
            int tmp = heap[i].data;
            heap[i].data = heap[l].data;
            heap[l].data = tmp;

            i = l;
        }else{
            break;
        }
    }
}

void Level_Order_Traversal(struct Node heap[] , int n){
    for(int i = 0; i<n; i++){
        printf("%d " , heap[i].data);
    }
    printf("\n");
}

int main(){
    struct Node heap[LARGE];
    int n;

    printf("Enter the number of nodes : ");
    scanf("%d" , &n);

    for(int i = 0; i<n; i++){
        scanf("%d" , &(heap[i].data));
        heap[i].lc_ind = 2 * i + 1;
        heap[i].rc_ind = 2 * i + 2;
        heap[i].p_ind = (i-1)/2;
    }
    //int ind;
    //scanf("%d" ,  &ind);

    //Bottom_Up_Heapify(heap , ind);
    //Level_Order_Traversal(heap , n);
    
    Level_Order_Traversal(heap , n);
    Top_Down_Heapify(heap , 0 , n);
    Level_Order_Traversal(heap , n);
    return 0;
}
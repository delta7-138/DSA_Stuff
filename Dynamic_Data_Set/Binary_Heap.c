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
    int p = (i-1)/2;
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

void Add_Node(struct Node heap[] , int data , int *size){
    heap[*size].data = data;
    *size = *size + 1;

    Bottom_Up_Heapify(heap , *size - 1); 
}

void update_node(struct Node heap[] , int ind , int data , int size){
    if(heap[ind].data>data){
        heap[ind].data = data;

        Bottom_Up_Heapify(heap , ind);

    }else if(heap[ind].data<data){
        heap[ind].data = data;

        Top_Down_Heapify(heap , ind , size);
    }
}

void Build_Heap(struct Node heap[] , int size){
    int inp;
    for(int i = 0; i<size;){
        scanf("%d" , &inp);
        Add_Node(heap , inp , &i);
    }
}

void Delete_Min_node(struct Node heap[] , int *size){
    heap[0] = heap[*size - 1];
    *size = *size - 1;

    Top_Down_Heapify(heap , 0 , *size);
}

int main(){
    struct Node heap[LARGE];
    int n;

    printf("Enter the number of nodes : ");
    scanf("%d" , &n);

    // for(int i = 0; i<n; i++){
    //     scanf("%d" , &(heap[i].data));
    //     heap[i].lc_ind = 2 * i + 1;
    //     heap[i].rc_ind = 2 * i + 2;
    //     heap[i].p_ind = (i-1)/2;
    //}

    // Level_Order_Traversal(heap , n);
    // printf("Enter index to update : \n");
    // int ind;
    // scanf("%d" , &ind); 
    // printf("Enter value : \n");
    // int data;
    // scanf("%d" , &data);

    // update_node(heap , ind , data, n);

    // Level_Order_Traversal(heap , n);
    
    Build_Heap(heap , n);
    Level_Order_Traversal(heap , n);

    Delete_Min_node(heap , &n);
    Level_Order_Traversal(heap , n);
    return 0;
}
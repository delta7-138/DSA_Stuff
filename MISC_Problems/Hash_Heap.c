#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000
#define PRIME 103

struct Hash_Node{
    int x;
    int i;
    int count;
    struct Node *next;
};

struct Heap_Node{
    int data;
    struct Hash_Node *p;
};

struct Hash_Node *hash_table[PRIME];
struct Heap_Node *heap[LARGE];

//Heap Functions
void Bottom_Up_Heapify(int i){
    int p = (i-1)/2;
    while(p>=0 && heap[p].data<heap[i].data){
        int tmp = heap[i].data;
        heap[i].data = heap[p].data;
        heap[p].data = tmp;

        i = p;
        p = (i-1)/2;
    }
}

void Top_Down_Heapify(int i , int n){
    int l = 0;
    while(2 * i + 2<n){
        if(heap[2 * i + 1].data<heap[2 * i + 2].data){
            l = 2 * i + 2;
        }else{
            l = 2 * i + 1;
        }

        if(heap[i].data<heap[l].data){
            int tmp = heap[i].data;
            heap[i].data = heap[l].data;
            heap[l].data = tmp;

            i = l;
        }else{
            break;
        }
    }
}


void Level_Order_Traversal(int n){
    for(int i = 0; i<n; i++){
        printf("%d " , heap[i].data);
    }
    printf("\n");
}

void Add_Node(int data , int *size){
    heap[*size].data = data;
    *size = *size + 1;

    Bottom_Up_Heapify(heap , *size - 1); 
}

void update_node(int ind , int data , int size){
    if(heap[ind].data>data){
        heap[ind].data = data;

        Bottom_Up_Heapify(heap , ind);

    }else if(heap[ind].data<data){
        heap[ind].data = data;

        Top_Down_Heapify(heap , ind , size);
    }
}

void Delete_Max_node(int *size){
    heap[0] = heap[*size - 1];
    *size = *size - 1;

    Top_Down_Heapify(heap , 0 , *size);
}

int main(){
    int q;
    printf("Enter number of queries : \n");
    scanf("%d" , &q);
    
    for(int i = 0; i<q; i++){
        
    }
}
#include <iostream>
#include <vector>
#define LARGE 100000
using namespace std;

struct Heap_Node{
    int count;
    int data;
};

struct Hash_Node{
    int count;
    int heap_ind;
};

struct Heap_Node heap[LARGE];
struct Hash_Node hash_table[LARGE];

void Top_Down_Heapify(int i , int n){
    int l = 0;
    while(2 * i + 2<n){
        if(heap[2 * i + 1].count>heap[2 * i + 2].count){
            l = 2 * i + 2;
        }else{
            l = 2 * i + 1;
        }

        if(heap[i].count>heap[l].count){
            struct Heap_Node tmp = heap[i];
            heap[i] = heap[l];
            heap[l] = tmp;

            i = l;
        }else{
            break;
        }
    }
}

int Bottom_Up_Heapify(int i){
    int p = (i-1)/2;
    while(p>=0 && heap[p].count<heap[i].count){
        struct Heap_Node tmp = heap[i];
        heap[i] = heap[p];
        heap[p] = tmp;

        i = p;
        p = (i-1)/2; 
    }
    return p;
}

int Add_Node(int data , int *size , int count){
    heap[*size].data = data;
    heap[*size].count = 1;
    *size = *size + 1;

    return Bottom_Up_Heapify(*size - 1); 
}

void Delete_Max_node(int *size){
    heap[0] = heap[*size - 1];
    *size = *size - 1;

    Top_Down_Heapify(0 , *size);
}

void Build_Heap(int size , int arr_inp[]){
    for(int i = 0; i<size;i++){
       Add_Node(i , &size , arr_inp[i]);
    }
}

void Level_Order_Traversal(int n){
    for(int i = 0; i<n; i++){
        printf("%d " , heap[i].data);
    }
    printf("\n");
}

int main(){
    int q;
    scanf("%d" , &q);
    int size = 0;
    for(int i = 0; i<LARGE; i++){
        hash_table[i].count = 0;
        hash_table[i].heap_ind = -1;
    }  

    int op , x;
    for(int i = 0; i<q; i++){
        scanf("%d" , &op);
        switch(op){
            case 0:
            scanf("%d" , &x);
            hash_table[x].count++;
            if(hash_table[x].count-1==0){
                int i = Add_Node(x , &size , 1);
                hash_table[x].heap_ind = i;
            }else{
                heap[hash_table[x].heap_ind].count+=1;
                Bottom_Up_Heapify(hash_table[x].heap_ind);
            }
            break;
            
            case 1:
            int data = heap[0].data;
            hash_table[data].count = 0;
            hash_table[data].heap_ind = -1;
            Delete_Max_node(&size);
            break;
        }
        //Printing level order traversal of heap after every query
        Level_Order_Traversal(size);
    }
    return 0;
}
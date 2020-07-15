#include <bits/stdc++.h>
#define LARGE 10000
#define PRIME 43
using namespace std;

//Linked List format
struct Node{
    int value; 
    struct Node *next;
    struct Node *prev;
};

void traverse_list(struct Node *list){
    struct Node *temp = list;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

//Hash Table Functions"
struct Node *insert(struct Node *table[] , long long key , int val){
    int hash_val = key%PRIME;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->value = val;
    struct Node *temp = table[hash_val];
    new_node->next = temp;
    new_node->prev = NULL;
    if(temp){
        temp->prev = new_node;
    }
    table[hash_val] = new_node;
    return new_node;
}

struct Node *search(struct Node *table[] , long long key , int val){
    int hash_val = key%PRIME;
    struct Node *temp = table[hash_val];

    while(temp!=NULL){
        if(temp->value==val){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct Node *delete_node(struct Node *table[] , long long key , int val){
    struct Node *del_node = search(table , key , val);
    if(del_node==NULL){
        return NULL;
    }
    struct Node *temp = del_node;
    int hash_val = key%PRIME;

    if(table[hash_val]==del_node){
        if(del_node->next==NULL){
            table[hash_val] = NULL;
            free(del_node);
        }else{
            table[hash_val] = del_node->next;
            (del_node->next)->prev = NULL;
            free(del_node);
        }
        return temp;
    }else if(del_node->next==NULL){
        (del_node->prev)->next = NULL;
        free(del_node);
        return temp;
    }else{
        struct Node *node_prev = del_node->prev;
        struct Node *node_next = del_node->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;

        free(del_node);
        return temp;      
    }
    return NULL;
}

void traverse_hash_table(struct Node *table[]){
    for(int i = 0; i<PRIME; i++){
        struct Node *temp = table[i];
        cout<<i<<" ";
        traverse_list(temp);
    }
} 

int main(){
    int num;
    cout<<"Enter the number of keys : ";
    cin>>num; 

    long long key;
    int val;

    cout<<"Enter the keys and values respectively : ";
    struct Node *hash_table[LARGE];
    for(int i = 0; i<num; i++){
        cin>>key>>val;
        insert(hash_table , key , val);
    }

    traverse_hash_table(hash_table);

    cout<<"Enter the key and value to be searched : ";
    long long key_s;
    int val_s;
    cin>>key_s>>val_s;
    struct Node *temp = search(hash_table , key_s , val_s);
    cout<<key_s<<" "<<temp->value<<endl;
    struct Node *node = delete_node(hash_table , key_s , val_s);

    cout<<"hash table after node deletion : "<<endl;
    traverse_hash_table(hash_table);
    return 0;
}
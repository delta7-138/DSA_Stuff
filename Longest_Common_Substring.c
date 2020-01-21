#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LARGE 100010
#define PRIME 43

struct Node{
  int data;
  struct Node *next;
};

struct Node *push(struct Node **head , int data){
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next= *head;
  *head = temp;
  return temp;
}

void traverse_list(struct Node *head){
  while(head!=NULL){
    printf("%d-->" , head->data);
    head = head->next;
  }printf("NULL\n");
}

int check_substring(char *str_1 , char *str_2 ,struct Node *hash_table[] ,  int len){
    //struct Node *hash_table[LARGE] = {NULL};
    int str_1_len = strlen(str_1);
    int str_2_len = strlen(str_2);
    int hash_value = str_1[0] - '0' , x = 2;
    for(int i = 0; i<len ; i++){
      if(hash_value<0){
        hash_value+=PRIME;
      }
      hash_value = (hash_value * 2 + str_1[0] - '0')%PRIME;
      x = (x * 2)%PRIME;
    }
    push(&hash_table[hash_value] , 0);

    for(int i = 1; i<=str_1_len -len; i++){
      hash_value = (hash_value * 2 + str_1[i + len -1]- '0' - (str_1[i-1] - '0') * x)%PRIME;
      push(&hash_table[hash_value] , i);
    }
    //for(int i = 0; i<PRIME; i++){
      //if(hash_table[i]!=NULL){
        //traverse_list(hash_table[i]);
      //}
    //}
    int sub_str_hash = str_2[0] - '0', z = 2;
    int j;
    for(j = 0; j<len; j++){
      sub_str_hash = (sub_str_hash * 2 + str_2[j]-'0')%PRIME;
      z = (z * 2)%PRIME;
    }
    struct Node *temp = hash_table[sub_str_hash];
    while(temp!=NULL){
      int m;
      for(m = 0; m<len; m++){
        int j = temp->data;
        for(; j<temp->data + len; j++){
          if(str_2[m]!=str_1[j])
            break;
        }
        if(j==temp->data + len)
           return 1;
        }
        temp = temp->next;
    }
    //rolling hash

    for(int k = 1; k<=str_2_len-len; k++){
      sub_str_hash = (sub_str_hash * 2 + str_2[k + len -1] - '0' + (str_2[k-1] - '0') * z)%PRIME;

      struct Node *temp = hash_table[sub_str_hash];
      while(temp!=NULL){
        for(int l = 0; l<len; l++){
          int p = temp->data;
          for(p; p<temp->data + len; p++){
            if(str_2[l]!=str_1[p])
              break;
          }
          if(p==temp->data + len)
            return 1;
        }
        temp = temp->next;
      }
    }
    return 0;
}
int main(){
  char str_1[LARGE];
  char str_2[LARGE];

  scanf("%s" , str_1);
  scanf("%s" , str_2);
  int str_1_len = strlen(str_1);
  //printf("%s %s\n" , str_1 , str_2);
  //struct Node **hash_table = (struct Node **)calloc(LARGE , sizeof(struct Node *))

  //HASH TABLE PART
  struct Node *hash_table[43];
  int i = check_substring(str_1 , str_2 , hash_table , 3);
  //for(int i = 0; i<PRIME; i++){
    //if(hash_table[i]!=NULL){
      //traverse_list(hash_table[i]);
    //}
  //}
  printf("%d\n" , i);
  return 0;

}

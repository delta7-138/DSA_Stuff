#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGE 100000
#define PRIME 103

struct Node{
  int data;
  int count;
  struct Node *next;
};

struct Node *hash_table[PRIME];
char str_1[LARGE] = "" , str_2[LARGE] = "";

void traverse_list(struct Node *head){
  while(head!=NULL){
    printf("%d-->" , head->data);
    head = head->next;
  }
  printf("NULL\n");
}

struct Node *addatbeg(struct Node **head , int data){
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = *head;
  temp->count = 1;
  *head = temp;
  return temp;
}

struct Node *check_string_match(char *str_main , int i , int hash_value , int len){

  char str_1[LARGE];

  for(int j = i; j<=i + len; j++){
    str_1[j-i] = str_main[j];
  }

  struct Node *temp = hash_table[hash_value];
  struct Node *prev = NULL;

  while(temp!=NULL){
    
    char str_2[LARGE];

    for(int j = temp->data ;j<=temp->data + len; j++){
      str_2[j-temp->data] = str_2[j];
    }

    if(strcmp(str_1 , str_2)==0){
      temp->count = temp->count + 1;
      return temp;
    }
    temp = temp->next;

    if(temp->next==NULL){
      prev = temp; 
    }
  }
  return addatbeg(&hash_table[hash_value] , i);
}

int check_k(char *str_main , int len , int k){
  int str_main_len = strlen(str_main);
  int hash_value = str_main[0] - '0' , x = 2;

  for(int i = 0; i<PRIME; i++){
    hash_table[i] = NULL;
  }

    for(int i = 1; i<len ; i++){
      hash_value = (hash_value * 2 + str_main[i] - '0')%PRIME;
      if(hash_value<0){
        hash_value+=PRIME;
      }
      x = (x * 2)%PRIME;
    }
    //printf("%d\n" , hash_value);

    addatbeg(&hash_table[hash_value] , 0);
    //printf("hi");

    //for(int i = 0;i<PRIME; i++){
      // if(hash_table[i]!=NULL){
    //     printf("%d " , hash_table[i]->data);
    //   }
    // }
    for(int i = 1; i<=str_main_len -len; i++){
      hash_value = (hash_value * 2 + str_main[i + len -1]- '0' - (str_main[i-1] - '0') * x)%PRIME;
      if(hash_value<0){
        hash_value = hash_value + PRIME;
      }
      //printf("%d " , hash_value);

      for(int j = i; j<i + len; j++){
         str_1[j-i] = str_main[j];
      }

      struct Node *temp = hash_table[hash_value];
      struct Node *prev = NULL;
      while(temp!=NULL){
        int ctr = temp->data;

        for(int j = ctr;j<ctr + len; j++){
           str_2[j-i] = str_main[j];
        }

        if(strcmp(str_1 , str_2)==0 && temp){
          //printf("h");
          temp->count = temp->count + 1;
          break;
        }

        if(temp->next==NULL){
          prev = temp;
        }
        temp = temp->next;
      }
      strcpy(str_1 , "");
      strcpy(str_2 , "");

      if(prev==NULL){
        addatbeg(&hash_table[hash_value] , i);
      }
      //check_string_match(str_main , i , hash_value , len);
      if(temp){
        printf("%d " , temp->count);
      }
      if(temp && temp->count>=k){
        printf("%d " , temp->count);
        return 1;
       }
    }
    return 0;
}

int Binary_Search(char *str , int k , int i , int j){
  if(i<=j){

    int mid = (i + j)/2;
    if(check_k(str , mid , k)==1){
      return Binary_Search(str , k , mid , j); 
    }else{
      return Binary_Search(str , k , i , mid-1);
    }

  }
  return i;
}

int main(){
  char str_inp[LARGE];
  scanf("%s" , str_inp);

  int len = strlen(str_inp);
  int k;
  scanf("%d" , &k);

  int check = check_k(str_inp , 3 , 3);
  //printf("%d\n" , check);
  printf("%d\n" , Binary_Search(str_inp , k , 0 , len-1));
  return 0;
}
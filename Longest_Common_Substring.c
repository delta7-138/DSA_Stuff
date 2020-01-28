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

    for(int i = 1; i<len ; i++){
      hash_value = (hash_value * 2 + str_1[i] - '0')%PRIME;
      if(hash_value<0){
        hash_value+=PRIME;
      }
      x = (x * 2)%PRIME;
    }
    push(&hash_table[hash_value] , 0);

    for(int i = 1; i<=str_1_len -len; i++){
      hash_value = (hash_value * 2 + str_1[i + len -1]- '0' - (str_1[i-1] - '0') * x)%PRIME;
      if(hash_value<0){
        hash_value = hash_value + PRIME;
      }
      push(&hash_table[hash_value] , i);
    }

    // for(int i = 0; i<PRIME; i++){
    //   if(hash_table[i]!=NULL){
    //     traverse_list(hash_table[i]);
    //   }
    // }

     int sub_str_hash = str_2[0] - '0', z = 2;
     int j;
     for(j = 1; j<len; j++){
       if(sub_str_hash<0){
        sub_str_hash = sub_str_hash + PRIME;
       }
       sub_str_hash = (sub_str_hash * 2 + str_2[j]-'0')%PRIME;
       z = (z * 2)%PRIME;
     }
     //printf("%d\n" , sub_str_hash);
     struct Node *temp = hash_table[sub_str_hash];
     while(temp!=NULL){
      int u = temp->data;
      int m;
      //printf("%d\n" , u);

      for(m = 0;u<(temp->data + len); u++ , m++){
          //printf("%c %c\n" , str_1[u] , str_2[m]);
           if(str_2[m]!=str_1[u])
             break;
         }
         //printf("%d\n" , m);
         if(m==len)
            return 1;
       temp = temp->next;
     }
   //rolling hash
     //printf("bla");
     for(int k = 1; k<=str_2_len-len; k++){
       sub_str_hash = (sub_str_hash * 2 + str_2[k + len -1] - '0' - (str_2[k-1] - '0') * z)%PRIME;
       if(sub_str_hash<0){
        sub_str_hash = sub_str_hash + PRIME;
       }

       struct Node *temp = hash_table[sub_str_hash];
       while(temp!=NULL){
         int l = 0;
         for(int p = temp->data; l<len; p++ , l++){
           if(str_1[p]!=str_2[l + k])
            break;
         }
         if(l==len){
          // for(int i = temp->data; i<temp->data + len; i++){
          //    printf("%c" , str_1[i]);
          //  }
          //  printf("\n");
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
  //int i = check_substring(str_1 , str_2 , hash_table , 3);
  //for(int i = 0; i<PRIME; i++){
    //if(hash_table[i]!=NULL){
      //traverse_list(hash_table[i]);
    //}
  //}
  //printf("%d\n" , i);
  int min_len = 0, max_len, mid;
  if(strlen(str_1) > strlen(str_2)){
	  max_len = strlen(str_2);
  }else{
	  max_len = strlen(str_1);
  }

  while(min_len<=max_len){
     struct Node *hash_table[43] = {NULL};
     mid = (min_len + max_len)/2;

     if(check_substring(str_1 , str_2 , hash_table , mid)==0){
       max_len = mid  - 1;
     }else{
       min_len = mid + 1;
     }
   }
  //int i = 1;
  // while(1){
  //   struct Node *hash_table[43] = {NULL};
  //   if(check_substring(str_1 , str_2 , hash_table , i)==0)
  //     break;
  //   i++;
  // }
  //printf("%d\n" , i+1);
  //struct Node *hash_table[43] = {NULL};
  //printf("%d\n" , check_substring(str_1 , str_2 , hash_table , 4));
  printf("%d\n" , min_len-1);
  return 0;

}

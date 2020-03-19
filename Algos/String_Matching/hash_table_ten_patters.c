#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *next;
};

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
  *head = temp;
  return temp;
}

int check_equal(char str[] , char pat[] , int i){
  int m = strlen(pat);
  int n = strlen(str);
  int j;
  for(j = 0; i<m; j++){
    if(str[j + i]!=pat[j])
      break;
  }
  if(j==m)
    return 1;
  return 0;
}

int main(){
  char pat_arr[10][10000];
  int arr[10];
  for(int i = 0; i<10; i++){
    arr[i]=0;
  }
  char str[100000];
  scanf("%s" , str);
  int n = strlen(str);
  for(int i = 0; i<10; i++)
    scanf("%s" , pat_arr[i]);

  //calculating hash values for all patterns
  struct Node *hash_table[43];
  for(int i = 0; i<43; i++)
    hash_table[i] = NULL;

  for(int j = 0; j<10; j++){
    int hash_value = pat_arr[j][0] - '0';
    int m = strlen(pat_arr[j]);
    for(int i = 1; i<m; i++){
        //x = (x * 2)%(43);
        if(hash_value<0)
          hash_value+=43;
        hash_value = (hash_value *2  + pat_arr[j][i]-'0')%43;
        //sub_str_num = (sub_str_num * 2 + str[i]-'0')%43;
    }
    addatbeg(&hash_table[hash_value] , j);
  }
  //for(int j = 0; j<43; j++)
  //  if(hash_table[j]!=NULL){
    //  traverse_list(hash_table[j]);
  //    printf("%d\n" , j);
//    }

  //rolling hash
  int m = 6;
  int sub_str_hash = str[0] - '0' , z = 2;
  for(int i = 1; i<m; i++){
    z = (z * 2)%43;
    if(sub_str_hash<0)
      sub_str_hash+=43;
    sub_str_hash = (sub_str_hash * 2 + str[i] - '0')%43;
  }
  struct Node *temp = hash_table[sub_str_hash];
  while(temp!=NULL){
    if(check_equal(str , pat_arr[temp->data] , 0))
      arr[temp->data]++;
    temp = temp->next;
  }
  for(int i = 1; i<=n-m; i++){
    //printf("hello");
    sub_str_hash = (sub_str_hash * 2 + str[i + m -1]- '0' - (str[i-1] - '0') * z)%43;
    if(sub_str_hash<0)
      sub_str_hash+=43;
    //printf("%d\n" , sub_str_hash);
    struct Node *temp = hash_table[sub_str_hash];
    //if(temp!=NULL){
    //  printf("%s\n" , pat_arr[temp->data]);
    //}
    while(temp!=NULL){
      int j;
      for(j = 0; j<m; j++){
        if(str[i+j]!=pat_arr[temp->data][j])
          break;
      }
      if(j==m)
        arr[temp->data]++;
      temp = temp->next;
    }
  }

  //printing number of times pattern appeared
  for(int i = 0; i<10; i++){
    printf("%s %d\n" , pat_arr[i] , arr[i]);
  }
}

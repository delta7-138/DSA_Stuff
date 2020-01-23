#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LARGE 100000
char *reverse_str(char *str){
  int len = strlen(str);
  char temp;
  char ans[LARGE];
  strcpy(ans , str);
  for(int i = 0; i<len; i++){
    str[len -i - 1] = ans[i];
  }
  str[len] = '\0';
  return str;
}
int main(){
  char num1[LARGE];
  char num2[LARGE];

  scanf("%s %s" , num1 , num2);
  //printf("%s\n", reverse_str(num1));
  int len_num_1 = strlen(num1);
  int len_num_2 = strlen(num2);

  strcpy(num1 , reverse_str(num1));
  strcpy(num2 , reverse_str(num2));
  //int diff = abs(len_num_2 - len_num_1);
  int len;
  if(len_num_1>len_num_2){
    for(int i = len_num_2 ; i<len_num_1; i++){
      num2[i] = '0';
     }
     len = len_num_1;
     num2[len_num_1] = '\0';
  }
  else{
    for(int i = len_num_1; i<len_num_2; i++){
      num1[i] = '0';
    }
    len = len_num_2;
    num1[len_num_2]= '\0';
  }
  char sum[LARGE];
  int i = 0 ,carry = 0, ans_int = 0;

  for(i = 0; i<len; i++){
    carry = carry + num1[i] - '0' + num2[i] - '0';
    sum[i] = (char)(carry%10 + '0');
    carry = carry/10;
  }
  if(carry!=0)
    sum[i] = (char)(carry%10 + '0');
    
  printf("%s\n" , reverse_str(sum));
  return 0;
}

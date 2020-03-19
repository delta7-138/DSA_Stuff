#include <stdio.h>
#include <string.h>
#define LARGE 1000
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

void add_two_nums(char num1[] ,char num2[] , char sum[]){
  int len_num_1 = strlen(num1);
  int len_num_2 = strlen(num2);
  int len;

  strcpy(num1 , reverse_str(num1));
  strcpy(num2 , reverse_str(num2));
  //printf("%s %s\n" , num1 , num2);
  //int diff = abs(len_num_2 - len_num_1);
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
  int i = 0 ,carry = 0, ans_int = 0;
  for(i = 0; i<len; i++){
    carry = carry + num1[i] - '0' + num2[i] - '0';
    sum[i] = (char)(carry%10 + '0');
    carry = carry/10;
  }
  if(carry!=0)
    sum[i] = (char)(carry%10 + '0');
  strcpy(sum , reverse_str(sum));
  strcpy(num2 , reverse_str(num2));
  //printf("%s\n" , sum);
}
void multiply(char num1[] , int num2 , char product[]){
  char temp[1000000] = "0";
  for(int i = 0; i<num2; i++){
    add_two_nums(temp , num1 , temp);
  }
  strcpy(product , temp);
  //printf("%s\n" , product);
}
int main(){
  char factorial[100000] = "1";
  int num;
  scanf("%d" , &num);
  for(int i =1; i<=num; i++){
    multiply(factorial , i , factorial);
  }
  printf("%s\n" , factorial);
}

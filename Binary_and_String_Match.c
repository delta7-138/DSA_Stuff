#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char *str = (char *)malloc(sizeof(char) * 10000000);
  scanf("%s" , str);
  char *t = (char *)malloc(sizeof(char) * 100000);
  scanf("%s" , t);
  int n = strlen(str);
  int m = strlen(t);
  int x = 2 , pat_num = (t[0]-'0') , sub_str_num = (str[0] - '0');
  for(int i = 1; i<m; i++){
      x = x * 2;
      pat_num = pat_num * 2 + t[i]-'0';
      sub_str_num = sub_str_num * 2 + str[i]-'0';
  }
  if(pat_num==sub_str_num){
    printf("There is a match\n");
  }
  for(int i = 1; i<=n-m; i++){
    sub_str_num = sub_str_num * 2 + str[i + m - 1]-'0' - ((str[i-1]-'0') * x);//10011001 1001
    //printf("%d\n" , sub_str_num);
    if(pat_num==sub_str_num)
      printf("There is a match\n");
  }
  return 0;
}

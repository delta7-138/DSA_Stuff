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
  int i  , j;
  for(i = 0; i<=n-m; i++){
    for(j = 0; j<m; j++){
      if(str[i+j]!=t[j])
        break;
      }
      if(j==m)
        printf("There is a match\n");
  }
  return 0;
}

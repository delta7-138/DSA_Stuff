#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000
int main(){
  int arr_inp[LARGE];
  int n;
  scanf("%d" , &n);

  for(int i = 0; i<n; i++){
    scanf("%d" , &arr_inp[i]);
  }

  for(int i = 1; i<n ; i++){
    int t = arr_inp[i];
    int j = i-1;
    while(j>=0 && arr_inp[j]>t){
      arr_inp[j+1] = arr_inp[j];
      j--;
    }
    arr_inp[j+1] = t;
  }

  for(int i = 0; i<n; i++){
    printf("%d " , arr_inp[i]);
  }
  printf("\n");
  return 0;
}

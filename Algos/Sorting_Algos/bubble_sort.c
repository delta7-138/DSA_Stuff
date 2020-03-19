#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000000
void bubble_sort(int arr_inp[] , int n){
  for(int i = 0; i<n-1; i++){
    for(int j = 0; j<n-i-1;j++){
      if(arr_inp[j]>arr_inp[j+1]){
        int temp = arr_inp[j];
        arr_inp[j] = arr_inp[j+1];
        arr_inp[j+1] = temp;
      }
    }
  }
}
int main(){
  int arr_inp[LARGE];
  int num_inp;
  scanf("%d" , &num_inp);

  for(int i = 0; i<num_inp; i++){
    scanf("%d" , &arr_inp[i]);
  }
  printf("\n");
  bubble_sort(arr_inp , num_inp);

  for(int i = 0; i<num_inp; i++){
    printf("%d\n" , arr_inp[i]);
  }
  return 0;
}

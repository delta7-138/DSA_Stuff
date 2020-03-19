#include <stdio.h>
#include <stdlib.h>
#define LARGE 1000000
void selection_sort(int arr[] , int n){
  int max_index = 0;
  for(int i = 0; i<n-1; i++){
    for(int j = i; j<n)
  }
}
int main(){
  int arr_inp[LARGE];
  int num_inp;
  scanf("%d" , &n);

  for(int i = 0; i<num_inp; i++){
    scanf("%d" , &arr_inp[i]);
  }printf("\n");

  selection_sort(arr_inp , num_inp);

  for(int i = 0; i<num_inp; i++){
    printf("%d\n" , arr_inp[i]);
  }
  return 0;
}

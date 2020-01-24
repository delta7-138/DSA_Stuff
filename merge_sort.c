#include <stdio.h>
#include <stdlib.h>
#define LARGE 100000
int main(){
    int num_inp;
    scanf("%d" , &num_inp);

    int arr_inp[LARGE];
    int arr_ans[LARGE];

    for(int i = 0; i<num_inp; i++){
        scanf("%d" , &arr_inp[i]);
    }

    return 0;
}
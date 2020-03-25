//Program to find leftmost and rightmost nodes of a binary search tree from its preorder traversal
//Assumption all numbers are less than 10000 and greater than 0
/*
if array = {10 , 2 , 4 , 40 , 5}
tree is 
            10
           /  \
          2    40
           \   /
            4  5

    Therefore the left most node is the minimum number and the rightmost node is the maximum number
*/
#include <stdio.h>
#include <stdlib.h>
#define LARGE 10000
int main(){
    int n;
    scanf("%d" , &n);

    int pre_order_trav[LARGE];
    int min = 10000 , max = 0;
    for(int i = 0; i<n; i++){
        scanf("%d" , &pre_order_trav[i]);
        if(max<pre_order_trav[i]){
            max = pre_order_trav[i];
        }
        if(min>pre_order_trav[i]){
            min = pre_order_trav[i];
        }
    }
    
    printf("LEFT MOST NODE : %d\n" , min);
    printf("RIGHTMOST NODE : %d\n" , max);

    return 0;
}

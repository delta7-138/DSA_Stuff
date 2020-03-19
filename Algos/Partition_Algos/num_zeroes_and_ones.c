#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LARGE 10000
int compute_pos(char str[]){
    if(strlen(str)==1)
        return -1;
    
    if(strlen(str)==2){
        return 0;
    }
    else{
        int start = 0;
        int end = strlen(str) - 1;

        int ind_lst_zero = start;
        int ind_lst_one = end;

        int count_one = 0 , count_zero = 0;
        while(start<end){
            if(str[start]=='0'){
                count_zero++;
                ind_lst_zero = start;
            }
            if(str[end]=='1'){
                count_one++;
                ind_lst_one = end;
            }
            if(count_one==count_zero && (ind_lst_one==ind_lst_zero)){
                return ind_lst_zero;
            }
            start++;
            end--;
        }
        if(str[start]=='0')
            
    }
}
int main(){
    char input_str[LARGE];
    scanf("%s" , input_str);
    int ans = compute_pos(input_str);
    if(ans<0){
        printf("NO");
    }else{
        printf("%d\n" , ans);
    }
    return 0;
}
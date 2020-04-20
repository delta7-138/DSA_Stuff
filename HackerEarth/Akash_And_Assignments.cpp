#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define LARGE 1000000

using namespace std;

int power(int x , int a){
    long long y = 1;
    while(a>0){
        if(a%2==1){
            y = y * x;
        }
        x = x * x;
        a = a/2;
    }
    return y;
}

void build_tree(int segment_tree[] , int arr[] , int n){
    for(int i = 0; i<n; i++){
        segment_tree[n + i - 1] = i;
    }

    for(int i = n-2; i>=0; i--){
        //printf("%d %d \n" , arr[segment_tree[2 * i + 1]] , arr[segment_tree[2 * i + 2]]);
        if(arr[segment_tree[2 * i + 1]]>arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
    }
}

void update_node(int segment_tree[] , int arr[] , int i ,  int x , int n){
    arr[i] = x;

    i = (n-1 + i - 1)/2;

    while(i>=0){
        if(arr[segment_tree[2 * i + 1]]>arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
        //printf("%d\n" , i);

        i = (i-1)/2;
        if(i<1){
            break;
        }
    }
}

int main(){
    int n , q;
    cin>>n>>q;

    string str;
    cin>>str;

    int op;
    int ind , lb , ub , k;

    int arr[LARGE];
    int seg_arr[LARGE];

    for(int i = 0; i<n; i++){
        arr[i] = (int)str[i];
    }

    for(int i = n; i<LARGE; i++){
        arr[i] = 1000;
    }

    if(log2(n) - n!=0){
        n = power(2 , (int)(ceil(log2(n))));
    }

    build_tree(seg_arr , arr , n);
    char c;
    for(int i = 0; i<q; i++){
        cin>>op;
        switch(op){
            case 0:
            cin>>ind;
            cin>>c;
            update_node(seg_arr , arr , ind  ,  (int)c , n);
            break;

            case 1:
            cin>>lb;
            cin>>ub;
            cin>>k;
            break;
        }
    }
    return 0;
}
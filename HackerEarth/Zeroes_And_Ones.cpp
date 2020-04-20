 #include <iostream>
 #include <vector>
 #include <cmath>
 #define LARGE 100000
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
        segment_tree[n + i - 1] = arr[i];
    }

    for(int i = n-2; i>=0; i--){
        //printf("%d %d \n" , arr[segment_tree[2 * i + 1]] , arr[segment_tree[2 * i + 2]]);
        segment_tree[i] = segment_tree[2 * i  +1] + segment_tree[2 * i + 2];
    }
}

void update_node(int segment_tree[] , int arr[] , int i ,  int x , int n){
    segment_tree[n + i - 1] = x;

    i = (n-1 + i - 1)/2;

    while(i>=0){
        segment_tree[i] = segment_tree[2 * i + 1] + segment_tree[2 * i + 2];
        //printf("%d\n" , i);
        if(i<1){
            break;
        }
        i = (i-1)/2;
    }
}

int give_ind(int segment_tree[] , int k , int arr_size , int n){
    int i = 0;
    int lc_i = 0 , rc_i = 0;

    if(segment_tree[0]<k){
        return -1;
    }

    while(i<=arr_size-2){
        lc_i = 2 * i + 1;
        rc_i = 2 * i + 2;

        if(segment_tree[lc_i]<k){
            i = rc_i;
            k = k - (segment_tree[lc_i]);
        }else{
            i = lc_i;
        }
    }
    int ans = i - (arr_size - 1);

    if(ans+1>n){
        return -1;
    }

    return (ans + 1);
}

int main(){
    int n;
    cin>>n;

    int arr[LARGE];
    int seg_arr[4 * LARGE];

    for(int i = 0; i<LARGE; i++){
        arr[i] = 1;
    }
    int size = n;
    if(log2(n)-n!=0){
        n = power(2 , (int)(ceil(log2(n))));
    }

    build_tree(seg_arr , arr , n);

    int q;
    cin>>q;

    int op, ind , k;
    for(int i = 0; i<q; i++){
        cin>>op;
        switch(op){
            case 0:
            cin>>ind;
            update_node(seg_arr , arr , ind-1 , 0 , n);
            break;

            case 1:
            cin>>k;
            cout<<give_ind(seg_arr , k , n , size)<<endl;
            break;



        }
        // for(int i = 0; i<2 * n-1; i++){
        //     printf("%d " , seg_arr[i]);
        // }printf("\n");
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#define LARGE 200000
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

void build_max_tree(int segment_tree[] , int arr[] , int n){
    for(int i = 0; i<n; i++){
        segment_tree[n + i - 1] = i;
    }

    for(int i = n-2; i>=0; i--){
        //printf("%d %d \n" , arr[segment_tree[2 * i + 1]] , arr[segment_tree[2 * i + 2]]);
        if(arr[segment_tree[2 * i + 1]]<=arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
    }
}

void build_min_tree(int segment_tree[] , int arr[] , int n){
    for(int i = 0; i<n; i++){
        segment_tree[n + i - 1] = i;
    }

    for(int i = n-2; i>=0; i--){
        //printf("%d %d \n" , arr[segment_tree[2 * i + 1]] , arr[segment_tree[2 * i + 2]]);
        if(arr[segment_tree[2 * i + 1]]>=arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
    }
}

void update_min_node(int segment_tree[] , int arr[] , int i ,  int x , int n){
    arr[i] = x;

    i = (n-1 + i - 1)/2;

    while(i>=0){
        if(arr[segment_tree[2 * i + 1]]>=arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
        //printf("%d\n" , i);
        if(i<1){
            break;
        }
        i = (i-1)/2;
    }
}

void update_max_node(int segment_tree[] , int arr[] , int i ,  int x , int n){
    arr[i] = x;

    i = (n-1 + i - 1)/2;

    while(i>=0){
        if(arr[segment_tree[2 * i + 1]]<=arr[segment_tree[2 * i + 2]]){
            segment_tree[i] = segment_tree[2 * i + 2];
        }else{
            segment_tree[i] = segment_tree[2 * i + 1];
        }
        //printf("%d\n" , i);
        if(i<1){
            break;
        }
        i = (i-1)/2;
    }
}


int next_Right_min(int arr[] , int seg_arr[] , int i , int n){

    int p = 0 , s = 0 , e = n-1 , m = 0 , j = n;
    //printf("\n");
    //printf("\n%d " , p);
    while(p<n-1){
        m = (s + e)/2;
        //printf("%d " , p);
        if(i<=m){
            if(arr[seg_arr[2*p + 2]]<=arr[i]){
                j = 2*p + 2;
            }
            p =2 * p + 1;
            e = m;
        }else{
            p = 2 * p + 2;
            s = m + 1;
        }
        //printf("%d %d\n" , p , j);
        //printf("%d " , j);
    }
    //printf("%d" , j);

    while(j<n-1){
        if(arr[seg_arr[2 * j + 1]]<=arr[i]){
            j = 2 * j + 1;
        }else{
            j = 2 * j + 2;
        }
    }
    //printf("%d\n" , j);
    return seg_arr[j];
}

int next_Right_max(int arr[] , int seg_arr[] , int i , int n){

    int p = 0 , s = 0 , e = n-1 , m = 0 , j = n;
    //printf("\n");
    //printf("\n%d " , p);
    while(p<n-1){
        m = (s + e)/2;
        //printf("%d " , p);
        if(i<=m){
            if(arr[seg_arr[2*p + 2]]>=arr[i]){
                j = 2*p + 2;
            }
            p =2 * p + 1;
            e = m;
        }else{
            p = 2 * p + 2;
            s = m + 1;
        }
        //printf("%d %d\n" , p , j);
        //printf("%d " , j);
    }
    //printf("%d" , j);

    while(j<n-1){
        if(arr[seg_arr[2 * j + 1]]>=arr[i]){
            j = 2 * j + 1;
        }else{
            j = 2 * j + 2;
        }
    }
    //printf("%d\n" , j);
    return seg_arr[j];
}

int RMaxQ(int seg_tree[] , int arr_inp[] , int i , int j , int s , int e , int n , int p){
    if(j<s || e<i){
        return n;
    }else if(i<=s && j>=e){
        return seg_tree[p];
    }
    int m = (s + e)/2;
    int l1 = RMaxQ(seg_tree , arr_inp, i , j , s , m , n , 2 *p + 1);
    int l2 = RMaxQ(seg_tree , arr_inp , i , j , m+1 , e , n , 2 * p + 2);

    if(arr_inp[l1]>arr_inp[l2]){
        return l1;
    }else{
        return l2;
    }
}

int RMinQ(int seg_tree[] , int arr_inp[] , int i , int j , int s , int e , int n , int p){
    if(j<s || e<i){
        return n;
    }else if(i<=s && j>=e){
        return seg_tree[p];
    }
    int m = (s + e)/2;
    int l1 = RMinQ(seg_tree , arr_inp, i , j , s , m , n , 2 *p + 1);
    int l2 = RMinQ(seg_tree , arr_inp , i , j , m+1 , e , n , 2 * p + 2);

    if(arr_inp[l1]<arr_inp[l2]){
        return l1;
    }else{
        return l2;
    }
}

int main(){
    int n, q;
    cin>>n>>q;

    int arr_max[LARGE];
    int arr_min[LARGE];

    for(int i = 0; i<n; i++){
        cin>>arr_max[i];
        arr_min[i] = arr_max[i];
    }

    int size = n;
    //Segment of code to add dummy variables
    if(log2(n) - n!=0){
        n = power(2 , (int)(ceil(log2(n))));
    }

    for(int i = size; i<LARGE; i++){
        arr_min[i] = 10000;
        arr_max[i] = -10000;
    }

    int seg_tree_min[4 * LARGE + 1];
    int seg_tree_max[4 *LARGE + 1];

    build_max_tree(seg_tree_max , arr_max , n);
    build_min_tree(seg_tree_min , arr_min , n);

    char op;
    int x , y; 
    long long int c;

    for(int i = 0;i<q; i++){
        cin>>op;
        switch(op){
            case 'U':
            cin>>x; 
            cin>>y;
            update_max_node(seg_tree_max , arr_max , x-1 , y , n);
            update_min_node(seg_tree_min , arr_min , x-1 , y , n);
            break;

            case 'Q':
            cin>>x;
            cin>>c;
            
            update_max_node(seg_tree_max , arr_max , x-1 , arr_max[x-1] + c , n);
            int max_ind = next_Right_max(arr_max , seg_tree_max , x-1 , n);
            update_max_node(seg_tree_max , arr_max , x-1 , arr_max[x-1] - c , n);

            update_min_node(seg_tree_min , arr_min , x-1 , arr_min[x-1] -c  , n);
            int min_ind = next_Right_min(arr_min , seg_tree_min , x-1 , n);
            update_min_node(seg_tree_min , arr_min , x-1 , arr_min[x-1] + c , n);

            if(arr_max[max_ind]<arr_max[x-1] + c){
                max_ind = size-1;
            }else if(arr_max[max_ind]!=arr_max[x-1] + c){
                max_ind = max_ind - 1;
            }

            if(arr_min[min_ind]>arr_min[x-1]-c){
                min_ind = size-1;
            }else if(arr_min[min_ind]!=arr_min[x-1]-c){
                min_ind = min_ind - 1;
            }
            //cout<<max_ind<<"  "<<min_ind;
            // int ind = (max_ind<min_ind)?max_ind:min_ind;

            // int range_min_ind = RMinQ(seg_tree_min , arr_min , x-1 , ind+1 , 0 , n-1 , n , 0);
            // int range_max_ind = RMaxQ(seg_tree_max , arr_max , x-1 , ind+1 , 0 , n-1 , n , 0);
            
            // int diff1 = arr_max[range_max_ind] - arr_max[x];
            // int diff2 = arr_min[x] - arr_min[range_min_ind];
            int ind1 = RMaxQ(seg_tree_max , arr_max , x-1 , max_ind, 0 , n-1 , n , 0);
            int ind2 = RMinQ(seg_tree_min , arr_min , x-1 , min_ind , 0 , n-1 , n , 0);

            int diff_1 = arr_max[ind1] - arr_max[x-1];
            int diff_2 = arr_min[x-1] - arr_min[ind2];

            int diff = 0;
            diff = (diff_1>diff_2)?diff_1:diff_2;
            if(c<0){
                cout<<"-1 -1"<<endl;
            }else{
                if(min_ind>max_ind){
                    if(max_ind - x + 2==1){
                        diff = 0;
                    }
                    cout<<(max_ind - x + 2)<<" " <<diff<<endl;

                }else if(min_ind<max_ind){
                    if(min_ind - x + 2==1){
                        diff = 0;
                    }
                    cout<<(min_ind - x + 2)<<" "<<diff<<endl;
                }else{ 
                    cout<<(max_ind-x +2)<<" "<<diff<<endl;

                }
            }
            break;
        }
    }
    return 0;
}
 
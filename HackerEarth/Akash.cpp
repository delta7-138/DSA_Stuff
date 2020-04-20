#include <iostream>
#include <vector>
#define LARGE 2000
using namespace std;

void increase(int hash_BIT[][27] , int i1 , int i2 , int x, int n){
    while(i1<=n){
        //cout<<"in increase loop";
        hash_BIT[i1][i2] = hash_BIT[i1][i2] + x;
        i1 = i1 + (i1&(-i1));
        //cout<<"i1 in : "<<i1<<endl;
    }
}

int prefix_sum(int hash_BIT[][27], int i1 , int i2 , int n){
    int sum = 0;
    while(i1>0){
        sum = sum + hash_BIT[i1][i2];
        i1 = i1 - (i1 & (-i1));
        //cout<<"i1: "<<i1<<endl;
    }
    return sum;
}
int main(){
    int hash_BIT[LARGE][27];

    // for(int i = 0; i<LARGE; i++){
    //     for(int j = 0; j<27; j++){
    //         hash_BIT[i][j] = 0;
    //     }
    // }

    int n;
    cin>>n;

    int q;
    cin>>q;

    string str;
    cin>>str;

    for(int i = 1; i<=n; i++){
        increase(hash_BIT , i+1 , str[i] - 'a' , 1 ,  n);
    }

    int op, ind;
    char c;

    int lb , ub , k;
    for(int i = 0; i<q; i++){

        cin>>op;
        //cout<<"ok";
        switch(op){
            case 0:
            cin>>ind;
            cin>>c;

            increase(hash_BIT , ind , str[ind-1] - 'a' , -1 , n);
            str[ind-1] = c;
            increase(hash_BIT , ind , str[ind-1] - 'a' , 1 , n);
            break;

            case 1:
            cin>>lb>>ub>>k;

            int sum = 0, j = 0;
            for(j = 0; j<26; j++){
                sum = sum + (prefix_sum(hash_BIT , ub , j , n)) - prefix_sum(hash_BIT , lb-1 , j , n);

                if(sum>=k){
                    break;
                }
            }
            if(sum>=k){
                cout<<(char)(j + 'a')<<endl;
            }else{
                cout<<"Out of range"<<endl;
            }
            break;
        }
    }
    return 0;
}
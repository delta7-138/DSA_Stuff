#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    vector <int>arr_inp;
    int inp, n;

    cin>>n;
    for(int i = 0;i<n; i++){
        cin>>inp;
        if(inp==0){
            inp = -1;
        }
        arr_inp.push_back(inp);
    }

    vector <int>prefix_sum(n , 0);
    prefix_sum[0] = arr_inp[0];

    map<int , int>pref;
    
    for(int i = 1; i<n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr_inp[i];
        if(pref.count(prefix_sum[i])){
            continue;
        }else{
            pref.insert(pair<int , int>(prefix_sum[i] , 0));
        }
    }

    for(int i = 0; i<pref.size(); i++){
        int start_ind = -1 , end_ind = n;
        for(int j = 0; j<n; j++){
            if(arr_inp[j]==i){
                start_ind = j;
                break;
            }
        }
        for(int j = n-1;j>=0; j--){
            if(arr_inp[j]==i){
                end_ind = j;
                break;
            }
        }
        if(start_ind!=-1 && end_ind!=n){
            pref[i] = end_ind - start_ind;
        }
    }
    int max_length = 0;
    for(int i = 0; i<pref.size(); i++){
        if(pref[i]>max_length){
            max_length = pref[i];
        }
    }

    cout<<max_length;
    return 0;
}
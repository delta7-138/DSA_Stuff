// https://leetcode.com/problems/decode-string/

#include <iostream>
#include <string>
#include <vector>
#define LARGE 100000
using namespace std;

void traverse_stack(string stack[] , int top){
    for(int i = 0; i<=top; i++){
        cout<<stack[i]<<" ";
    }cout<<endl;
}

void push(string stack[] , int *top , string data){
    stack[*top + 1] = data;
    *top = *top + 1;
}

string pop(string stack[] , int *top){
    *top = *top - 1;
    return stack[*top - 1];
}

int main(){
    string ans = "";
    string str_inp;
    cin>>str_inp;

    int len_inp = str_inp.length();
    int i = 0 , top_letter = -1 , top_param = -1;

    string letter_stack[LARGE] , param_stack[LARGE];
    while(i<len_inp){
        string tmp = "";

        if(str_inp[i]>='0' && str_inp[i]<='9'){
            tmp = tmp + str_inp[i];
            push(letter_stack , &top_letter , tmp);

        }else if(str_inp[i]=='[' || str_inp[i]==']'){
            tmp = tmp + str_inp[i];
            push(param_stack , &top_param , tmp);
        }else{
            while(str_inp[i]>='a' && str_inp[i]<='z'){
                tmp = tmp + str_inp[i];
                cout<<tmp<<endl;
                i++;
            }
            push(letter_stack , &top_letter , tmp);
            i--;
        }
        i++;
    }

    //traverse_stack(letter_stack , top_letter);
    //traverse_stack(param_stack , top_param);

    while(top_param>0){
        int ctr = 0, ptr = 0;
        while(param_stack[top_param][0]==']'){
            pop(param_stack , &top_param);
            ctr++;
        }

        string tmp = "", res = "" , num = "";
        while(ptr<(2 * ctr)){
            tmp = letter_stack[top_letter] + tmp;
            res = res + pop(letter_stack , &top_letter);
            num = num + pop(letter_stack , &top_letter);
            ptr+=2;
            for(int i = 0; i<num[0]-'0'; i++){
                tmp = res + tmp;
            }
            ans = ans + tmp;
        }

        while(param_stack[top_param][0]=='['){
            pop(param_stack , &top_param);
        }
    }
    cout<<ans;
    return 0;
}
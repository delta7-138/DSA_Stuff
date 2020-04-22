#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#define LARGE 100000
using namespace std;

struct Node{
    int data;
    struct Node *lc;
    struct Node *rc;
    struct Node *par;
};

struct Node *node_list[2];
int ctr = 0;

int string_to_int(string inp){
    int ans_str = 0;
    int fleg = 0;
    
    int len = inp.length();

    if(inp[0]=='-'){
        fleg++;
    }

    for(int i = 0; i<len; i++){
        if(fleg && i==1){
            continue;
        }
        ans_str = ans_str * 10 + inp[len - i- 1]-'0';
    }
    if(fleg){
        ans_str = -ans_str;
    }
    return ans_str;
}

void find_two_nodes(struct Node *root){
    if(root && ctr<=2){
        int data_lc = (root->lc)?(root->lc->data):(-LARGE);
        int data_rc = (root->rc)?(root->rc->data):(LARGE);

        if(root->data > data_rc || root->data < data_lc){
            node_list[ctr] = root;
            ctr++;
        }
        find_two_nodes(root->lc);
        find_two_nodes(root->rc);
    }
}

void inorder_traversal(struct Node *root){
    if(root){
        inorder_traversal(root->lc);
        printf("%d " , root->data);
        inorder_traversal(root->rc);
    }
}

int main(){
    int n;
    scanf("%d" , &n);

    string inp;
    struct Node *tree[LARGE];
    for(int i = 0; i<n; i++){
        cin>>inp;
        tree[i] = (struct Node *)malloc(sizeof(struct Node));

        if(inp.compare("null")!=0) {
            tree[i]->data = string_to_int(inp);
            tree[i]->par = NULL;
            tree[i]->lc = NULL;
            tree[i]->rc = NULL;
        }else{
            tree[i] = NULL;
        }
    }

    for(int i = 0; i<n; i++){
        if(tree[i]){
            tree[i]->lc = tree[2 * i + 1];
            tree[i]->rc = tree[2 * i + 2];
            tree[i]->par = tree[i-1/2];
        }
    }
    
    inorder_traversal(tree[0]);
    printf("\n");
    find_two_nodes(tree[0]);

    int temp = node_list[0]->data;
    node_list[0]->data = node_list[1]->data;
    node_list[1]->data = temp;
    
    inorder_traversal(tree[0]);
    return 0;
}
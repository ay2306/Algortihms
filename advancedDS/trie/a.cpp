/*
*
*   Question:
*       Given an array of integers, we have to find two elements whose
*       XOR is maximum
*
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int bit;
    struct node* child[2];
};

struct node* newNode(int bit){
    struct node* ptr = new struct node;
    ptr->bit = bit;
    ptr->child[0] = NULL;
    ptr->child[1] = NULL;
    return ptr;
}

string to_binary(int a){
    string ans = "";
    while(a){
        ans+=(char(a%2 + '0'));
        a/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void insert(struct node* root, string a){
    int i = 0;
    for(i = 0; i < a.length(); ++i){
        if(root->child[a[i]-'0'] != NULL)root=root->child[a[i]-'0'];
        else break;
    }
    for(; i < a.length(); ++i){
        root->child[a[i]-'0'] = newNode(a[i]-'0');
        root = root->child[a[i]-'0'];
    }
}

int binary_to_dec(string k){
    int ans = 0;
    for(int i = k.length()-1; i >= 0; --i){
        ans+=((k[i]-'0') << i);
    }
    return ans;
}

int query(struct node* root, int y){
    string yb = to_binary(y);
    string ans = "";
    for(int i = 0; i < yb.length(); ++i){
        if(root->child[1-(yb[i]-'0')]!=NULL){
            root = root->child[1-(yb[i]-'0')];
            ans+=("1");
        }else{
            root = root->child[(yb[i]-'0')];
            ans+=("0");
        }
    }
    cout << ans << endl;
    return binary_to_dec(ans);
}

int main(){
    // int n;
    // cin >> n;   
    // cout << to_binary(n);
    struct node *root = newNode(-1);
    insert(root,to_binary(5));
    insert(root,to_binary(6));
    // cout << binary_to_dec("101");
    cout << query(root,7);
}
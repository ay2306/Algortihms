/*
*
*   Question:
*       Given an array find the subarray with maximum xor
*
*/
#include<bits/stdc++.h>
using namespace std;

class Trie{
    struct node{
    struct node* child[2];
};
    struct node* root;
    unsigned int max_length;
    int n;
    vector<int> arr;
    struct node* newNode(int bit){
        struct node* ptr = new struct node;
        ptr->child[0] = NULL;
        ptr->child[1] = NULL;
        return ptr;
    }

    void insert(int inp){
        struct node* root = this->root;
        string a = to_binary(inp);
        unsigned int i = 0;
        for(i = 0; i < a.length(); ++i){
            if(root->child[a[i]-'0'] != NULL)root=root->child[a[i]-'0'];
            else break;
        }
        for(; i < a.length(); ++i){
            root->child[a[i]-'0'] = newNode(a[i]-'0');
            root = root->child[a[i]-'0'];
        }
    }


    int query(int y){
        struct node* root = this->root;
        string yb = to_binary(y);
        // cout << yb << endl;
        string ans = "";
        for(unsigned int i = 0; i < yb.length(); ++i){
            if(root->child[1-(yb[i]-'0')]!=NULL){
                root = root->child[1-(yb[i]-'0')];
                ans+=("1");
            }else{
                root = root->child[(yb[i]-'0')];
                ans+=("0");
            }
        }
        // cout << ans << endl;
        return binary_to_dec(ans);
    }
    int binary_to_dec(string k){
        long ans = 0;
        // cout << k << endl;
        int j = 0;
        for(int i = k.length()-1; i >= 0; --i,++j){
            ans+=((k[i]-'0') << j);
        }
        // cout << ans << endl;
        return ans;
    }
   
    string to_binary(int a){
        string ans = "";
        // int back_up = a;
        while(a){
            ans+=(char(a%2 + '0'));
            a/=2;
        }
        reverse(ans.begin(),ans.end());
        while(ans.length() != max_length){
            ans  = "0" + ans;
        }
        // cout << back_up << " " <<  ans << endl;
        return ans;
    }
public:
    Trie(){
        root = newNode(-1);
        max_length = 32;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            arr.push_back(a);
        }
    }

    int solution(){
        int ans = 0;
        int pre = 0;
        insert(0);
        for(unsigned int i = 0; i < arr.size(); ++i){
            pre = (pre^arr[i]);
            insert(pre);
            // cout << query(pre) << endl;
            ans = max(ans,query(pre));
        }
        return ans;
    }

};


int main(){

    FILE* freopenReturn = freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        Trie t;
        cout << t.solution() << endl;
    }
    return 0;
}
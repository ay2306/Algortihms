#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define P pair<pair<long long int,long long int> , pair<long long int,long long int> >
using namespace std;

P multi(P a, P b){
    P c;
    c.first.first = (a.first.first*b.first.first + a.first.second*b.second.first)%MOD;
    c.first.second = (a.first.first*b.first.second + a.first.second*b.second.second)%MOD;
    c.second.first = (a.second.first*b.first.first + a.second.second*b.second.first)%MOD;
    c.second.second = (a.second.first*b.first.second + a.second.second*b.second.second)%MOD;
    return c;
}

P binaryExponent(P a,ll n){
    if(n == 1)return a;
    P c = multi(a,a);
    c = binaryExponent(c,n/2);
    if(n%2 == 1){
        c = multi(c,a);
    }
    return c;
}


int main(){
    ll n;
    cin >> n;
    if(n < 0){cout << "0";return 0;}
    if(n == 1 || n == 0){cout << "1";return 0;}
    P a = make_pair(make_pair(1,1),make_pair(1,0));
    P ans = make_pair(make_pair(-1,-1),make_pair(-1,-1));
    n--;
    ll ab = 1;
    int i = 0;
    vector<int> v;
    while((ab << i) <= n){
        if((n >> i)&1 == 1){
            v.push_back(i);
        }
        ++i;
    }
    for(vector<int>::reverse_iterator itr = v.rbegin(); itr != v.rend(); ++itr){
        int i = *itr;
        // cout << (ab << i) << endl;
        P d = binaryExponent(a,(ab << i));
        if(ans.first.first == -1 && ans.first.second == -1 && ans.second.first == -1 && ans.second.second == -1){
            ans = d;
        }else{
            ans = multi(d,ans);
        }
        // cout << d.first.first << " " << d.first.second << endl;
        // cout << d.second.first << " "  << d.second.second << endl;
    }
    P c = ans;
    // P c = binaryExponent(a,n);
    // cout << c.first.first << " " << c.first.second << endl;
    // cout << c.second.first << " "  << c.second.second << endl;
    cout << c.first.first+c.first.second << endl;
}

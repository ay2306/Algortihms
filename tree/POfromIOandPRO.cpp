/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
V<int> post_order;
int search(int *arr, int x, int n){
    for(int i = 0; i < n; ++i)if(arr[i] == x)return i;
    return -1;
}

void printPostOrder(int *in, int *pre, int n){
    int root = search(in,pre[0],n);
    if(root != 0){
        printPostOrder(in,pre+1,root);
    }
    if(root != n-1){
        printPostOrder(in+root+1,pre+root+1,n-root-1);
    }
    post_order.pb(pre[0]);
}

int main(){
    int in[] = {4,2,5,1,3,6};
    int pre[] = {1,2,4,5,3,6};
    int n = sizeof(in)/sizeof(in[0]);
    printPostOrder(in, pre, n);
    for(int i = 0; i < post_order.size(); ++i)cout << post_order[i] << " ";
    cout << "\n";
    return 0;
}
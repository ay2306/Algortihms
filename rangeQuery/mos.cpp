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

int block;

struct Query{
    int l,r;
};


bool compare(Query x, Query y){
    if(x.l/block != y.l/block)return x.l/block < y.l/block;
    return x.r < y.r;
}

int queryResult(int a[], int n, Query q[], int m){
    block = (int)sqrt(n);
    sort(q,q+m,compare);
    cout << "BLOCK = " << block << endl;
    for(int i = 0; i < m; ++i){
        cout << "{" << q[i].l << ", " << q[i].r << "}\n";
    }
    int currL = 0; 
    int currR = 0;
    int currSum = 0;
    for(int i = 0; i < m; ++i){
        int L = q[i].l, R = q[i].r;
        while(currL < L){
            currSum -= a[currL];
            currL++;
        }
        while(currL > L){
            currSum += a[currL-1];
            currL--;
        }
        while(currR <= R){
            currSum += a[currR];
            currR++;
        }
        while(currR > R+1){
            currSum -= a[currR-1];  
            currR--;
        }
        cout << currSum << endl;
    }
}

int main(){
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q)/sizeof(q[0]);
    queryResult(a,n,q,m);
    return 0;
}
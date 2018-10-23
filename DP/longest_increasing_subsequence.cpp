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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     int *dp = new int[n];
//     for(int i = 0; i < n; ++i){
//         cin >> arr[i];
//     }    
//     for(int i = 0; i < n; ++i){
//         dp[i] = 1;
//         for(int j = 0; j < i; ++j){
//             if(arr[j] < arr[i]){
//                 dp[i] = max(dp[i],dp[j]+1);
//             }
//         }
//     }
//    return 0;
// }

// O(nlogn) approach

int main(){
    vector<int> arr,q;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i = 0; i < n; ++i){
        int index = lower_bound(q.begin(),q.end(),arr[i]) - q.begin();
        if(index == q.size())q.push_back(arr[i]);
        else q[index] = arr[i];
    }
    cout << q.size();
    return 0;
}
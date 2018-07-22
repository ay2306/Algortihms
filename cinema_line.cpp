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

int main(){
    int arr[3] = {0,0,0};
    int n;
    cin >> n;
    for(int i = 0,a; i < n; ++i){
        cin >> a;
        if(a == 100){
            if(arr[1] > 0 && arr[0] > 1){
                arr[0]--;
                arr[1]--;
            }else if(arr[1] == 0 && arr[0] > 2){
                arr[0]-=3;
            }else{
                cout << "NO";
                return 0;
            }
            arr[2]++;
        }
        if(a == 50){
            if(arr[0] == 0){
                cout << "NO";
                return 0;
            }
            a[0]--;
            a[1]++;
        }
        if(a == 25)a[0]++;
    }
    cout << "YES";
    return 0;
}
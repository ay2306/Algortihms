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

ll readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
 
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
 
	if (ch == '-') minus = true; else result = ch-'0';
 
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
 
	if (minus)
		return -result;
	else
		return result;
 
}
int main(){
	int n;
	cin >> n;
	int two = n/18;
	int rem = n%18;
	long long int ans = 1;
	for(int i = 0; i < two; ++i){
		ans*=(30);
	}
	if(ans == 1)rem--;
	switch(rem){
		case 0: ans*=1;
				break;
		case 1: ans*=2;
				break;
		case 2: ans*=3;
				break;
		case 3: ans*=4;
				break;
		case 4: ans*=5;
				break;
		case 5: ans*=6;
				break;
		case 6: ans*=8;
				break;
		case 7: ans*=9;
				break;
		case 8: ans*=10;
				break;
		case 9: ans*=12;
				break;
		case 10: ans*=15;
				break;
		case 11: ans*=16;
				break;
		case 12: ans*=18;
				break;
		case 13: ans*=20;
				break;
		case 14: ans*=21;
				break;
		case 15: ans*=24;
				break;
		case 16: ans*=25;
				break;
		case 17: ans*=27;
				break;
	}
	cout << ans;
   return 0;
}
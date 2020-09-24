// #include <bits/stdc++.h>
// #define ull unsigned long long int
// #define ll long long int
// #define P pair
// #define PLL pair<long long, long long>
// #define PII pair<int, int>
// #define PUU pair<unsigned long long int, unsigned long long int>
// #define L list
// #define V vector
// #define S set
// #define MS multiset
// #define M map
// #define mp make_pair
// #define pb push_back
// #define MM multimap
// #define IT iterator
// #define RIT reverse_iterator
// #define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

// using namespace std;

// class graph{
//     int v;
//     V<V<int> > adj;
//     vector<int> topologicalSortVector;
//     int indexing;
// public:
//     graph(int v, int indexing){
//         this->v = v;
//         this->adj = V<V<int> > (v,V<int>());
//         this->indexing = indexing;
//     }
//     void addEdge(int a, int b){
//         if(indexing == 1){
//             a--;
//             b--;
//         }
//         adj[a].push_back(b);
//     }
//     // vector<int> topSortUtil(){
//     void topSortUtil(){
//         vector<bool> visited = vector<bool>(this->v, false);
//         vector<int> inDegree = vector<int>(this->v, 0);
//         vector<int> ans;
//         queue<int> q;
//         for(auto i: adj){
//             for(auto k: i){
//                 inDegree[k]++;
//             }
//         }
//         for(int i = 0; i < this->v; ++i){
//             if(inDegree[i] == 0){
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//         int level = 0;
//         unordered_map<int,vector<int> > m;
//         while(q.size()){
//             vector<int> nl;
//             int sz = q.size();
//             for(int l = 0; l < sz; ++l){
//                 int vertex = q.front();
//                 nl.push_back(q.front());
//                 q.pop();
//                 for(auto i : adj[vertex]){
//                     if(!visited[i]){
//                         inDegree[i]--;
//                         if(inDegree[i] == 0){
//                             q.push(i);
//                             visited[i] = true;
//                         }
//                     }
//                 }
//             }
//             m[level++] = nl;
//         }
//         for(int i = 0; i < level; ++i){
//             vector<int> arr = m[i];
//             sort(arr.begin(),arr.end());
//             for(auto i: arr)cout << i+1 << " ";
//         }
//         // return ans;
//     }
//     void topSort(){
//         // vector<int> ans = topSortUtil();
//         topSortUtil();
//     }
//     void topSortDisplay(){
//         topSort();
//         cout << endl;
//     }
// };

// int main(){
//     int n,m;
//     cin >> n >> m;
//     graph g(n,1);
//     for(int i =0 ; i < m; ++i){
//         int a,b;
//         cin >> a >> b;
//         g.addEdge(a,b);
//     }
//     g.topSortDisplay();
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b){
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    map<string,int> m;
    while(n--){
        string a;
        cin >> a;
        m[a]++;
    }
    vector<pair<string,int> > arr;
    for(auto i: m){
        arr.push_back(make_pair(i.first,i.second));
    }
    sort(arr.begin(),arr.end(),cmp);
    for(map<string,int>::iterator itr = m.begin(); itr != m.end(); ++itr){
        cout << itr->first << " " << itr->second << "\n";
    }
    
    return 0;
}
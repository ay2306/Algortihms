#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> > adj;
vector<bool> visited;
vector<bool> is_cut;
vector<int> tym;
vector<int> parent;
vector<int> child;
vector<int> low;
vector<pair<int,int> > bridges;
int id = 0;
map<pair<int,int>, int> mp;
void dfs(int i){
    static int c = 0;
    visited[i] = true;
    id++;
    low[i] = c;
    tym[i] = c++;
    for(auto k: adj[i]){
        int curr = k;
        if(curr == parent[i]){
            continue;
        }
        if(!visited[k]){
            child[k]++;
            parent[k] = i;
            dfs(k);
            low[i] = min(low[i],low[k]);
            if(tym[i] <= low [k]){
                // bridges.push_back(make_pair(i,k));
                mp[make_pair(min(i,k),max(i,k))]++;    
                is_cut[i] = true;
            }
        }else{
            low[i] = min(low[i],tym[k]);
        }
    }
}

void solve(){
    vector<int> ans;
    adj = vector<vector<int> > (n, vector<int> ());
    visited = vector<bool> (n, false);
    is_cut = vector<bool> (n, false);
    tym = vector<int> (n, 0);
    parent = vector<int> (n, 0);
    child = vector<int> (n, 0);
    low = vector<int> (n, 0);
    for(int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[0] = -1;
    dfs(0);
    is_cut[0] = ((child[0] > 1)?true:false);
    for(int i = 0; i < n; ++i){
        if(is_cut[i])ans.push_back(i);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(),ans.end());
    for(auto i: ans){
        cout << i << "\n";
    }
    cout << mp.size() << "\n";
    for(auto i: mp){
        cout << i.first.first << " " << i.first.second << "\n";
    }
}

int main(){
    cin >> n;
    cin >> m;
    solve();
    
}
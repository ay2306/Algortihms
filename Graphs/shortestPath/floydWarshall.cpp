#include<bits/stdc++.h>
using namespace std;

class Graph{
int V;
vector<vector<int> > adj;
vector<vector<int> > path;
public:
    Graph(int V);
    void addEdge(int a, int b, int w);
    void floydWarshall();
    int getShortestPath(int a, int b);
};
Graph::Graph(int V){
    this->V = V;
    adj = vector<vector<int> >(this->V+1,vector<int> (this->V+1,0));
    path = vector<vector<int> >(this->V+1,vector<int> (this->V+1,INT_MAX));
}

void Graph::addEdge(int a, int b, int w){
    adj[a][b] = max(w,0);
}

void Graph::floydWarshall(){
    for(int k = 1; k <= this->V; ++k){
        for(int i = 1; i <= this->V; ++i){
            for(int j = 1; j <= this->V; ++j){
                if(adj[i][j] != 0){
                    path[i][j] = min(adj[i][j],path[i][j]);
                }
                if(path[i][k] != INT_MAX && path[k][j] != INT_MAX);
                path[i][j] = min(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
}

int Graph::getShortestPath(int a, int b){
    return path[a][b];
}

int main(){
    int v;
    cin >> v;
    int e;
    cin >> e;
    Graph g(v);
    for(int i = 0; i < e; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        g.addEdge(a,b,c);
    }
    g.floydWarshall();
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        int d = g.getShortestPath(a,b);
        if(d == INT_MAX){
            cout << "NO PATH\n";
        }else{
            cout << "Shortest Path from " << a << " " << b << " is " << d << "\n";
        }
    }
}
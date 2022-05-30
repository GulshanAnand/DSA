#include <bits/stdc++.h>
using namespace std;

bool canColor(vector<int> adj[],vector<int> color, int n, int node, int col){
    for(auto v : adj[node]){
        if(color[v] == col) return false; 
    }
    return true;
}

bool mColor(vector<int> adj[], int m, vector<int> color, int n, int node){
    if(node >= n) return true;
    for(int col = 1;col<=m;col++){
        if(canColor(adj, color, n, node, col)){
            color[node] = col;
            if(mColor(adj,m,color,n,node+1)) return true;
            color[node] = 0;   
        }
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n,0);
    cout<<mColor(adj, 3, color, n, 0);
    return 0;
}
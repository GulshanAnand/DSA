#include <bits/stdc++.h>

using namespace std;
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
typedef long long ll;

vector<int> adj[100];
int visited[100];
bool bipartite = true;

void checkBipartite(int v, int par){
    if(visited[v] == 0){
        if(visited[par] == 1){
            visited[v] = 2;
        }
        else{
            visited[v] = 1;
        }
        for(int el : adj[v]){
            checkBipartite(el, visited[v]);
        }
    }
    else if(visited[v] == 1){
        if(visited[par] == 1){
            bipartite = false;
        }
    }
    else{
        if(visited[par] == 2){
            bipartite = false;
        }
    }
}

void dfs(int v){
    visited[v] = 1;
    cout<<v<<" ";
    for(int el : adj[v]){
        if(!visited[el]){
            dfs(el);
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for(int i=0;i<100;i++){
        visited[i] = 0;
    }
    // dfs(1);
    checkBipartite(1,1);
    cout<<bipartite;
    return 0;
}

/* Code to check if a graph is bipartite or not:
Problem link:
https://www.codechef.com/problems/BPTGH

vector<int> adj[10000];
int vis[10000]={0};

bool dfs(int node, int curr){
    vis[node] = curr;
    for(int i=0;i<adj[node].size();i++){
        if(vis[adj[node][i]] == curr) return false;
        if(vis[adj[node][i]] == 0)
            dfs(adj[node][i], 3-curr);
    }
    return true;
}

int main(){
    FIO;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ans = true;
    for(int i=1;i<=n;i++){
        if(vis[i] == 0)
            ans = ans&dfs(i,1);
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
*/
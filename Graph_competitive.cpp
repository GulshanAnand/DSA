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
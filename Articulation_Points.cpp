#include <bits/stdc++.h>
using namespace std;

int timer = 1;
    
void dfs(int node, int par, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark, vector<int> adj[]){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    
    int child = 0;
    for(auto ch:adj[node]){
        if(!vis[ch]){
            dfs(ch, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[ch]);
            if(low[ch] >= tin[node] && par != -1){
                mark[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], tin[ch]);
        }
    }
    
    if(child > 1 && par == -1){
        mark[node] = 1;
    }
}

int main(){
	cout<<"Enter no. of vertices and edges:";
	int n,e;
	cin>>n>>e;
	cout<<"Enter the edges:\n";
	vector<int> adj[n];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
    vector<int> vis(n, 0);
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> mark(n+1, 0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }

    vector<int> ap;
    for(int i=0;i<n;i++){
        if(mark[i]) ap.push_back(i);
    }

    cout<<"Articulation Points in the Graph:\n";
    for(auto e:ap) cout<<e<<" ";

	return 0;
}
/*
Input:
12 14
0 1
1 2
2 3
3 0
3 4
4 5
5 6
6 7
7 8
8 5
7 9
9 10
9 11
10 11

Output:
3 4 5 7 9
*/
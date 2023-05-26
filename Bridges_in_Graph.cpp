#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bridges;
int timer = 1;

void dfs(int node, int par, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[]){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;

    for(auto ch:adj[node]){
        if(ch != par){
            if(!vis[ch]){
                dfs(ch, node, vis, tin, low, adj);
                low[node] = min(low[node], low[ch]);
                if(low[ch] > tin[node]){
                    bridges.push_back({node, ch});
                }
            }
            else{
                low[node] = min(low[node], low[ch]);
            }
        }
    }
}

void tarjan(vector<int> adj[], int n){
    vector<int> vis(n, 0);
    vector<int> tin(n);
    vector<int> low(n);
    dfs(0, -1, vis, tin, low, adj);
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
	
    tarjan(adj, n);

    cout<<"Bridges in the Graph:\n";

    for(auto v:bridges){
        cout<<v[0]<<" "<<v[1]<<'\n';
    }

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
10 11
11 9

Output:
3 4
4 5
7 9
*/
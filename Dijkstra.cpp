#include <bits/stdc++.h>
using namespace std;
#define inf 1000000

void dijkstra(int s, vector<pair<int,int>> adj[], vector<int> &dist, vector<int> &mark, int n){
	dist[s] = 0;
    set<pair<int,int>> st;
    st.insert({0, s});
    while(st.size() > 0){
        pair<int,int> p = *st.begin();
        st.erase(st.begin());
        int u = p.second;
        int w = p.first;
        if(mark[u]) continue;
        mark[u] = 1;
        for(auto ed:adj[u]){
            int v = ed.first;
            int wt = ed.second;
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                st.insert({dist[v], v});
            }
        }
    }
}

int main(){
	cout<<"Enter no. of vertices and edges:";
	int n,e;
	cin>>n>>e;
	int s;
	cout<<"Enter the edges and their weights:\n";
	vector<pair<int,int>> adj[n];
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	cout<<"Enter source vertex: ";
	cin>>s;
	vector<int> dist(n);
	for(int i=0;i<n;i++){
		dist[i] = inf;
	}
    vector<int> mark(n, 0);
	dijkstra(0, adj, dist, mark, n);
	cout<<"vertices with corresponding shortest path lengths are:\n";
	for(int i=0;i<n;i++){
		cout<<i<<" "<<dist[i]<<"\n";
	}

	return 0;
}
/*
Input:
9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 5 4
2 3 7
6 5 2
3 4 9
4 5 10
3 5 14
0

Output:
0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14
*/
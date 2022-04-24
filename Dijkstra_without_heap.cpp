#include <bits/stdc++.h>
using namespace std;
#define inf 1000000

int findMinIndex(int dist[], int mark[], int n){
	int idx = 0;
	for(int i=0;i<n;i++){
		if(mark[i] == 0){
			idx = i;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(mark[i] == 0 && dist[i] < dist[idx]){
			idx = i;
		}
	}
	return idx;
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
	int dist[n];
	int mark[n] = {0};
	for(int i=0;i<n;i++){
		dist[i] = inf;
	}
	dist[s] = 0;
	for(int i=0;i<n;i++){
		int u = findMinIndex(dist, mark, n);
		mark[u] = 1;
		for(auto ed:adj[u]){
			int cost = ed.second;
			int v = ed.first;
			if(dist[u] + cost < dist[v]){
				dist[v] = dist[u] + cost;
			}
		}
	}
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
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N+1]; 
    int w[N+1][N+1]={0};
	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
        w[a][b] = wt;
        w[b][a] = wt;
	}	
	
	int parent[N+1]; 
      
    int key[N+1]; 
      
    bool mstSet[N+1]; 
  
    for (int i = 1; i <= N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  

    key[1] = 0; 
    parent[1] = -1; 
    int ansWeight = 0;
    for (int count = 1; count <= N - 1; count++)
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 1; v <= N; v++) 
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
                
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 2; i <= N; i++){
        cout << parent[i] << " - " << i <<" \n";
        ansWeight += w[parent[i]][i];
    }
    cout<<"The minimum cost is: "<<ansWeight<<endl;
	return 0;
}

/*
Input:
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7

Output:
1 - 2 
2 - 3 
1 - 4 
1 - 5 
2 - 6 
The minimum cost is: 17
*/
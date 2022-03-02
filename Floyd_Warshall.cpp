#include<bits/stdc++.h>
using namespace std;

#define inf 10000000

int main(){
    int n,m;
    cin>>n>>m;
	int dist[n+1][n+1];
	for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else dist[i][j] = inf;
        }
    }

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        dist[u][v] = wt;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] < inf) cout<<dist[i][j]<<" ";   
            else cout<<"I ";
        }
        cout<<endl;
    }

	return 0;
}

/*
Input:
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2

Output:
0 1 3 3 2 4 
I 0 2 2 1 3 
I I 0 I 2 4 
I I I 0 3 1 
I I I I 0 2 
I I I I I 0 
*/
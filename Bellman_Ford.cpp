#include <bits/stdc++.h>
using namespace std;
#define inf 100000

//Bellman Ford Algorithm
int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<pair<int,int>,int>> g(e);
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[i].first.first = a;
        g[i].first.second = b;
        g[i].second = w;
    }
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i] = inf;
    }
    dist[0] = 0;
    for(int c=0;c<n-1;c++){
        for(int i=0;i<e;i++){
            int u = g[i].first.first;
            int v = g[i].first.second;
            int w = g[i].second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    cout<<"Single source shortest path is:\n";
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}
/*
6 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3


Output:
Single source shortest path is:
0 5 3 3 1 2
*/
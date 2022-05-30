#include <bits/stdc++.h>
using namespace std;

#define inf 100000
#define N 50000
vector<int> adj[N];
bool visited[N] = {false};
int level[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int cv = q.front();
        q.pop();
        for(int child : adj[cv]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[cv] + 1;
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    int wt[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            wt[i][j] = inf;
        }
    }
    
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(b);
        wt[a][b] = w;
    }
    int source,destination;
    cin>>source>>destination;
    for(int i=0;i<N;i++){
        level[i] = -1;
    }
    level[source] = 0;
    bfs(source);
    
    int n_stages = 0;
    for(int i=1;i<=n;i++){
        n_stages = max(n_stages, level[i]);
    }
    vector<vector<int>> stage_graph(n_stages+1);
    for(int j=0;j<=n_stages;j++){
        for(int i=0;i<N;i++){
            if(level[i] == j){
                stage_graph[j].push_back(i);
            }
        }
    }

    int cost[n+1];

    for(int i=0;i<=n;i++){
        cost[i] = inf;
    }
    cost[n] = 0;
    cout<<"Number of stages: "<<n_stages+1<<endl;
        cout<<"Vertices in stages:\n";
        for(int i=0;i<=n_stages;i++){
            for(auto e:stage_graph[i]){
                cout<<e<<" ";
            }
            cout<<endl;
        }

    for(int i=0;i<=n;i++){
        cost[i] = inf;
    }
    cost[destination] = 0;

    // for(int i=n_stages;i>=0;i--){
    //     for(int j=0;j<stage_graph[i].size();j++){
    //         for(auto v:adj[stage_graph[i][j]]){
    //             cost[stage_graph[i][j]] = min(cost[stage_graph[i][j]], cost[v] + wt[stage_graph[i][j]][v]);
    //         }
    //     }
    // }

    for(int u = destination-1;u>=source;u--){
        for(auto v:adj[u]){
            cost[u] = min(cost[u], wt[u][v] + cost[v]);
        }
    }

    for(int i=0;i<n;i++) cout<<cost[i]<<" ";

    vector<int> path;
    path.push_back(source);
    int cv = source;
    while(cv != destination){
        int minCost = INT_MAX;
        int ver;
        for(auto v:adj[cv]){
            if(cost[v] < minCost){
                minCost = cost[v];
                ver = v;
            }
        }
        path.push_back(ver);
        cv = ver;
    }


    // int ver = source;
    // while(ver != destination){
    //     int cv = path.back();
    //     for(auto v:adj[ver]){
    //         if(cost[v] <= cost[cv]){
    //             path.push_back(v);
    //             ver = v;
    //         }
    //     }
    // }
    cout<<"Shortest path is: ";
    for(auto e:path) cout<<e<<" ";
    return 0;
}

/*
input:
8 12
0 1 1
0 3 5
0 2 2
1 4 4
1 5 11
2 4 9
2 5 5
2 6 16
3 6 2
4 7 18
5 7 13
6 7 2
0 7


Output:
0 3 6 7



9 22 18 4 18 13 2 0
*/
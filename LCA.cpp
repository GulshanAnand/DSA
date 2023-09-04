#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1135/
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int
int m;

void dfs(int node, int par, vector<int> adj[], vector<int> &lvl, vector<vector<int>> &dp){
    lvl[node] = lvl[par] + 1;
    dp[node][0] = par;
    for(int i=1;i<=m;i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    for(auto ch:adj[node]){
        if(ch != par){
            dfs(ch, node, adj, lvl, dp);
        }
    }
}

int lca(int a, int b, vector<int> &lvl, vector<vector<int>> &dp){
    if(lvl[a] < lvl[b]) swap(a, b);
    int diff = lvl[a] - lvl[b];
    for(int i=0;i<=m;i++){
        if((diff>>i)&1){
            a = dp[a][i];
        }
    }
    if(a == b) return a;
    for(int i=m;i>=0;i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int32_t main(){
    FIO;
    int n,q;
    cin>>n>>q;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    m = ceil(log2(n));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<int> lvl(n+1, 0);
    dfs(1, 0, adj, lvl, dp);    

    while(q--){
        int a,b;
        cin>>a>>b;
        int x = lvl[a] + lvl[b] - 2*lvl[lca(a, b, lvl, dp)];
        cout<<x<<'\n';
    }
    return 0;
}
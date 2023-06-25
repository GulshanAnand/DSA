#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int
// https://cses.fi/problemset/task/1687
int32_t main(){
    FIO;
    int n,q;
    cin>>n>>q;

    int m = log2(n);
    vector<vector<int>> par(n+1, vector<int>(m+1, -1));

    for(int i=2;i<=n;i++){
        cin>>par[i][0];
    }

    for(int i=1;i<=m;i++){
        for(int node=1;node<=n;node++){
            int v = par[node][i-1];
            if(v != -1){
                par[node][i] = par[v][i-1];
            }
        }
    }

    while(q--){
        int x,k;
        cin>>x>>k;
        int boss = x;
		for(int i=0;i<=20;i++){
            if(k&(1<<i)){
                boss = par[boss][i];
            }
            if(boss == -1) break;
        }		
        cout<<boss<<"\n";
    }

    return 0;
}
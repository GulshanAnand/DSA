#include <bits/stdc++.h>
using namespace std;
 
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int
//https://cses.fi/problemset/task/1648/

int n;
vector<int> bit;
 
void update(int k, int d){
    while(k <= n){
        bit[k] += d;
        k += (k&(-k));
    }
}
 
int query(int k){
    int x = 0;
    while(k > 0){
        x += bit[k];
        k -= (k&(-k));
    }
    return x;
}
 
int32_t main(){
    FIO;
    int TC = 1;
    // cin>>TC;
    while(TC-->0){
        int q;
        cin>>n>>q;
        vector<int> a(n+1, 0);
        for(int i=0;i<n;i++) cin>>a[i+1];
 
        bit.resize(n+1, 0);
        for(int i=1;i<=n;i++){
            update(i, a[i]);
        }
 
        while(q--){
            int t;
            cin>>t;
            if(t == 1){
                int k, u;
                cin>>k>>u;
                int x = query(k);
                x -= query(k-1);
                int d = u - x;
                update(k, d);
            }
            else{
                int l, r;
                cin>>l>>r;
                int x = query(r) - query(l-1);
                cout<<x<<'\n';
            }
        }
    }
    return 0;
}
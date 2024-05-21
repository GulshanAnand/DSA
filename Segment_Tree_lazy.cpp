#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int

void build(int idx, int l, int r, vector<int> &seg, vector<int> &a){
    if(l == r){
        seg[idx] = a[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*idx+1, l, mid, seg, a);
    build(2*idx+2, mid+1, r, seg, a);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int query(int l, int r, int idx, int x, int y, vector<int> &seg, vector<int> &lazy){
    int n = lazy.size();
    if(lazy[idx]){
        seg[idx] += (r-l+1)*lazy[idx];
        if(2*idx+1 < n) lazy[2*idx+1] += lazy[idx];
        if(2*idx+2 < n) lazy[2*idx+2] += lazy[idx];
        lazy[idx] = 0;
    }
    if(x<=l && y>=r){
        return seg[idx];
    }
    if(y < l || x > r){
        return 0;
    }
    int mid = l + (r-l)/2;
    return query(l, mid, 2*idx+1, x, y, seg, lazy) + query(mid+1, r, 2*idx+2, x, y, seg, lazy);
}

void update(int idx, int l, int r, int x, int y, int v, vector<int> &seg, vector<int> &lazy){
    int n = lazy.size();
    if(lazy[idx]){
        seg[idx] += (r-l+1)*lazy[idx];
        if(2*idx+1 < n) lazy[2*idx+1] += lazy[idx];
        if(2*idx+2 < n) lazy[2*idx+2] += lazy[idx];
        lazy[idx] = 0;
    }
    if(x <= l && y >= r){
        seg[idx] += (r-l+1)*v;
        if(2*idx+1 < n) lazy[2*idx+1] += v;
        if(2*idx+2 < n) lazy[2*idx+2] += v;
        return;
    }
    if(y < l || x > r){
        return;
    }
    int mid = l + (r-l)/2;
    update(2*idx+1, l, mid, x, y, v, seg, lazy);
    update(2*idx+2, mid+1, r, x, y, v, seg, lazy);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int32_t main(){
    FIO;
    int TC = 1;
    // cin>>TC;
    while(TC-->0){
        int n,q;
        cin>>n>>q;
        vector<int> a(n+1);
        vector<int> seg(4*n+1), lazy(4*n+1);
        for(int i=0;i<n;i++) cin>>a[i];

        build(0, 0, n-1, seg, a);

        while(q--){
            int t;
            cin>>t;
            if(t == 1){
                int x,y,v;
                cin>>x>>y>>v;
                x--;
                y--;
                update(0, 0, n-1, x, y, v, seg, lazy);
            }
            else{
                int p;
                cin>>p;
                p--;
                int ans = query(0, n-1, 0, p, p, seg, lazy);
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int

void build(int idx, int l, int r, vector<int> &seg, vector<int> &a){
    if(r == l){
        seg[idx] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*idx+1, l, mid, seg, a);
    build(2*idx+2, mid+1, r, seg, a);
    seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
}

int query(int x, int y, int idx, int l, int r, vector<int> &seg){
    if(l >= x && r <= y){
        return seg[idx];
    }
    if(l > y || r < x){
        return 2e9; 
    }
    int mid = (l + r)/2;
    return min(query(x, y, idx*2+1, l ,mid, seg), query(x, y, idx*2+2, mid+1, r, seg));
}

void update(int pos, int val, int idx, int l, int r, vector<int> &seg){
    if(r == l){
        seg[idx] = val;
        return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
        update(pos,val,idx*2+1, l, mid, seg);
    }
    else{
        update(pos,val,idx*2+2, mid+1, r, seg);
    }
    seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
}

int32_t main(){
    FIO;
    int n;
    cin>>n;
    vector<int> a(n);
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> seg(4*n);
    build(0, 0, n-1, seg, a);
    
    while(q-->0){
        int t;
        cin>>t;
        if(t == 1){
            int i,val;
            cin>>i>>val;
            i--;
            update(i, val, 0, 0, n-1, seg);
        }
        else{
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            cout<<query(x, y, 0, 0, n-1, seg)<<endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
typedef long long ll;
#define int long long int
#define inf 1e9+1

int n; // size of arr
vector<int> arr;  // original array
vector<int> seg;

void build(int idx = 0, int l = 0, int r = n-1){
    if(r == l){
        // Leaf node
        seg[idx] = arr[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*idx+1, l, mid); // left child
    build(2*idx+2, mid+1, r); // right child
    seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
}

int query(int x, int y, int idx = 0, int l = 0, int r = n-1){
    if(l >= x && r <= y){
            // When [L,R) is entirely inside [x,y)
        return seg[idx];
    }
    if(l > y || r < x){
        // When [L,R) is entirely outside [x,y)
        return inf; 
    }
    int mid = (l + r)/2;
    return min(query(x, y, idx*2+1, l ,mid), query(x, y, idx*2+2, mid+1, r));
}

void modify(int pos, int val, int idx = 0, int l = 0, int r = n-1){
    if(r == l){
        // leaf node
        arr[pos] = val;
        seg[idx] = val;
        return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
        modify(pos,val,idx*2+1, l, mid);
    }
    else{
        modify(pos,val,idx*2+2, mid+1, r);
    }
    seg[idx] = min(seg[idx*2+1], seg[idx*2+2]);
}

int32_t main(){
    FIO;
    cin>>n;
    arr.resize(n);
    seg.resize(4*n);
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build();
    
    while(q-->0){
        int t;
        cin>>t;
        if(t == 1){
            int i,val;
            cin>>i>>val;
            modify(i, val);
        }
        else{
            int x,y;
            cin>>x>>y;
            cout<<query(x, y-1)<<endl;
        }
    }
    return 0;
}
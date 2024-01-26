#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/220/problem/B
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int
const int BLK = 360;

struct query{
    int l;
    int r;
    int idx;
};

bool cmp(query &a, query &b){
    if((a.l)/BLK != (b.l)/BLK){
        return (a.l)/BLK < (b.l)/BLK;
    }
    return a.r < b.r;
}

void add(int x, int &ans, vector<int> &a, unordered_map<int,int> &mp){
    int k = a[x];
    int f = mp[k];
    if(k == f){
        ans--;
    }
    mp[k]++;
    if(k == mp[k]) ans++;
}

void remove(int x, int &ans, vector<int> &a, unordered_map<int,int> &mp){
    int k = a[x];
    int f = mp[k];
    if(k == f){
        ans--;
    }
    mp[k]--;
    if(k == mp[k]) ans++;
}

int32_t main(){
    FIO;
    int TC = 1;
    // cin>>TC;
    while(TC-->0){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        vector<query> v(q);
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            v[i] = {l, r, i};
        }
        sort(v.begin(), v.end(), cmp);

        int ans = 0;
        unordered_map<int,int> mp;
        vector<int> res(q);

        int x = 0, y = -1;
        for(int i=0;i<q;i++){
            int l = v[i].l;
            int r = v[i].r;
            while(x > l){
                x--;
                add(x, ans, a, mp);
            }
            while(x < l){
                remove(x, ans, a, mp);
                x++;
            }
            while(y < r){
                y++;
                add(y, ans, a, mp);
            }
            while(y > r){
                remove(y, ans, a, mp);
                y--;
            }
            res[v[i].idx] = ans;
        }

        for(auto e:res) cout<<e<<'\n';
    }
    return 0;
}
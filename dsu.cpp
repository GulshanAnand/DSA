#include<bits/stdc++.h>
using namespace std;
#define N 100010

vector<int> par;
vector<int> sz;

void make(int v){
    par[v] = v;
    sz[v] = 1;
}

int find(int v){
    if(v == par[v]) return v;
    //Path compression
    return par[v] = find(par[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    par.resize(N);
    sz.resize(N);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(k-- > 0){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    int connected_components = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == i) connected_components++;
    }
    return 0;
}
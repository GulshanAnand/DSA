#include<bits/stdc++.h>
using namespace std;
#define N 100010

int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    //Path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int, pair<int,int>>> edges;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());

    for(int i=1;i<=v;i++){
        make(i);
    }
    int totalCost = 0;
    for(auto edge:edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v)) continue;
        Union(u, v);
        totalCost += wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<totalCost<<endl;
    return 0;
}


/* Sample input: (answer should be 17)
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/
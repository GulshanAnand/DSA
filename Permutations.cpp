#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> a, int idx, vector<vector<int>> &ans){
    if(idx >= a.size()){
        ans.push_back(a);
    }

    for(int j=idx;j<a.size();j++){
        swap(a[idx], a[j]);
        permute(a, idx+1, ans);
        swap(a[idx], a[j]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> ans;
    permute(a, 0, ans);
    cout<<"Permutations are:\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/*
Input:
3
1 2 3

Output:
Permutations are:
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2
*/
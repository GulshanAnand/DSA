#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &v, int x, int j, int n){
    for(int i=0;i<=x;i++){
        if(v[i][j] == 1) return false;
    }
    for(int i=0;i<=j;i++){
        if(v[x][i] == 1) return false;
    }
    int a = x, b = j;
    while(x >= 0 && j >= 0){
        if(v[x][j] == 1) return false;
        x--;
        j--;
    }
    while(a >= 0 && b < n){
        if(v[a][b] == 1) return false;
        a--;
        b++;
    }
    return true;
}

bool nQueen(vector<vector<int>> &v, int x, int n){
    if(x >= n) return true;
    for(int j=0;j<n;j++){
        if(isSafe(v,x,j,n)){
            v[x][j] = 1;
            if(nQueen(v,x+1,n)) return true;
            v[x][j] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            tmp.push_back(0);
        }
        v[i] = tmp;
    }

    if(nQueen(v,0,n)){
        cout<<"The Queens can be placed as follows:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
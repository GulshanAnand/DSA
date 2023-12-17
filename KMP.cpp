#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int

vector<int> prefix_function(string s){
    int n = s.length();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main(){
    FIO;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int

vector<int> manacher(string &s){
    int n = s.size();
    vector<int> p(n, 1);
    int l = 1;
    int r = 1;
    for(int i=1;i<n;i++){
        p[i] = max(0ll, min(r-i, p[l+r-i]));
        while(i+p[i] < n && i-p[i] >= 0 && s[i-p[i]] == s[i+p[i]]){
            p[i]++;
        }
        if(i+p[i] > r){
            l = i-p[i];
            r = i+p[i];
        }
    }
    return p;
}

bool isPalindrome(int l, int r, vector<int> &p){
    int x = 2*l+1;
    int y = 2*r+1;
    int mid = (x+y)/2;
    int len = 2*p[mid]-1;
    return (len >= y-x+1);
}

vector<int> runManacher(string s){
    string t = "";
    for(auto e:s){
        t += '#';
        t += e;
    }
    t += '#';
    return manacher(t);
}

int32_t main(){
    FIO;
    int n;
    cin>>n;
    string s;
    cin>>s;
    auto p = runManacher(s);
    for(auto e:p) cout<<e<<' ';
    cout<<'\n';
    return 0;
}
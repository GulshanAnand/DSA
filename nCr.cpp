#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int


#define N 300010
const int m = 1e9 + 7;

vector<int> f, fi;

long long binpow(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int ncr(int n, int r){
    if(n < r){
        return 0;
    }
    if(n == 0) return 1;
    if(r == 0) return 1;
    int res = (((f[n]*fi[r])%m)*fi[n-r])%m;
    return res;
}

void compute_fact(){
    f.resize(N);
    fi.resize(N);

    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<N;i++){
        f[i] = (f[i-1]*i)%m;
    }
    fi[0] = fi[1] = binpow(1, m-2);
    for(int i=2;i<N;i++){
        fi[i] = binpow(f[i], m-2)%m;
    }
}


int32_t main(){
    FIO;
    
    return 0;
}
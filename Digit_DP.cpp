#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007

int dp[23][2][2][402];

int countt(int idx, bool t1, bool t2, int sum, string &n1, string &n2){
    if(sum < 0) return 0;
    if(idx >= n2.size()) return 1;
    if(dp[idx][t1][t2][sum] != -1) return dp[idx][t1][t2][sum];

    int lo = t1?n1[idx]-'0':0;
    int hi = t2?n2[idx]-'0':9;

    int ans = 0;
    for(int i=lo;i<=hi;i++){
        ans = (ans + countt(idx+1, (t1&&(i==lo)), (t2&&(i==hi)), sum-i, n1, n2))%mod;
    }
    return dp[idx][t1][t2][sum] = ans;
}

int count(string num1, string num2, int min_sum, int max_sum) {

    for(int i=0;i<23;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<402;l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    string s = "";
    while(s.length() + num1.length() < num2.length()) s += '0';

    for(auto ch:num1) s += ch;
    num1 = s;

    int ans = countt(0, true, true, max_sum, num1, num2);

    for(int i=0;i<23;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<=max_sum;l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    int ans2 = countt(0, true, true, min_sum-1, num1, num2);
    ans = (ans + mod - ans2)%mod;
    return ans;
}

int32_t main(){
    // https://leetcode.com/problems/count-of-integers/description/
    return 0;
}
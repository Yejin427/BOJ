#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD = 10007;
int dp[1001][1001];

string s;
int f(int l, int r) {
    if(l == r) return 1;
    if(l+1 == r) {
        if(s[l] == s[r]) return 3;
        else return 2;
    }
    if(dp[l][r] != -1) return dp[l][r];
    if(s[l] != s[r]) {
        dp[l][r] = f(l, r-1) + f(l+1, r) - f(l+1, r-1);
        if(dp[l][r] < 0) return dp[l][r] = dp[l][r] % MOD + MOD;
        else return dp[l][r] %= MOD;
    }
    else {
        return dp[l][r] = (f(l, r-1) + f(l+1, r) + 1) % MOD;
    }
    return dp[l][r];
}
int main() {
    cin >> s;
    memset(dp, -1, sizeof(dp));

    cout << f(0, s.length()-1);
}
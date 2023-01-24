#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
long long dp[200001][5];
int main(){
    int n; cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;

    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][3] + dp[i-1][4]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][4]) % MOD;
        dp[i][3] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][4] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
    }
    cout << ((dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]) % MOD);
}
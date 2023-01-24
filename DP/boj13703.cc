#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;
ll dp[200][200];
ll solve(ll k, ll n){
    if(k == 0) return 0;
    if(n == 0) return 1;
    if(dp[k][n] != -1) return dp[k][n];
    return dp[n][k] = solve(k-1 ,n-1) + solve(k+1, n-1);
}
int main(){
    ll k,n; cin >> k >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(k, n);
}
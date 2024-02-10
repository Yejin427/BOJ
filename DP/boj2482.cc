#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1000000003;
ll dp[1001][1001];
//직선일때 n개중 인접하지 않게 k선택
ll f(int n, int k) {
    if(n < 1) return 0;
    if((n+1) / k < 2) return 0;
    if(k == 1) return n;
    if(dp[n][k]) return dp[n][k];
    
    for(int i=1;i<=n;i++) {
        dp[n][k] += f(n-i-1, k-1);
        dp[n][k] %= MOD;
    }
    return dp[n][k];
}
int main() {
    int n,k; cin >> n >> k;

    ll ans = 0;
    if(k == 1) cout << n;
    else {
        for(int i=1;i<=n;i++) {
            if(i == 1 || i == 2) {
                ans += f(n-3, k-1);
            } else {
                ans += f(n-i-1, k-1);
            }
            ans %= MOD;
        }
        cout << ans;
    }
}
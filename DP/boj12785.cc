#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000007;
ll dp[500][500];
ll comb(int n, int r) {
    if(n == r || r == 0) return 1;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = (comb(n-1, r) + comb(n-1, r-1)) % MOD;
}
int main() {
    int w,h, x,y;
    cin >> w >> h >> x >> y;
    cout << comb(x+y-2, y-1) * comb(w+h-x-y, w-x) % MOD;
}
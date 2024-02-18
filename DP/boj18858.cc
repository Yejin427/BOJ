#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
using ll = long long;
const int MOD = 998244353;
ll dp[1001][101][2];    //n: 길이, m: 전의 수, 0: 전이 큼, 1: 작거나 같음
int n,m;
ll func(int x, int y, int z) {
    if(x == 1) return 1;
    if(x == 2) {
        if(z) return y;
        else return m-y;
    }
    if(dp[x][y][z] != -1) return dp[x][y][z];
    dp[x][y][z] = 0;

    if(z) {     //전이 작거나 같음
        for(int i=1;i<=y;i++) {
            dp[x][y][z] += func(x-1, i, 1);
            dp[x][y][z] += func(x-1, i, 0);
            dp[x][y][z] %= MOD;
        }
    } else {    //전이 큼
        for(int i=y+1;i<=m;i++){  //전전은 크거나 같아야함
            dp[x][y][z] += func(x-1, i, 0);     //전전이 큼

            if(x > 3) {
                dp[x][y][z] += (func(x-2, i, 0) + func(x-2, i, 1)) % MOD;   //전전이 같음
            } else {
                dp[x][y][z] += func(x-2, i, 0) % MOD;
            }
            dp[x][y][z] %= MOD;
        }
    }
    return dp[x][y][z];
}

int main() {
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));
    if(n == 1) return m;
    else {
        ll ans = 0;
        for(int i=1;i<=m;i++) {
            ans += (func(n, i, 0) + func(n, i, 1)) % MOD;
            ans %= MOD;
        }
        cout << ans;
    }
}
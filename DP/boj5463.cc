#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int r[51][51];
int sum[51][51];
int dp[51][51][51][51];
int func(int sx, int sy, int ex, int ey) {
    if(sx == ex && sy == ey) return 0;
    if(dp[sx][sy][ex][ey] != -1) return dp[sx][sy][ex][ey];
    dp[sx][sy][ex][ey] = 1e9;
    int val = sum[ex][ey] - sum[sx-1][ey] - sum[ex][sy-1] + sum[sx-1][sy-1];
    for(int i=sx;i<ex;i++) {
        dp[sx][sy][ex][ey] = min(val + func(sx,sy,i,ey) + func(i+1, sy, ex, ey), dp[sx][sy][ex][ey]);
    }
    for(int i=sy;i<ey;i++) {
        dp[sx][sy][ex][ey] = min(val + func(sx,sy,ex,i) + func(sx,i+1,ex,ey), dp[sx][sy][ex][ey]);
    }
    return dp[sx][sy][ex][ey];
}
int main() {
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> r[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + r[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << func(1, 1, n, m);
}
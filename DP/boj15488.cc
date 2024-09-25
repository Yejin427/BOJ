#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
double dp[51][51][51];
int n;
double solve(int x, int y, int k) {
    if(x < 1 || y < 1 || x > n || y > n) return 0;
    if(k == 0) return 1;
    if(dp[x][y][k] != -1) return dp[x][y][k];

    return dp[x][y][k] = (double)1/8 * (solve(x-2, y-1, k-1) + solve(x-2, y+1, k-1) + solve(x-1, y-2, k-1) + solve(x-1, y+2, k-1)
        + solve(x+1, y-2, k-1) + solve(x+1, y+2, k-1) + solve(x+2, y-1, k-1) + solve(x+2, y+1, k-1));
}
int main(){
    int x,y,k;
    cin >> n >> x >> y >> k;
    for(int i=1;i<=50;i++) {
        for(int j=1;j<=50;j++) {
            for(int k=1;k<=50;k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << solve(x,y,k);
}
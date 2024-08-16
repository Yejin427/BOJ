#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int dp[40][501];
int level[5];
string mvp;
int getIdx(char level) {
    if(level == 'B') return 1;
    if(level == 'S') return 2;
    if(level == 'G') return 3;
    if(level == 'P') return 4;
    if(level == 'D') return 5;
    return 0;
}
int main(){
    int n; cin >> n;
    cin >> level[1] >> level[2] >> level[3] >> level[4];
    cin >> mvp;
    memset(dp, -1, sizeof(dp));

    for(int i=1;i<=n;i++) {
        int lvl = getIdx(mvp[i-1]);
        if(i == 1) {
            if(lvl == 5) dp[i][level[4]] = level[4];
            else{
                for(int j=level[lvl-1];j<level[lvl];j++) {
                    dp[i][j] = j;
                }
            }
            continue;
        }
        if(lvl < 5) {
            for(int sum=level[lvl-1];sum<level[lvl];sum++) {
                for(int j=0;j<=sum;j++) {
                    if(dp[i-1][sum-j] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i-1][sum-j] + j);
                }
            }
        } 
        else{
            for(int j=0;j<=level[4];j++) {
                for(int p=level[4]-j;p<=level[4];p++) {
                    if(dp[i-1][p] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i-1][p] + j);
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=level[4];i++) {
        ans = max(dp[n][i], ans);
    }
    cout << ans;
}
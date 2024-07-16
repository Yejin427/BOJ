#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[1001][1001];
int dp[1001][1001][3];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> arr[i][j];
        }
    }
    if(arr[1][1] == 0) dp[1][1][0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i ==1&&j==1) continue;
            for(int k=0;k<=2;k++) {
                if(k == arr[i][j]) {
                    if(k == 0) {
                        if(dp[i][j-1][2] != 0) dp[i][j][0] = dp[i][j-1][2] + 1;
                        if(dp[i-1][j][2] != 0) dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][2] + 1);
                        dp[i][j][0] = max(dp[i][j][0], 1);
                    }
                    else {
                        //0이 아닌데 1일 수 없음
                        if(dp[i][j-1][k-1] != 0) dp[i][j][k] = dp[i][j-1][k-1] + 1;
                        if(dp[i-1][j][k-1] != 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + 1);
                    }
                }
                else dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
            }
        }
    }
    cout << max({dp[n][n][0], dp[n][n][1], dp[n][n][2]});
}
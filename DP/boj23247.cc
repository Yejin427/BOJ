#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[301][301];
int dp[301][301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=i-1;k>=0;k--){
                if(dp[i][j] - dp[i][j-1] - dp[k][j] + dp[k][j-1] > 10) continue;
                for(int l=j-1;l>=0;l--){
                    int val = dp[i][j] - dp[i][l] - dp[k][j] + dp[k][l];
                    if(val >= 10) {
                        if(val == 10) {
                            ans++;
                        }
                        continue;
                    }
                }
            }
        }
    }

    cout << ans;
}
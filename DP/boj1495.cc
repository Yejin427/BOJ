#include<iostream>
#include<algorithm>
using namespace std;

int arr[51];
int dp[51][1001];
int main() {
    int n,s,m;
    cin >> n >> s >> m;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    
    dp[0][s] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(j-arr[i] >= 0) dp[i][j] = dp[i-1][j-arr[i]];
            if(j+arr[i] <= m && dp[i][j] == 0) dp[i][j] = dp[i-1][j+arr[i]];
        }
    }
    int ans = -1;
    for(int i=0;i<=m;i++) {
        if(dp[n][i]) ans = i;
    }
    cout << ans;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[210][2];
int dp[210][210][3];
int n,k;
int main(){
    cin >> n >> k;
    int sum = 0;
    for(int i=1;i<=n+1;i++) {
        cin >> arr[i][0] >> arr[i][1];
        sum += arr[i][0] + arr[i][1];
    }
    for(int i=1;i<=k;i++) {
        for(int j=0;j<3;j++) {
            dp[i][0][j] = 1e9;
        }
    }
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][2]) + arr[j][0];
            dp[i][j][1] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + arr[j][1];
            dp[i][j][2] = min({dp[i][j-1][0], dp[i][j-1][1], dp[i][j-1][2]});
        }
    }
    cout << sum - min({dp[k][n][0], dp[k][n][1], dp[k][n][2]});
}
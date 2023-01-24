#include<iostream>
using namespace std;
int arr[301];
int dp[301][2]; //전에꺼 밟음 : 1, 안밟음 : 0
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    dp[1][1] = arr[1];
    dp[1][0] = arr[1];
    dp[2][0] = arr[2];
    dp[2][1] = arr[2] + arr[1];

    for(int i = 3; i <= n; i++){
        dp[i][0] = max(dp[i-2][0], dp[i-2][1])+arr[i];
        dp[i][1] = max(dp[i-1][0], max(dp[i-2][0], dp[i-2][1]))+arr[i];
    }
    // for(int i=1;i<=n;i++){
    //     cout << dp[i][0] << " "<<dp[i][1]<<'\n';
    // }
    cout << max(dp[n][1], dp[n][0]);
}
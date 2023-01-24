#include<iostream>
#include<algorithm>
using namespace std;
int dp[5001];
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) dp[i] = -1;
    dp[3] = 1;
    dp[5] = 1;
    for(int i=6;i<=n;i++){
        if(dp[i-3] != -1 && dp[i-5] != -1) dp[i] = min(dp[i-3], dp[i-5])+1;
        else if(dp[i-5] != -1 && dp[i-3] == -1) dp[i] = dp[i-5]+1;
        else if(dp[i-3] != -1 && dp[i-5] == -1) dp[i] = dp[i-3]+1;
    }
    cout << dp[n];
}
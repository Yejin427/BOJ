#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1] = arr[1];
    for(int i=2;i<=n;i++) {
        dp[i] = 1e9;
        for(int j=0;j<i;j++) {
            dp[i] = min(dp[i], dp[j] + arr[i-j]);
        }
    }
    cout << dp[n];
}
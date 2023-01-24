#include<iostream>
#include<algorithm>
using namespace std;
int arr[21][2];
int dp[21][2];
using namespace std;
const int INF = 1e9;
int main(){
    int n; cin >> n;
    for(int i=1;i<=n-1;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    int k; cin >> k;
    dp[0][0] = INF;
    dp[1][0] = 0; dp[1][1] = INF; 
    dp[2][0] = arr[1][0];   dp[2][1] = INF;
    for(int i=3;i<=n;i++){
        dp[i][0] = min(dp[i-1][0] + arr[i-1][0], dp[i-2][0] + arr[i-2][1]);
        dp[i][1] = min({dp[i-1][1] + arr[i-1][0], dp[i-2][1] + arr[i-2][1], dp[i-3][0] + k});
    }
    cout << min(dp[n][0], dp[n][1]);
}
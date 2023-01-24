#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001][3];
int dp[1001][3][3]; //집 번호, 처음 색깔, 현재 색깔
const int INF = 10000000;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i == j) dp[1][i][i] = arr[1][i];
            else dp[1][i][j] = INF;
        }
    }
    for(int start = 0; start < 3; start++){
        for(int i = 2; i <= n; i++){
            dp[i][start][0] = min(dp[i-1][start][1], dp[i-1][start][2]) + arr[i][0];
            dp[i][start][1] = min(dp[i-1][start][0], dp[i-1][start][2]) + arr[i][1];
            dp[i][start][2] = min(dp[i-1][start][0], dp[i-1][start][1]) + arr[i][2];
        }
    }
    cout << min({dp[n][0][1], dp[n][0][2], dp[n][1][0], dp[n][1][2], dp[n][2][1], dp[n][2][0]});
}
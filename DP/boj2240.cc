#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[1001];
int dp[1001][31][3];   //time, move, pos
int main(){
    int t,w; cin >> t >> w;
    for(int i=1;i<=t;i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    dp[0][w][1] = 0;
    for(int i=0;i<t;i++) {
        for(int j=0;j<=w;j++) {
            if(dp[i][j][1] >= 0) {
                if(arr[i+1] == 1) { //제자리에서 받기
                    dp[i+1][j][1] = dp[i][j][1] + 1;
                } else {
                    if(j != 0) {
                        dp[i+1][j-1][2] = max(dp[i][j][1] + 1, dp[i+1][j-1][2]);  //움직여서 받기
                    }
                    dp[i+1][j][1] = dp[i][j][1];    //안움직이고 안받기
                }
            }
            if(dp[i][j][2] >= 0) {
                if(arr[i+1] == 2) {
                    dp[i+1][j][2] = dp[i][j][2] + 1;
                } else {
                    if(j != 0) {
                        dp[i+1][j-1][1] = max(dp[i][j][2] + 1, dp[i+1][j-1][1]);
                    }
                    dp[i+1][j][2] = dp[i][j][2];
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=t;i++) {
        ans = max({dp[i][0][1], dp[i][0][2], ans});
    }
    for(int i=0;i<=w;i++) {
        ans = max({dp[t][i][1], dp[t][i][2], ans});
    }
    cout << ans;
}
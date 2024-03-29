#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
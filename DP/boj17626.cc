#include<bits/stdc++.h>
using namespace std;
int dp[50001];
int main(){
    int n; cin >> n;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        if((int)sqrt(n) == sqrt(n)){
            dp[i] = 1;
        }
        else{
            int value = 5;
            for(int j=1;j<=sqrt(i);j++){
                value = min(value, dp[i-j*j]+1);
            }
            dp[i] = value;
        }
    }
    cout << dp[n];
}
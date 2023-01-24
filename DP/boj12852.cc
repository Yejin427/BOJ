#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int p[1000001];
int main(){
    int n; cin >> n;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+1;
        p[i] = i-1;
        if(i % 3 == 0 && dp[i/3]+1 < dp[i]){
            dp[i] = dp[i/3]+1;
            p[i] = i/3;
        }
        if(i % 2 == 0 && dp[i/2]+1 < dp[i]){
            dp[i] = dp[i/2]+1;
            p[i] = i/2;
        }
    }
    cout << dp[n] << '\n';
    int x = n;
    while(x != 0){
        cout << x << " ";
        x = p[x];
    }
}
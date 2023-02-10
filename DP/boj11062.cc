#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[1001];
int dp[1001][1001][2];
int solve(int start, int end, bool player){
    if(start == end){
        if(!player){
            return dp[start][end][player] = arr[start];
        }
        else{
            return dp[start][end][player] = 0;
        }
    }
    if(dp[start][end][player] > 0) return dp[start][end][player];
    if(!player){
        return dp[start][end][player] = max(solve(start, end-1, !player) + arr[end], solve(start + 1, end, !player) + arr[start]);
    }
    else{
        return dp[start][end][player] = min(solve(start, end-1, !player), solve(start + 1, end, !player));
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i];
        cout << solve(1, n, 0)<<'\n';
        memset(dp, 0, sizeof(dp));
        
    }
}
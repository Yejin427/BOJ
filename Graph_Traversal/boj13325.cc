#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

ll arr[(1 << 21)+1];
ll dp[(1 << 21)+1], nodes;
void dfs(int root){
    if(root * 2 <= nodes){
        dfs(root * 2);
        dfs(root * 2 + 1);
        if(dp[root * 2] + arr[root * 2 - 1] > dp[root * 2 + 1] + arr[root * 2]){
            arr[root * 2] += (dp[root * 2] + arr[root * 2 - 1] - dp[root * 2 + 1] - arr[root * 2]);
        }
        else if(dp[root * 2] + arr[root * 2 - 1] < dp[root * 2 + 1] + arr[root * 2]){
            arr[root * 2 - 1] += (dp[root * 2 + 1] + arr[root * 2] - dp[root * 2] - arr[root * 2 - 1]);
        }
        dp[root] = dp[root * 2] + arr[root * 2 - 1];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k; cin >> k;
    nodes = pow(2, k+1) - 1;
    for(int i=1;i<nodes;i++){
        cin >> arr[i];
    }
    dfs(1);
    ll ans = 0;
    for(int i=1;i<nodes;i++){
        ans += arr[i];
    }
    cout << ans;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;

int arr[200001];
vector<int> v[200001];
int dp[200001][2];
int solve(int root, int self){
    if(v[root].size() == 0) return 0;
    if(dp[root][self] != -1) return dp[root][self];
    dp[root][self] = 0;
    for(int child: v[root]){
        dp[root][self] += max(solve(child, 0), solve(child, 1));
    }
    if(self){
        int val = 0;
        for(int child: v[root]){
            if(solve(child, 0) >= solve(child, 1)){
                val = max(arr[root] * arr[child], val);
            }
        }
        dp[root][self] += val;
        
        int value = 0;
        for(int child: v[root]){
            value = max(dp[root][self] - val - solve(child, 1) + solve(child, 0) + arr[root] * arr[child], value);
        }
        dp[root][self] = max(dp[root][self], value);
    }
    return dp[root][self];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=2;i<=n;i++){
        int parent; cin >> parent;
        v[parent].push_back(i);
    }
    for(int i=1;i<=n;i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    //cout << solve(1, 0)<< " "<<solve(1, 1);
    cout << max(solve(1, 0), solve(1, 1));
}
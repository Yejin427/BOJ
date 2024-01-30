#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
vector<int> v[100001];
vector<long long> edge;
int dp[100001];
long long arr[100001];
const long long MOD = 1e9+7;
int dfs(int root){
    dp[root] = 1;
    for(int ch: v[root]){
        if(dp[ch] == -1){
            dp[root] += dfs(ch);
        }
    }
    return dp[root];
}
int main(){
    int n; cin >> n;
    for(int i=1;i<n;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n-1;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n-1);
    memset(dp, -1, sizeof(dp));
    dfs(1);
    for(int i=2;i<=n;i++){
        edge.push_back((long long)dp[i] * (n-dp[i]));
    }
    sort(edge.begin(), edge.end(), greater<long long>());
    long long ans = 0;
    for(int i=0;i<n-1;i++){
        ans += edge[i] * arr[i];
        ans %= MOD;
    }
    cout << ans;
}
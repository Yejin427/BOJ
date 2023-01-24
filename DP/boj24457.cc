#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using pi = pair<int,int>;
int e[5010], c[5010];
int dp[5010][5010];
vector<pi> v;
bool cmp(pi a, pi b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i].first;
    for(int i=0;i<n;i++) cin >> v[i].second;
    
    sort(v.begin(), v.end(), cmp);

    for(int i = n - 1; i >= 0; i--){  //이 위치부터
        for(int j = 1; j <= n-i; j++){    //몇개
            dp[i][j] = max(dp[i+1][j], dp[i][j]);
            int energy = dp[i+1][j-1] - (j-1) * v[i].second + v[i].first;
            dp[i][j] = max(dp[i][j], energy);
        }
    }
    int ans = 0;
    for(int i=0;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    
}
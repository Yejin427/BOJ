#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
vector<pair<int,int>> v;
int func(int sx, int sy, int ex, int ey) {
    if(ex < sx || ey < sy) return 0;
    if(ex == sx && ey == sy) return arr[ex][ey];
    if(dp[ex][ey] != -1) return dp[ex][ey];
    return dp[ex][ey] = max(func(sx, sy, ex, ey-1), func(sx, sy, ex-1, ey)) + arr[ex][ey];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> arr[i][j];
        }
    }
    int p; cin >> p;
    v.push_back({1,1});
    while(p--) {
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    v.push_back({n,n});
    sort(v.begin(), v.end());

    memset(dp, -1, sizeof(dp));
    bool cango = true;
    int ans = 0;
    for(int i=0;i<v.size()-1;i++) {
        pair<int,int> s = v[i];
        pair<int,int> e = v[i+1];
        
        if(s.second > e.second) {
            cango = false;
            break;
        }
        // cout << func(s.first, s.second, e.first, e.second) - arr[s.first][s.second] << ' ';
        ans += func(s.first, s.second, e.first, e.second) - arr[s.first][s.second];
    }
    ans += arr[1][1];
    if(!cango) cout << -1;
    else cout << ans;
}
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int dp[6700];
vector<pair<int, pair<int,int>>> v;
double dist(pair<int,int> a, pair<int,int> b) {
    return (double)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main(){
    int n,s; cin >> n >> s;
    v.push_back({0,{0,0}});
    for(int i=1;i<=n;i++) {
        int x,y,t;
        cin >> x >> y >> t;
        v.push_back({t,{x,y}});
    }
    sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<i;j++) {
            if(dp[j] != -1 && dist(v[i].second, v[j].second) <= s * (v[i].first - v[j].first)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
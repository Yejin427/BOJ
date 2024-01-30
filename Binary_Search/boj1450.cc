#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int arr[31];
void dfs(int s, int e, vector<ll> &v, ll sum){
    if(s > e){
        v.push_back(sum);
        return;
    } else {
        dfs(s + 1, e, v, sum);
        dfs(s + 1, e, v, sum + arr[s]);
    }
}
int main(){
    int n,c; cin >> n >> c;
    for(int i=1;i<=n;i++) cin >> arr[i];
    vector<ll> v1;
    vector<ll> v2;
    dfs(1, n / 2, v1, 0);
    dfs(n / 2 + 1, n, v2, 0);
    int ans = 0;
    sort(v2.begin(), v2.end());
    for(ll x: v1){
        ans += upper_bound(v2.begin(), v2.end(), (ll)(c - x)) - v2.begin();
    }
    cout << ans;
}
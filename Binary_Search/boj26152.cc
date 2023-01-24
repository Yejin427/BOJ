#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> c;
int dp[250001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        b.push_back(x);
    }
    for(int i=0;i<n;i++){
        c.push_back(a[i]-b[i]);
    }
    dp[0] = c[0];
    for(int i=1;i<n;i++){
        dp[i] = min(dp[i-1], c[i]);
    }
    sort(dp, dp+n);
    int q; cin >> q;
    while(q--){
        int bird; cin >> bird;
        int idx = lower_bound(dp, dp+n, bird) - dp;
        cout << n - idx<<'\n';
    }
}
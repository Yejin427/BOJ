#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
vector<p> v;
ll mina[500001];     
ll bsum[500001];
ll ans[500001];
priority_queue<ll> pq; 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    v.resize(n+1);
    for(int i=1;i<=n;i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [&](p a, p b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    mina[n] = v[n].first;
    for(int i=n-1;i>=1;i--) {
        mina[i] = min(mina[i+1], v[i].first);
    }
    for(int i=1;i<=n;i++) bsum[i] = bsum[i-1] + v[i].second;

    for(int i=1;i<=n;i++) {
        ans[i] = bsum[i-1] + mina[i];
    }
    
    for(int i=1;i<=n;i++) {
        pq.push(v[i].second - v[i].first);
        ans[i] = min(ans[i], bsum[i] - pq.top());
    }
    for(int i=1;i<=n;i++) cout << ans[i] << '\n';
}
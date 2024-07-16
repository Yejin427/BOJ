#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
typedef pair<int,ll> pi;
vector<pi> v[100001];
int n,m,a,b;
ll c;
bool djk(ll maxval) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int visited[100001];
    memset(visited, -1, sizeof(visited));
    pq.push({a, 0});
    while(!pq.empty()) {
        int node = pq.top().first;
        ll dis = pq.top().second;
        pq.pop();
        if(visited[node] != -1) continue;
        visited[node] = dis;
        if(node == b) return true;
        for(pi nxt: v[node]) {
            if(nxt.second > maxval || visited[nxt.first] != -1 || dis + nxt.second > c) continue;
            pq.push({nxt.first, dis + nxt.second});
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> a >> b >> c;
    for(int i=1;i<=m;i++) {
        int s,e; ll w;
        cin >> s >> e >> w;
        v[s].push_back({e, w});
        v[e].push_back({s, w});
    }
    ll l = 1, r = c;
    ll ans = -1;
    while(l <= r) {
        ll mid = (l + r) / 2;
        // cout << "mid: "<<mid<<'\n';
        if(djk(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}
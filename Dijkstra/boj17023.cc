#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll,pair<int,int>>;
ll dist[10001];
ll dp[10001];
int p[10001]; int cow[10001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pair<int,ll>> v[10001];
vector<int> tree[10001];
void treedp(int root){
    for(auto& ch: tree[root]){
        treedp(ch);
        dp[root] += dp[ch];
    }
    dp[root] += cow[root];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,t; cin >> n >> m >> t;
    for(int i=1;i<=n;i++) cin >> cow[i];
    for(int i=1;i<=m;i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    memset(dist, -1, sizeof(dist));
    
    pq.push({0, {1, 1}});
    while(!pq.empty()){
        int pr = pq.top().second.first;
        int cur = pq.top().second.second;
        ll d = pq.top().first;
        pq.pop();
        if(dist[cur] != -1) {
            if(dist[cur] == d) p[cur] = min(pr, p[cur]);
            continue;
        }  //똑같은길 여러개
        else{
            p[cur] = pr;
            dist[cur] = d;
        }
        for(auto& nxt: v[cur]){
            if(dist[nxt.first] != -1) continue;
            pq.push({d + nxt.second, {cur, nxt.first}});
        }
    }
    ll ans = 0;
    for(int i=2;i<=n;i++){
        tree[p[i]].push_back(i);
    }
    treedp(1);
    for(int i=2;i<=n;i++){
        //cout << "dp " << dp[i] << " dist "<<dist[i]<<'\n';
        ans = max(ans, dp[i] * (dist[i] - t));
    }
    cout << ans;
}
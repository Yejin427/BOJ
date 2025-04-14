#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define MOD 1000000000
using namespace std;
using ll = long long;
vector<pair<ll, pair<int,int>>> edges;
int parent[100001];
vector<int> edgeSet;
ll sum[100001];
ll setCount[100001];
int find(int node) {
    return node == parent[node] ? node : parent[node] = find(parent[node]);
}
void merge(int x, int y){
    int rx = find(x);
    int ry = find(y);
    setCount[rx] += setCount[ry];
    parent[ry] = rx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        parent[i] = i;
        setCount[i] = 1;
    }
    for(int i=1;i<=m;i++) {
        int x,y; ll w;
        cin >> x >> y >> w;
        edges.push_back({w,{x,y}});
    }
    sort(edges.begin(), edges.end());
    sum[0] = edges[0].first;
    for(int i=1;i<edges.size();i++) {
        sum[i] = sum[i-1] + edges[i].first;
    }
    ll ans = 0;
    for(int i=edges.size()-1;i>=0;i--) {
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        // cout << "find(x): "<<setCount[find(x)]<< " find(y): "<<setCount[find(y)]<<" sum: "<<sum[i]<<'\n';
        if(find(x) == find(y)) continue;
        ans += (((setCount[find(x)] * setCount[find(y)]) % MOD) * (sum[i] % MOD)) % MOD;

        merge(min(x, y), max(x, y));
        ans %= MOD;
    }
    cout << ans;
}
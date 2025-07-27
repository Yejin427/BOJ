#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int,int>> p; //거리, 다음 인덱스, 압축 개수  
vector<pair<int,ll>> v[10001];
priority_queue<p, vector<p>, greater<p>> pq;
ll dist[10001][21];
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++) {
        int s, e; ll d;
        cin >> s >> e >> d;
        v[s].push_back({e, d});
        v[e].push_back({s, d});
    }
    memset(dist, -1, sizeof(dist));
    pq.push({0, {1, 0}});

    while(!pq.empty()) {
        auto front = pq.top();
        ll d = front.first;
        int node = front.second.first;
        int compress = front.second.second;
        // cout << "d: "<<d<<" node: "<<node<<" compress: "<<compress<<'\n';
        pq.pop();

        if(dist[node][compress] != -1) continue;
        dist[node][compress] = d;
        for(auto nxt: v[node]) {
            //현재 경로 압축 X
            if(dist[nxt.first][compress] == -1) {
                pq.push({d + nxt.second, {nxt.first, compress}});
            }
            if(compress < k && dist[nxt.first][compress] == -1) {
                pq.push({d, {nxt.first, compress + 1}});
            }
        }
    }
    ll ans = 1e11;
    for(int c = 0; c <= k; c++) {
        if(dist[n][c] != -1)
            ans = min(dist[n][c], ans);
    }
    cout << ans;
}
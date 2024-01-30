#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> p;
vector<p> graph[10001];
int starbucks[10001];
int mcdonald[10001];
priority_queue<int,vector<int>,greater<int>> ans;
int map[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V,E; cin >> V >> E;
    while(E--) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int m,x,s,y;
    cin >> m >> x;
    while(m--) {
        int mc; cin >> mc;
        map[mc] = 1;
    }
    cin >> s >> y;
    while(s--) {
        int sb; cin >> sb;
        map[sb] == 1 ? map[sb] = 3 : map[sb] = 2;
    }

    priority_queue<p, vector<p>, greater<p>> pq1;
    priority_queue<p, vector<p>, greater<p>> pq2;
    memset(mcdonald, -1, sizeof(mcdonald));
    memset(starbucks, -1, sizeof(starbucks));
    for(int i=1;i<=V;i++) {
        if(map[i] == 1 || map[i] == 3) {  //맥 -> 집
            pq1.push({0, i});
        }
        if(map[i] == 2 || map[i] == 3) {  //스 -> 집
            pq2.push({0, i});
        }
    }
    while(!pq1.empty()) {
        int cost = pq1.top().first;
        int pos = pq1.top().second;

        pq1.pop();
        if(mcdonald[pos] != -1 && mcdonald[pos] < cost) continue;
        mcdonald[pos] = cost;
        for(p nxt: graph[pos]) {
            if(mcdonald[nxt.first] != -1 && mcdonald[nxt.first] < cost + nxt.second) continue;
            pq1.push({cost + nxt.second, nxt.first});
        }
    }
    while(!pq2.empty()) {
        int cost = pq2.top().first;
        int pos = pq2.top().second;

        pq2.pop();
        if(starbucks[pos] != -1 && starbucks[pos] < cost) continue;
        starbucks[pos] = cost;
        for(p nxt: graph[pos]) {
            if(starbucks[nxt.first] != -1 && starbucks[nxt.first] < cost + nxt.second) continue;
            pq2.push({cost + nxt.second, nxt.first});
        }
    }
    for(int i=1;i<=V;i++) {
        if(map[i]) continue;

        // cout << "i: "<<i<<" mc: "<<mcdonald[i]<<" sb: "<<starbucks[i]<<'\n';
        if(mcdonald[i] <= x && starbucks[i] <= y) ans.push(mcdonald[i] + starbucks[i]);
    }
    // cout << "ans.size(): "<<ans.size()<<'\n';
    if(ans.size()) cout << ans.top();
    else cout << -1;
}
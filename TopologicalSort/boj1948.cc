#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> p;
vector<p> graph[10001];
vector<p> revgraph[10001];
int arr[10001];
int dist[10001];
bool visited[10001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=m;i++) {
        int u,v,w; 
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        revgraph[v].push_back({u, w});
        arr[v]++;
    }
    int start, end; cin >> start >> end;

    queue<p> q;
    q.push({start, 0});
    while(!q.empty()) {
        int pos = q.front().first;
        int d = q.front().second;
        q.pop();
        
        for(p nxt: graph[pos]) {
            dist[nxt.first] = max(d + nxt.second, dist[nxt.first]);
            if(--arr[nxt.first] == 0) {
                q.push({nxt.first, dist[nxt.first]});
            }
        }
    }

    queue<int> que;
    que.push(end);
    visited[end] = true;
    int ans = 0;
    while(!que.empty()) {
        int pos = que.front();
        que.pop();

        for(p nxt: revgraph[pos]) {
            if(dist[pos] - nxt.second == dist[nxt.first]) {
                ans++;
                if(!visited[nxt.first]) {
                    visited[nxt.first] = true;
                    que.push(nxt.first);
                }
            }
        }
    }

    cout << dist[end] << '\n' << ans;
}
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int,pair<int,int>> pii;
vector<pair<int,int>> map[501];
bool shortest[501][501];    //최단경로에 포함??
int ans[501];   //최단 경로
vector<int> prv[501];  //이전 경로
bool visited[501][501];
void shortchk(int start, int dest) {
    if(dest == start) return;
    for(int nd: prv[dest]) {
        if(visited[nd][dest]) continue;
        visited[nd][dest] = true;
        shortest[nd][dest] = true;
        shortchk(start, nd);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        int n,m,s,d; 
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> s >> d;
        
        memset(ans, -1, sizeof(ans));
        for(int i=1;i<=m;i++) {
            int u,v,p; cin >> u >> v >> p;
            map[u].push_back({v,p});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, {s,s}});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int pr = pq.top().second.first;
            int edge = pq.top().second.second;
            pq.pop();
            if(ans[edge] != -1) {
                if(ans[edge] == dis) {
                    prv[edge].push_back(pr);
                }
                continue;
            } else {
                ans[edge] = dis;
                prv[edge].push_back(pr);
            }
            for(auto nxt: map[edge]) {
                if(ans[nxt.first] != -1) continue;
                pq.push({dis + nxt.second, {edge, nxt.first}});
            }
        }
        //최단 경로 포함 edge 체크
        shortchk(s, d);
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         if(shortest[i][j]) cout << 1 << ' ';
        //         else cout << 0 << ' ';
        //     }
        //     cout << '\n';
        // }
        memset(ans, -1, sizeof(ans));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
        pq2.push({0, s});
        while(!pq2.empty()) {
            int dis = pq2.top().first;
            int edge = pq2.top().second;
            pq2.pop();
            if(ans[edge] != -1) continue;
            ans[edge] = dis;
            for(auto nxt: map[edge]) {
                if(ans[nxt.first] != -1 || shortest[edge][nxt.first]) continue;
                pq2.push({dis + nxt.second, nxt.first});
            }
        }
        // for(int i=0;i<n;i++) {
        //     cout << ans[i] << ' ';
        // }
        // cout << '\n';
        cout << ans[d] << '\n';
        //배열 초기화
        memset(ans, -1, sizeof(ans));
        memset(shortest, false, sizeof(shortest));
        for(int i=0;i<n;i++) {
            map[i].clear();
            prv[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }
}
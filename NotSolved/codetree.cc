#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<pair<int,int>> map[2001];
int ans[2001];
// vector<int> answer;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int rev[30001];
typedef pair<int, pair<int,int>> pii;
struct cmp {
    bool operator()(pii a, pii b) {
        if(a.first == b.first) {
            return a.second.first > b.second.first;
        }
        return a.first < b.first;
    }
};
priority_queue<pii, vector<pii>, cmp> landmark;
int main() {
    // 여기에 코드를 작성해주세요.
    int q; cin >> q;
    while(q--) {
        int cmd; cin >> cmd;
        int n,m;
        if(cmd == 100) {
            cin >> n >> m;
            for(int i=1;i<=m;i++) {
                int v,u,w; cin >> v >> u >> w;
                map[v].push_back({u,w});
                map[u].push_back({v,w});
            }
            memset(ans, -1, sizeof(ans));
            //dijkstra
            pq.push({0, 0});
            while(!pq.empty()) {
                int dis = pq.top().first;
                int edge = pq.top().second;
                pq.pop();
                if(ans[edge] != -1) continue;
                ans[edge] = dis;
                for(auto nxt: map[edge]) {
                    if(ans[nxt.first] != -1) continue;
                    pq.push({dis + nxt.second, nxt.first});
                }
            }
            // for(int i=0;i<n;i++) {
            //     cout << ans[i] << ' ';
            // }
            // cout << '\n';
        }
        else if(cmd == 200) {
            int id, reve, dest; cin >> id >> reve >> dest;
            if(ans[dest] == -1) {
                landmark.push({-1, {id, dest}});
            } else {
                landmark.push({reve-ans[dest], {id, dest}});
            }
            rev[id] = reve;
        }
        else if(cmd == 300) {
            int id; cin >> id;
            rev[id] = 0;
        }
        else if(cmd == 400) {
            while(!landmark.empty() && rev[landmark.top().second.first] == 0) {
                landmark.pop();     //삭제된것
            }
            if(landmark.empty()) cout << -1 << '\n';
            else {
                int cost = landmark.top().first;
                int id = landmark.top().second.first;
                int dest = landmark.top().second.second;
                if(cost >= 0) {
                    // cout << "cost: "<<cost<<'\n';
                    landmark.pop();
                    rev[id] = 0;
                    cout << id << '\n';
                }
                else cout << -1 << '\n';
            }
        }
        else {  //500
            int s; cin >> s;
            memset(ans, -1, sizeof(ans));
            //dijkstra
            pq.push({0, s});
            while(!pq.empty()) {
                int dis = pq.top().first;
                int edge = pq.top().second;
                pq.pop();
                if(ans[edge] != -1) continue;
                ans[edge] = dis;
                for(auto nxt: map[edge]) {
                    if(ans[nxt.first] != -1) continue;
                    pq.push({dis + nxt.second, nxt.first});
                }
            }
            // for(int i=0;i<n;i++) {
            //     cout << ans[i] << ' ';
            // }
            // cout << '\n';
            vector<pii> tmp;
            while(!landmark.empty()) {
                pii top = landmark.top();
                landmark.pop();
                if(ans[top.second.second] == -1) {
                    tmp.push_back({-1, top.second});
                }
                else tmp.push_back({rev[top.second.first] - ans[top.second.second], top.second});
            }
            for(auto p: tmp) {
                landmark.push(p);
            }
        }
    }
    // for(int a: answer) cout << a << '\n';
    return 0;
}
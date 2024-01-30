#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;
typedef pair<ll,pair<int,int>> p;

priority_queue<p, vector<p>, greater<p>> pq;
vector<pair<int,ll>> v[200001];
ll ans[200001];
vector<int> prv[200001];    //최단 경로가 여러개일 수 있음 -> 이전 노드를 여러개
bool ansNode[200001];
void dfs(int node, int start) {
    // cout << "curNode: "<<node<<'\n';
    ansNode[node] = true;
    if(node == start) return;
    for(int nd: prv[node]) {
        dfs(nd, start);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b;
    cin >> n >> m >> a >> b;
    
    for(int i=1;i<=m;i++) {
        int x,y; ll z;
        cin >> x >> y >> z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }

    memset(ans, -1, sizeof(ans));
    pq.push({0, {0, a}});
    while(!pq.empty()) {
        int curNode = pq.top().second.second;
        int prevNode = pq.top().second.first;
        ll dist = pq.top().first;
        pq.pop();

        if(ans[curNode] != -1) {    //같은 길 여러개
            if(ans[curNode] == dist) prv[curNode].push_back(prevNode);
            continue;
        }
        else {
            prv[curNode].push_back(prevNode);
            ans[curNode] = dist;
        }
        for(pair<int,int> nxt: v[curNode]) {
            if(ans[nxt.first] != -1) continue;
            pq.push({dist + nxt.second, {curNode, nxt.first}});
        }
    }
    // for(int i=1;i<=n;i++) cout << i <<": "<<ans[i]<<'\n';

    dfs(b, a);
    int size = 0;
    for(int i=1;i<=n;i++) {
        if(ansNode[i]) size++;
    }
    cout << size << '\n';
    for(int i=1;i<=n;i++) {
        if(ansNode[i]) cout << i << ' ';
    }
}
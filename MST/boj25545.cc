#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
typedef pair<pair<ll,int>,pair<int,int>> p;
priority_queue<p, vector<p>, greater<p>> pq;
priority_queue<p, vector<p>, greater<p>> pq2;
vector<pair<ll, pair<int,int>>> vec;
vector<int> ans;
int parent[200001];
int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[py] = px;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; 
    cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=1;i<=m;i++) {
        int u,v;
        ll c;
        cin >> u >> v >> c;
        pq.push({{c, i}, {u,v}});
        vec.push_back({c, {u, v}});
    }
    while(!pq.empty()) {
        p front = pq.top();
        ll c = front.first.first;
        int idx = front.first.second;
        int u = front.second.first;
        int v = front.second.second;

        pq.pop();
        if(find(u) != find(v)) {
            merge(u, v);
        } else {
            pq2.push(front);
        }
    }
    if(pq2.empty()) {
        cout << "NO";
        return 0;
    }
    for(int i=1;i<=n;i++) parent[i] = i;
    p front = pq2.top();
    merge(front.second.first, front.second.second);
    ans.push_back(front.first.second);
    for(int i=0;i<vec.size();i++) {
        pq.push({{vec[i].first, i+1}, {vec[i].second.first, vec[i].second.second}});
    }
    while(!pq.empty()) {
        p front = pq.top();
        ll c = front.first.first;
        int idx = front.first.second;
        int u = front.second.first;
        int v = front.second.second;

        pq.pop();
        if(find(u) != find(v)) {
            merge(u, v);
            ans.push_back(idx);
        }
    }
    cout << "YES\n";
    for(int a: ans) cout << a << " ";
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int,int>> v[1001];
bool visited[1001];
int dfs(int root, int prev) {
    visited[root] = true;
    int sum = 0, before = 0;
    for(int i=0;i<v[root].size();i++) {
        int child = v[root][i].first;
        if(prev == child) {
            before = v[root][i].second;
            continue;
        }
        if(!visited[child]) {
            visited[child] = true;
            sum += dfs(child, root);
        }
    }
    if(v[root].size() == 1) return before;
    return min(before, sum);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--) {
        int n,m; cin >> n >> m;
        for(int i=1;i<=m;i++) {
            int p1, p2, c;
            cin >> p1 >> p2 >> c;
            v[p1].push_back({p2, c});
            v[p2].push_back({p1, c});
        }
        int ans = 0;
        for(int i=0;i<v[1].size();i++) {
            ans += dfs(v[1][i].first, 1);
        }
        cout << ans << '\n';
        for(int i=1;i<=n;i++) {
            v[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }
}
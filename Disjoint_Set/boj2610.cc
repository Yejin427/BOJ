#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int parent[101];
int edge[101][101];
vector<int> set[101];
vector<int> ans;
int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if(rx > ry) parent[ry] = rx;
    else parent[rx] = ry;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            edge[i][j] = 1e9;
        }
    }
    for(int i=1;i<=m;i++) {
        int x,y; cin >> x >> y;
        edge[x][y] = 1;
        edge[y][x] = 1;
        merge(x,y);
    }
    for(int i=1;i<=n;i++) {
        int root = find(i);
        set[root].push_back(i);
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                if(edge[j][k] > edge[j][i] + edge[i][k]) {
                    edge[j][k] = edge[j][i] + edge[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        int res = 0, resval = 1e9;
        if(set[i].size() == 0) continue;
        for(int j: set[i]) {
            int tmp = 0;
            for(int k: set[i]) {
                if(j == k) continue;
                tmp = max(tmp, edge[j][k]);
            }
            if(resval > tmp) {
                res = j;
                resval = tmp;
            }
        }
        ans.push_back(res);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int num: ans) {
        cout << num << '\n';
    }
}
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int tree[10001][2];
vector<int> lvl[10001];
int dp[10001];
int col[10001];
bool leaf[10001];
int dfs(int root, int lv) {
    lvl[lv].push_back(root);
    if(tree[root][0] != -1) {
        dp[root] += dfs(tree[root][0], lv+1);
    }
    if(tree[root][1] != -1) {
        dp[root] += dfs(tree[root][1], lv+1);
    }
    return dp[root];
}
void solve(int root, int s, int e) {
    col[root] = s;
    if(tree[root][0] != -1) {
        col[root] += dp[tree[root][0]];
        solve(tree[root][0], s, col[root]-1);
    }
    if(tree[root][1] != -1) {
        solve(tree[root][1], col[root]+1, e);
    }
}
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int p,x,y;
        cin >> p >> x >> y;
        tree[p][0] = x;
        tree[p][1] = y;
        leaf[x] = true, leaf[y] = true;
        dp[p] = 1;
    }
    int root = -1;
    for(int i=1;i<=n;i++) {
        if(!leaf[i]) {
            root = i;
            break;
        }
    }
    dfs(root, 1);
    solve(root, 1, n);
    int idx = 1, width = 0;
    for(int i=1;i<=n;i++) {
        if(lvl[i].size() == 0) break;
        int min = n+1, max = 0;
        for(int node: lvl[i]) {
            if(min > col[node]) min = col[node];
            if(max < col[node]) max = col[node];
        }
        if(width < max - min) {
            idx = i;
            width = max - min;
        }
    }
    cout << idx << ' ' << width + 1;
}
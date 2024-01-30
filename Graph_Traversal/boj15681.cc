#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int> tree[100001];
int visited[100001];
int dfs(int root){
    visited[root] = 1;
    for(auto& ch: tree[root]){
        if(visited[ch] == -1){
            visited[root] += dfs(ch);
        }
    }
    return visited[root];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,r,q; cin >> n >> r >> q;
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(visited, -1, sizeof(visited));
    dfs(r);
    while(q--){
        int root; cin >> root;
        cout << visited[root] << '\n';
    }
}
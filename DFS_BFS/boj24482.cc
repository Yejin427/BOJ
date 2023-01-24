#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> v[100001];
int depth[100001];
void dfs(int root){
    for(auto& ch: v[root]){
        if(depth[ch] == -1){
            depth[ch] = depth[root]+1;
            dfs(ch);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,r; cin >> n >> m >> r;
    for(int i=1;i<=m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(), v[i].end(), greater<int>());
    }
    memset(depth, -1, sizeof(depth));
    depth[r] = 0;
    dfs(r);
    for(int i=1;i<=n;i++) cout << depth[i]<<'\n';
}
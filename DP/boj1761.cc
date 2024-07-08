#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<pair<int,long long>> v[40001];
long long treedp[40001];
int prv[40001];
bool visited[40001];
void dfs(int root) {
    visited[root] = true;
    for(pair<int,long long> p: v[root]) {
        if(visited[p.first]) continue;
        treedp[p.first] = treedp[root] + p.second;
        prv[p.first] = root;
        dfs(p.first);
    } 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n-1;i++) {
        int a,b; long long c; 
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1);

    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        memset(visited, false, sizeof(visited));
        
        int tmp = a;
        while(tmp != 0) {   //경로 표시
            visited[tmp] = true;
            tmp = prv[tmp];
        }
        tmp = b;
        while(tmp != 0) {
            if(visited[tmp]) break;
            tmp = prv[tmp];
        }
        cout << treedp[a] + treedp[b] - 2 * treedp[tmp] << '\n';
    }
}
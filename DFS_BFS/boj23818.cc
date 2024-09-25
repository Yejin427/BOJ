#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>> v[100001];
int parent[100001];
bool relation[100001];
bool err[100001];
void dfs(int prev, int cur, int group) {
    for(int i=0;i<v[cur].size();i++) {
        int nxt = v[cur][i].first;
        int st = v[cur][i].second;
        if(nxt == prev) continue;
        if(parent[nxt]) {
            if((st == 0 && relation[cur] != relation[nxt])
                || (st == 1 && relation[cur] == relation[nxt])) {
                err[group] = true;
            }
        }
        else{
            parent[nxt] = group;
            if(st == 0) {
                relation[nxt] = relation[cur];
            }
            else if(st == 1){
                relation[nxt] = !relation[cur];
            }
            dfs(cur, nxt, group);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++) {
        int t,a,b;
        cin >> t >> a >> b;
        v[a].push_back({b,t});
        v[b].push_back({a,t});
    }    
    int group = 1;
    for(int i=1;i<=n;i++) {
        if(!parent[i]) {
            parent[i] = group;
            dfs(0, i, group);
            group++;
        }
    }
    for(int i=1;i<=k;i++) {
        int a,b; cin >> a >> b;
        if(parent[a] != parent[b]) {
            cout << "Unknown\n";
        }
        else if(parent[a] == parent[b]) {
            if(err[parent[a]]) {
                cout << "Error\n";
            }
            else {
                if(relation[a] == relation[b]) {
                    cout << "Friend\n";
                }
                else {
                    cout << "Enemy\n";
                }
            }
        }
    }
}
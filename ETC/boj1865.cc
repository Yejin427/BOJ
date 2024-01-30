#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int shortest[501];
vector<pair<pair<int,int>,int>> v;
int n,m,w;

bool bellman_ford(int start){
    shortest[start] = 0;
    for(int i=1;i<=n;i++){
        for(auto& edge: v){
            int cur = edge.first.first;
            int nxt = edge.first.second;
            int cost = edge.second;

            if(shortest[nxt] > shortest[cur] + cost) {
                shortest[nxt] = shortest[cur] + cost;
                if(i == n) return true;
            }
        }
    }
    return false;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m >> w;
        for(int i=1;i<=m;i++){
            int s,e,t; cin >> s >> e >> t;
            v.push_back({{s,e},t});
            v.push_back({{e,s}, t});
        }
        for(int i=1;i<=w;i++){
            int s,e,t; cin >> s >> e >> t;
            v.push_back({{s,e},-t});
        }
        for(int i=1;i<=n;i++) shortest[i] = 1e9;
        if(bellman_ford(1)){
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
        v.clear();
    }
}
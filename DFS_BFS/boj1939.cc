#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int,int>> tree[100001];
bool visited[100001];
const int INF = 1e9+1;
int s,e;
bool bfs(int cost){
    queue<pair<int,int>> q;
    q.push({s, INF});
    visited[s] = true;
    while(!q.empty()){
        int p = q.front().first;
        int c = q.front().second;
        q.pop();
        if(p == e) return true;
        for(auto nxtpos: tree[p]){
            int nxtcost = min(c, nxtpos.second);
            if(nxtcost >= cost && !visited[nxtpos.first]){
                q.push({nxtpos.first, nxtcost});
                visited[nxtpos.first] = true;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int maxcost = 0;
    for(int i=1;i<=m;i++){
        int a,b,c; cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
        maxcost = max(maxcost, c);
    }
    cin >> s >> e;
    int left = 1, right = maxcost;
    while(left <= right){
        memset(visited, false, sizeof(visited));
        int mid = (left + right) / 2;
        if(bfs(mid)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << right;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int map[11][11], ans, n,m,h;
pair<int,int> home;
vector<pair<int,int>> milk;
bool visited[11];
int dist(int nowr, int nowc, int nxtr, int nxtc) {
    return (abs(nxtr-nowr) + abs(nxtc-nowc));
}
void dfs(int r, int c, int cnt, int health) {
    // cout << "r: "<<r<<" c: "<<c<<" health: "<<health<<'\n';
    if(r == home.first && c == home.second && cnt != 0) {
        ans = max(cnt, ans);
        return;
    }
    for(int i=0;i<milk.size();i++) {
        int dis = dist(r, c, milk[i].first, milk[i].second);
        if(!visited[i] && dis <= health) {
            visited[i] = true;
            dfs(milk[i].first, milk[i].second, cnt+1, health-dis+h);
            visited[i] = false;
        }
    }
    if(dist(r, c, home.first, home.second) >= 1 && dist(r, c, home.first, home.second) <= health) { //집으로 가기
        dfs(home.first, home.second, cnt, health-dist(r, c, home.first, home.second));
    }
}
int main() {
    cin >> n >> m >> h;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) home = {i, j};
            if(map[i][j] == 2) milk.push_back({i, j});
        }
    }
    dfs(home.first, home.second, 0, m);
    
    cout << ans;
}
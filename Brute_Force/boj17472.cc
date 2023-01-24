#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
using pi = pair<int,pair<int,int>>;
int arr[11][11], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool visited[11][11];
vector<pair<int,int>> v[7];
priority_queue<pi, vector<pi>, greater<pi>> pq; 
int n,m, islandno, tmp;
int parent[7];
void dfs(int x, int y){
    visited[x][y] = true;
    arr[x][y] = islandno;
    v[islandno].push_back({x,y});
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m || visited[nx][ny] || !arr[nx][ny]) continue;
        dfs(nx, ny);
    }
}
int bridge(int s, int e){
    int tmp = 200;
    for(auto& p: v[s]){
        for(int i=0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            while(nx <= n && ny <= m && nx >= 1 && ny >= 1){
                if(arr[nx][ny] == e){
                    if(abs(nx - p.first) + abs(ny - p.second) - 1 >= 2){
                        tmp = min(abs(nx - p.first) + abs(ny - p.second) - 1, tmp);
                        break;
                    }
                }
                if(arr[nx][ny] != 0) break;
                nx += dx[i]; ny += dy[i];
            }
        }
    }
    return tmp;
}
int find(int x){
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
void merge(int x, int y){
    int rx = find(x);
    int ry = find(y);
    parent[ry] = rx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            if(!visited[i][j] && arr[i][j] != 0){
                islandno++;
                dfs(i, j);
            } 
        }
    }

    for(int i=1;i<=islandno;i++) {
        parent[i] = i;
        for(int j=i+1;j<=islandno;j++){
            int length = bridge(i, j);
            if(length != 200) pq.push({length, {i, j}});
        }
    }

    int ans = 0;
    while(!pq.empty()){       
        int l = pq.top().first;
        int f = pq.top().second.first;
        int s = pq.top().second.second;
        pq.pop();
        if(find(f) != find(s)) {
            merge(f, s);
            ans += l;
        }
    }
    for(int i=1;i<=islandno;i++){
        for(int j=i+1;j<=islandno;j++){
            if(find(i) != find(j)){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << ans;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
using ll = long long;
int n,m;
int arr[21][21];
int cus[401][4], went[401];
ll dis[21][21];
bool visited[21][21];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
typedef pair<int,int> pi;
int bfs(int sx, int sy) {   //택시 -> 승객
    memset(visited, false, sizeof(visited));
    memset(dis, -1, sizeof(dis));
    queue<pi> q;
    q.push({sx,sy});
    visited[sx][sy] = true;
    dis[sx][sy] = 0;
    ll distance = -1;
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        // cout << "fx: "<<fx<<" fy: "<<fy<<'\n';
        q.pop();
        if(arr[fx][fy] > 0 && distance == -1) {
            distance = dis[fx][fy];
        }
        for(int k=0;k<4;k++) {
            int nx = fx + dx[k], ny = fy + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > n || visited[nx][ny] || arr[nx][ny] == -1) continue;
            visited[nx][ny] = true;
            dis[nx][ny] = dis[fx][fy] + 1;
            q.push({nx, ny}); 
        }
    }
    if(distance == -1) return -1;
    // cout << "distance: "<<distance<<'\n';
    int idx = -1, curx = -1, cury = -1;
    for(int i=1;i<=m;i++) {
        if(!went[i] && dis[cus[i][0]][cus[i][1]] == distance) {
            if(curx == -1) {
                curx = cus[i][0], cury = cus[i][1];
                idx = i;
            } else {
                if(curx > cus[i][0]) {
                    curx = cus[i][0], cury = cus[i][1];
                    idx = i;
                }
                else if(curx == cus[i][0]) {
                    if(cury > cus[i][1]) {
                        cury = cus[i][1];
                        idx = i;
                    }
                }
            }
        }
    }
    return idx;
}
int minDis(int sx, int sy, int ex, int ey) {
    memset(visited, false, sizeof(visited));
    memset(dis, -1, sizeof(dis));
    queue<pi> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    dis[sx][sy] = 0;
    ll distance = -1;
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        if(fx == ex && fy == ey) {
            distance = dis[ex][ey];
            break;
        }
        for(int k=0;k<4;k++) {
            int nx = fx + dx[k], ny = fy + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > n || visited[nx][ny] || arr[nx][ny] == -1) continue;
            visited[nx][ny] = true;
            dis[nx][ny] = dis[fx][fy] + 1;
            q.push({nx, ny}); 
        }
    }
    return distance;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) arr[i][j] = -1;
        }
    }
    int sx, sy; cin >> sx >> sy;
    for(int i=1;i<=m;i++) {
        for(int j=0;j<4;j++) {
            cin >> cus[i][j];
        }
        arr[cus[i][0]][cus[i][1]] = i;
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int curx = sx, cury = sy;
    long long ans = k;    //남은 연료
    bool cango = true;
    for(int s=1;s<=m;s++) {
        // cout << "ans: "<<ans<<'\n';
        //승객에게 감
        int pnum = bfs(curx, cury);
        // cout << "pnum: "<<pnum<<'\n';
        if(pnum == -1) {    //태울 승객 남았지만 갈 수 있는 곳이 없음
            cango = false;
            break;
        }
        int posx = cus[pnum][0], posy = cus[pnum][1];
        int endx = cus[pnum][2], endy = cus[pnum][3];
        if(ans - dis[posx][posy] <= 0) {
            //가는 중 연료 바닥
            cango = false;
            break;
        }
        arr[posx][posy] = 0;
        ans -= dis[posx][posy];
        went[pnum] = 1;
        
        //승객 태우고 목적지
        memset(dis, 0, sizeof(dis));
        ll mindis = minDis(posx, posy, endx, endy);
        // cout << "mindis: "<<mindis<<'\n';
        if(mindis == -1) {
            cango = false;
            break;
        }
        if(ans - dis[endx][endy] < 0) {
            //손님 태우고 가는 중 연료 바닥
            cango = false;
            break;
        }
        ans += dis[endx][endy]; //두배 충전
        curx = endx, cury = endy;
    }
    if(!cango) cout << -1;
    else cout << ans;
}
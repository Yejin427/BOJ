#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
char arr[50][50];
int ans[50][50][33];
int startx, starty, n, m, endx, endy;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    cin >> n >> m;

    char xnum = '0';
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'S'){
                startx = i;
                starty = j;
            }
            else if(arr[i][j] == 'X') {
                arr[i][j] = xnum++;
            }
            else if(arr[i][j] == 'E') {
                endx = i;
                endy = j;
            }
        }
    }
    memset(ans, -1, sizeof(ans));
    ans[startx][starty][0] = 0;

    queue<pair<pair<int,int>,int>> q;
    q.push({{startx, starty}, 0});
    while(!q.empty()) {
        pair<pair<int,int>,int> front = q.front();
        int x = front.first.first;
        int y = front.first.second;
        int status = front.second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > m || ny < 1 || ny > n || arr[nx][ny] == '#' || ans[nx][ny][status] != -1) continue;

            if('0' <= arr[nx][ny] && arr[nx][ny] <= '9'){
                int nxt_status = status | (1 << (arr[nx][ny] - '0'));
                ans[nx][ny][nxt_status] = ans[x][y][status] + 1;
                q.push({{nx, ny}, nxt_status});
            }
            else{
                ans[nx][ny][status] = ans[x][y][status] + 1;
                q.push({{nx, ny}, status});
            }
        }
    }

    cout << ans[endx][endy][(1 << (xnum - '0')) - 1];
}
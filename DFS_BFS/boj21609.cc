#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int arr[21][21];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n,m;
bool visited[21][21];
pair<int,int> bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    int ans = 1, rb = 0;
    while(!q.empty()) {
        int fx = q.front().first, fy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = fx + dx[i], ny = fy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n || visited[nx][ny] || (arr[nx][ny] != 0 && arr[nx][ny] != arr[x][y])) continue;
            if(arr[nx][ny] == 0) rb++;
            visited[nx][ny] = true;
            q.push({nx, ny});
            ans++;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(arr[i][j] == 0) visited[i][j] = false;
        }
    }
    return {ans, rb};
}
void remove(int cx, int cy) {
    queue<pair<int,int>> q;
    q.push({cx,cy});
    visited[cx][cy] = true;
    int color = arr[cx][cy];
    arr[cx][cy] = -2;
    while(!q.empty()) {
        int fx = q.front().first, fy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = fx + dx[i], ny = fy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n || visited[nx][ny] || (arr[nx][ny] != 0 && arr[nx][ny] != color))
                continue;
            visited[nx][ny] = true;
            arr[nx][ny] = -2;
            q.push({nx, ny});
        }
    }
}
void drop() {
    for(int i=n-1;i>=1;i--) {
        for(int j=1;j<=n;j++) {
            if(arr[i][j] == -2 || arr[i][j] == -1) continue;
            int color = arr[i][j];
            int floor = i+1;
            while(floor <= n) {
                if(arr[floor][j] != -2) break;
                floor++;
            }
            floor--;
            arr[i][j] = -2;
            arr[floor][j] = color;
        }
    }
}
void rotate() {
    int cop[21][21];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cop[i][j] = arr[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            arr[j][i] = cop[i][n+1-j];
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> arr[i][j];
        }
    }
    int score = 0;
    while(1) {
        int group = 0, cx = -1, cy = -1, rb = 0;
        // cout << "before\n";
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(!visited[i][j] && arr[i][j] > 0) {
                    pair<int,int> p = bfs(i,j);
                    if(group < p.first) {
                        group = p.first;
                        rb = p.second;
                        cx = i, cy = j;
                    }
                    else if(group == p.first) {
                        if(rb < p.second) {
                            rb = p.second;
                            cx = i, cy = j;
                        }
                        else if(rb == p.second) {
                            if(cx < i) {
                                cx = i; cy = j;
                            } else if(cx == i){
                                if(cy < j) {
                                    cx = i; cy = j;
                                }
                            }   
                        }
                    }
                }
            }
        }
        // cout << "cx: "<<cx<<" cy: "<<cy<<'\n';
        if(group <= 1) break;
        memset(visited, false, sizeof(visited));
        remove(cx, cy);
        // cout << "after remove\n";
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "group: "<<group<<'\n';
        score += group * group;
        drop();
        // cout << "after drop\n";
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        rotate();
        drop();
        memset(visited, false, sizeof(visited));
    }
    cout << score;
}
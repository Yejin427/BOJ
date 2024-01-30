#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[301][301];
int tmp[301][301];
bool visited[301][301];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n,m;
bool inmap(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}
void melt() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] == 0) continue;
            for(int k=0;k<4;k++) {
                int nx = i+dx[k], ny = j+dy[k];
                if(!inmap(nx, ny)) continue;

                if(tmp[nx][ny] == 0) {
                    arr[i][j] = max(0, arr[i][j]-1);
                }
            }
        }
    }
}
void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!inmap(nx, ny) || visited[nx][ny]) continue;
        if(arr[nx][ny] != 0) {
            dfs(nx, ny);
        }
    }
}
int divided() {
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] != 0 && !visited[i][j]) {
                dfs(i, j); 
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    while(1) {
        int cur = divided();
        if(cur == 0) {
            cout << 0;
            return 0;
        }
        if(cur > 1) break;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        
        melt();

        memset(visited, false, sizeof(visited));
        ans++;
    }
    cout << ans;
}
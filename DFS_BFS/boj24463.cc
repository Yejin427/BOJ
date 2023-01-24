#include<iostream>
#include<vector>
using namespace std;
char arr[2002][2002];
bool chk[2002][2002];
bool go[2002][2002];
int n,m, sx, sy, ex, ey;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<int> v;
bool cango(int x, int y){
    if(1 <= x && x <= n && 1 <= y && y <= m && !chk[x][y] && arr[x][y] == '.') return true;
    return false;
}
bool dfs(int x, int y){
    chk[x][y] = true;
    if(x == ex && y == ey){
        return true;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(cango(nx, ny)){
            if(dfs(nx, ny)){
                go[nx][ny] = true;
                return true;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        if(arr[i][1] == '.' && v.size() < 4){
            v.push_back(i);
            v.push_back(1);
        }
        if(arr[i][m] == '.' && v.size() < 4){
            v.push_back(i);
            v.push_back(m);
        }
    }
    for(int i=1;i<=m;i++){
        if(arr[1][i] == '.' && v.size() < 4){
            v.push_back(1);
            v.push_back(i);
        }
        if(arr[n][i] == '.' && v.size() < 4){
            v.push_back(n);
            v.push_back(i);
        }
    }
    sx = v[0], sy = v[1], ex = v[2], ey = v[3];
    go[sx][sy] = true;
    dfs(sx, sy);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == '.' && !go[i][j]) cout << '@';
            else cout << arr[i][j];
        }
        cout <<'\n';
    }
}
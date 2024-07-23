#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int arr[101][101], play[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};   //S, E, N, W
int n,m;
int drop(int x, int y, int d){
    int res = 1;
    queue<pair<int,int>> q;
    play[x][y] = 0;
    q.push({x,y});
    while(!q.empty()) {
        pair<int,int> front = q.front();
        q.pop();
        int h = arr[front.first][front.second];

        int fx = front.first, fy = front.second;
        for(int i=1;i<h;i++) {
            fx += dx[d];
            fy += dy[d];

            if(fx < 1 || fx > n || fy < 1 || fy > m) break;
            if(play[fx][fy] == 0) continue;
            play[fx][fy] = 0;
            res++;
            q.push({fx,fy});
        }
    }
    return res;
}
int main() {
    int r; cin >> n >> m >> r;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            play[i][j] = arr[i][j]; //다시 올렸을 때 기억하기 위함
        }
    }
    int ans = 0;
    while(r--) {
        int x,y; char d; 
        cin >> x >> y >> d;
        int q;
        if(d == 'E') q = 1;
        else if(d == 'W') q = 3;
        else if(d == 'S') q = 0;
        else q = 2;
        if(play[x][y] > 0) ans += drop(x,y,q);
        int x2, y2; cin >> x2 >> y2;
        play[x2][y2] = arr[x2][y2];
    }
    cout << ans << '\n';
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(play[i][j] == 0) cout << "F ";
            else cout << "S ";
        }
        cout << '\n';
    }
}
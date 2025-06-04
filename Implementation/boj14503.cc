#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int arr[51][51];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int main(){
    int n,m; cin >> n >> m;
    int r,c,d; cin >> r >> c >> d;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    while(1){
        if(arr[r][c] == 0) {
            cout << "r: "<<r<<" c: "<<c<<'\n';
            arr[r][c] = 1;
            ans++;
        }
        bool hasnxt = false;
        for(int i=0;i<4;i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if(0 <= nr && nr < n && 0 <= nc && nc < m && arr[nr][nc] == 0) {
                hasnxt = true;
                break;
            }
        }
        if(hasnxt) {
            //반시계 회전
            if(d == 0) d = 3;
            else d--;
            //청소되지 않은 칸이면 전진
            if(0 <= r+dx[d] && r+dx[d] < n && 0 <= c+dy[d] && c+dy[d] < m 
                && arr[r+dx[d]][c+dy[d]] == 0) {
                r += dx[d];
                c += dy[d];
            }
        } else {
            //후진
            int nr = r + dx[d^2], nc = c + dy[d^2];
            //후진 가능하면 후진
            if(0 <= nr && nr < n && 0 <= nc && nc < m) {
                r = nr; c = nc;
            } else {
                break;
            }
        }
    }
    cout << ans;
}
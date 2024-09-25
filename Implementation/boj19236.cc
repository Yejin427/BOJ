#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[5][5][2];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans;
void btrk(pair<int,int> shark, int sum, int board[][5][2]) {
    int copyy[5][5][2];
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=4;j++) {
            copyy[i][j][0] = board[i][j][0];
            copyy[i][j][1] = board[i][j][1];
        }
    }
    int cur = copyy[shark.first][shark.second][0];
    sum += cur;
    copyy[shark.first][shark.second][0] = 0;
    ans = max(ans, sum);
    // 물고기 이동
    for(int i=1;i<=16;i++) {
        int fishx = -1, fishy = -1;
        for(int k=1;k<=4;k++) {
            for(int l=1;l<=4;l++) {
                if(copyy[k][l][0] == i) {
                    fishx = k; fishy = l;
                    break;
                }
            }
        }
        if(fishx == -1 && fishy == -1) continue;
        int dir = copyy[fishx][fishy][1];

        for(int j=0;j<8;j++) {
            int ndir = (dir + j) % 8;
            int nx = fishx + dx[ndir];
            int ny = fishy + dy[ndir];
            if(1 <= nx && nx <= 4 && 1 <= ny && ny <= 4 && !(nx == shark.first && ny == shark.second)) {
                copyy[fishx][fishy][1] = ndir;
                swap(copyy[fishx][fishy], copyy[nx][ny]);
                break;
            }
        }
    }
    //상어 이동
    int sharkdir = copyy[shark.first][shark.second][1];
    // cout << "sharkmove: "<<sharkdir<<'\n';
    for(int i=1;i<=3;i++) {
        int nx = shark.first + dx[sharkdir] * i;
        int ny = shark.second + dy[sharkdir] * i;
        if(1 <= nx && nx <= 4 && 1 <= ny && ny <= 4 && copyy[nx][ny][0] > 0) {
            btrk({nx,ny}, sum, copyy);
        }
    }
}
int main(){
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=4;j++) {
            cin >> arr[i][j][0] >> arr[i][j][1];
            arr[i][j][1]--;
        }
    }
    btrk({1,1}, 0, arr);
    cout << ans;
}
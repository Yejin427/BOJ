#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[21][4];
int iscurve[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int nxtdir(int dir) {
    if(dir == 3) return 0;
    else return dir+1;
}
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<4;j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        vector<int> dir;
        pair<int,int> curp = {arr[i][0], arr[i][1]};
        iscurve[curp.first][curp.second] = i;
        dir.push_back(arr[i][2]);
        curp.first += dx[arr[i][2]]; curp.second += dy[arr[i][2]];
        iscurve[curp.first][curp.second] = i;
        for(int j=1;j<=arr[i][3];j++){
            vector<int> nxtv;
            for(int idx = dir.size()-1;idx>=0;idx--) {
                int nxt = nxtdir(dir[idx]);
                nxtv.push_back(nxt);
                curp.first += dx[nxt]; curp.second += dy[nxt];
                iscurve[curp.first][curp.second] = i;
            }
            for(int d: nxtv) {
                dir.push_back(d);
            }
            // cout <<"j: "<<j<< " size: "<<dir.size()<<'\n';
        }
    }
    int ans = 0;
    // for(int i=0;i<=4;i++) {
    //     for(int j=0;j<=4;j++) {
    //         cout << iscurve[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            if(iscurve[i][j] && iscurve[i+1][j] && iscurve[i][j+1] && iscurve[i+1][j+1]) {
                ans++;
            }
        }
    }
    cout << ans;
}
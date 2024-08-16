#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
char arr[8][8];
bool visited[8][8];
int dx[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0}, dy[9] = {1, 0, -1, 0, 1, -1, 1, -1, 0};
bool cango(int nx, int ny, int time) {
    if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) return false;
    if(nx - time >= 0 && arr[nx - time][ny] == '#') return false;
    if(nx - time + 1 >= 0 && arr[nx - time + 1][ny] == '#') return false;
    return true; 
}
int main(){
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({0, {7, 0}});
    visited[7][0] = true;
    while(!q.empty()) {
        int time = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();
        if(x == 0 && y == 7) {
            cout << 1;
            return 0;
        }
        for(int i=0;i<9;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny, time+1)) {
                // cout << "nx: "<<nx<< " ny: "<<ny<<" time: "<<time+1<<'\n';
                q.push({time+1, {nx, ny}});
            }
        }
    }
    cout << 0;
}
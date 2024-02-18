#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
int arr[21][21], xpos, ypos;
int dest[21][21];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, shark;

void bfs(int destx, int desty){
    dest[xpos][ypos] = 0;
    queue<pair<int,int>> q;
    q.push({xpos, ypos});
    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        //cout << "fx: "<<fx<<" fy: "<<fy<<'\n';
        q.pop();
        if(fx == destx && fy == desty){
            break;
        }
        for(int i=0;i<4;i++){
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(dest[nx][ny] == -1 && arr[nx][ny] <= shark){
                q.push({nx, ny});
                dest[nx][ny] = dest[fx][fy] + 1;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                xpos = i;
                ypos = j;
                arr[i][j] = 0;
            }
        }
    }
    vector<pair<int,int>> eat;
    int time = 0, ate = 0;
    shark = 2;
    while(1){
        eat.clear();
        memset(dest, -1, sizeof(dest));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j] < shark && arr[i][j] != 0){
                    eat.push_back({i,j});
                }
            }
        }
        if(!eat.size()) break;  //먹을 수 있는 물고기 없음

        int shortest = 500;
        int fishx = 30, fishy = 30; //현재 가장 가까운 fish 위치
        for(auto& fish: eat){   //거리 계산
            if(dest[fish.first][fish.second] == -1){
                bfs(fish.first, fish.second);
            }
            if(dest[fish.first][fish.second] == -1) continue;
            if(dest[fish.first][fish.second] < shortest){
                shortest = dest[fish.first][fish.second];
                fishx = fish.first;
                fishy = fish.second;
            }
            else if(dest[fish.first][fish.second] == shortest){
                if(fishx > fish.first){
                    fishx = fish.first;
                    fishy = fish.second;
                }
                else if(fishx == fish.first && fishy > fish.second){
                    fishx = fish.first;
                    fishy = fish.second;
                }
            }
        }
        // cout << "shortest: "<<shortest<<'\n';
        // cout << "fishx: "<<fishx<<" fishy: "<< fishy<<"\n";
        if(shortest == 500) break; //먹을 수 있는 물고기 없음
        time += shortest;
        xpos = fishx;
        ypos = fishy;
        arr[xpos][ypos] = 0;
        ate++;
        if(shark == ate) {
            shark++;
            ate = 0;
        }
        
    }
    cout << time;
}
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m, arr[10][10];
bool temp[10][10];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<pair<int,int>> wall;
void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    temp[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        //cout << qx <<" "<<qy<<'\n';
        q.pop();
        for(int i=0;i<4;i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m || temp[nx][ny] || arr[nx][ny] != 0) continue;
            temp[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    //cout << "BFS finished"<<"\n";
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) wall.push_back({i,j});
        }
    }
    int ans = 0;
    for(int i=0;i<wall.size();i++){
        for(int j=i+1;j<wall.size();j++){
            for(int k=j+1;k<wall.size();k++){
                pair<int,int> w1 = wall[i];
                pair<int,int> w2 = wall[j];
                pair<int,int> w3 = wall[k];
                arr[w1.first][w1.second] = 1;
                arr[w2.first][w2.second] = 1;
                arr[w3.first][w3.second] = 1;

                for(int r=1;r<=n;r++){
                    for(int c=1;c<=m;c++){
                        if(arr[r][c] == 2){
                            bfs(r,c);
                        }
                    }
                }
                int cnt = 0;
                for(int r=1;r<=n;r++){
                    for(int c=1;c<=m;c++){
                        if(!temp[r][c] && arr[r][c] == 0) cnt++;
                    }
                }
                ans = max(cnt, ans);
                arr[w1.first][w1.second] = 0;
                arr[w2.first][w2.second] = 0;
                arr[w3.first][w3.second] = 0;
                memset(temp, false, sizeof(temp));
            }
        }
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
using pi = pair<pair<int,int>,int>;
char arr[51][51];
int visited[51][51][64];
int n,m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pi> q;
bool cango(int i, int j, int k){
    if(i > n || i < 1 || j > m || j < 1 || arr[i][j] == '#' || visited[i][j][k] != -1) return false;
    if('A'<=arr[i][j] && arr[i][j] <='F'){
        int cmp = 1 << (arr[i][j] - 'A');
        //cout <<k<<" "<< cmp<<" "<<(k&cmp)<<"\n";
        if((k & cmp) == 0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int sx = 0, sy = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == '0'){
                sx = i; sy = j;
            }
        }
    }
    memset(visited, -1, sizeof(visited));
    q.push({{sx, sy},0});
    visited[sx][sy][0] = 0;
    while(!q.empty()){
        int frontx = q.front().first.first;
        int fronty = q.front().first.second;
        int key = q.front().second;
        // cout << frontx<<" " << fronty<<" " << key<<"\n";
        q.pop();
        if(arr[frontx][fronty] == '1'){
            cout << visited[frontx][fronty][key];
            return 0;
        }
        for(int i=0;i<4;i++){
            int nx = frontx + dx[i];
            int ny = fronty + dy[i];
            if(cango(nx, ny, key)){
                int newkey = key;
                if('a'<=arr[nx][ny]&&arr[nx][ny]<='f'){//get key
                    newkey |= (1 << (arr[nx][ny] - 'a'));
                }
                visited[nx][ny][newkey] = visited[frontx][fronty][key] + 1;
                q.push({{nx, ny}, newkey});
            }
        }
    }
    cout << "-1";
}
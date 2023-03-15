#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int arr[100][100];
bool visited[100][100];
int l[1001], n,q, tmp;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
queue<pair<int,int>> qu;
void rotate(int r, int c, int len){
    int copy[100][100];
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            copy[j][len-1-i]=arr[r+i][c+j];
        }
    }

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            arr[r + i][c + j] = copy[i][j];
        }
    }
}
void rotate(int level){
    int len = 1 << level;
    for(int r = 0; r < n; r+=len){
        for(int c = 0; c < n; c+=len){
            rotate(r, c, len);
        }
    }
}
void melt(){
    int copy[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            copy[i][j] = arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(copy[i][j] == 0) continue;
            int ice = 4;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) ice--;
                else if(copy[nx][ny] == 0) ice--;
            }
            if(ice < 3) arr[i][j]--;
        }
    }
}
void bfs(int r, int c){
    visited[r][c] = true;
    qu.push({r, c});
    while(!qu.empty()){
        int fr = qu.front().first;
        int fc = qu.front().second;
        qu.pop();
        tmp++;
        for(int k=0;k<4;k++){
            int nr = fr + dx[k];
            int nc = fc + dy[k];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(arr[nr][nc] == 0 || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            qu.push({nr, nc});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    n = 1 << n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= q; i++) cin >> l[i];

    for(int lv = 1; lv <= q; lv++){
        rotate(l[lv]);
        melt();
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum += arr[i][j];
        }
    }
    cout << sum << '\n';
    int biggest = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && arr[i][j]){
                tmp = 0;
                bfs(i, j);
                biggest = max(biggest, tmp);
            }
        }
    }
    cout << biggest;
}
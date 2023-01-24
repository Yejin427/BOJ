#include<iostream>
#include<algorithm>
using namespace std;
int n,m,arr[51][51],p;
bool visited[51][51];
bool inmap(int col, int row){
    return(0 <= col && col < n && 0 <= row && row < m);
}
bool cango(int col, int row, int pipe){
    if(inmap(col, row) && !visited[col][row] && pipe <= p) return true;
    return false;
}
int dfs(int dir, int col, int row, int pipe, int sum){
    //cout <<"dir: " <<dir<<" col: "<<col<<" row: "<<row<<" pipe: "<<pipe<<" sum: "<<sum<<'\n';
    int ans = sum;
    if(pipe == p) return ans;
    ans += arr[col][row]; 
    int newsum = ans;
    int np = pipe+1;
    for(int i=0)
    switch(dir){
        case 0:
        if(cango(col+1, row, np)){
            visited[col+1][row] = true;
            ans = max(ans, dfs(0, col+1, row, np, newsum));
            visited[col+1][row] = false;
        }
        if(cango(col, row+1, np+1)){
            visited[col][row+1] = true;
            ans = max(ans, dfs(1, col, row+1, np+1, newsum));
            visited[col][row+1] = false;
        }
        if(cango(col, row-1, np+1)){
            visited[col][row-1] = true;
            ans = max(ans, dfs(3, col, row-1, np+1, newsum));
            visited[col][row-1] = false;
        }
        break;
        case 1:
        if(cango(col, row+1, np)){
            visited[col][row+1] = true;
            ans = max(ans, dfs(1, col, row+1, np, newsum));
            visited[col][row+1] = false;
        }
        if(cango(col+1, row, np+1)){
            visited[col+1][row] = true;
            ans = max(ans, dfs(0, col+1, row, np+1, newsum));
            visited[col+1][row] = false;
        }
        if(cango(col-1, row, np+1)){
            visited[col-1][row] = true;
            ans = max(ans, dfs(2, col-1, row, np+1, newsum));
            visited[col-1][row] = false;
        }
        break;
        case 2:
        if(cango(col-1, row, np)){
            visited[col-1][row] = true;
            ans = max(ans, dfs(2, col-1, row, np, newsum));
            visited[col-1][row] = false;
        }
        if(cango(col, row+1, np+1)){
            visited[col][row+1] = true;
            ans = max(ans, dfs(1, col, row+1, np+1, newsum));
            visited[col][row+1] = false;
        }
        if(cango(col, row-1, np+1)){
            visited[col][row-1] = true;
            ans = max(ans, dfs(3, col, row-1, np+1, newsum));
            visited[col][row-1] = false;
        }
        break;
        default:
        if(cango(col, row-1, np)){
            visited[col][row-1] = true;
            ans = max(ans, dfs(3, col, row-1, np, newsum));
            visited[col][row-1] = false;
        }
        if(cango(col+1, row, np+1)){
            visited[col+1][row] = true;
            ans = max(ans, dfs(0, col+1, row, np+1, newsum));
            visited[col+1][row] = false;
        }
        if(cango(col-1, row, np+1)){
            visited[col-1][row] = true;
            ans = max(ans, dfs(2, col-1, row, np+1, newsum));
            visited[col-1][row] = false;
        }
        break;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int x,y; cin >> x >> y >> p;
    /*dir 0, 1, 2, 3 -> up, left, down, right*/
    visited[x][y] = true;
    int answer = arr[x][y];
    if(inmap(x-1, y)) {
        visited[x-1][y]=true;
        answer = max(answer, dfs(2, x-1, y, 0, arr[x][y]));
        visited[x-1][y]=false;
    }
    if(inmap(x, y-1)) {
        visited[x][y-1]=true;
        answer = max(answer, dfs(3, x, y-1, 0, arr[x][y]));
        visited[x][y-1]=false;
    }
    if(inmap(x+1, y)) {
        visited[x+1][y]=true;
        answer = max(answer, dfs(0, x+1, y, 0, arr[x][y]));
        visited[x+1][y]=false;
    }
    if(inmap(x, y+1)) {
        visited[x][y+1]=true;
        answer = max(answer, dfs(1, x, y+1, 0, arr[x][y]));
        visited[x][y+1]=false;
    }
    cout << answer;
}
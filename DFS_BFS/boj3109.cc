#include<bits/stdc++.h>
using namespace std;
char arr[10001][501];
bool visited[10001][501];
int r,c, ans;
bool isok(int depth, int row){
    if(depth < 1 || depth > c || row < 1 || row > r || visited[row][depth] || arr[row][depth] == 'x'){
        return false;
    }
    return true;
}
bool dfs(int depth, int row){
    if(depth == c){
        return true;
    }
    for(int i=row-1;i<=row+1;i++){
        if(isok(depth+1, i)){
            visited[i][depth+1] = true;
            if(dfs(depth+1, i)) return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        if(dfs(1, i)) ans++;
    }
    cout << ans;
}
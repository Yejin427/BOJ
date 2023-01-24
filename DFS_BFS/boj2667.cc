#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[26][26];
int arr[26][26], n;

bool isok(int i, int j){
    if(1 <= i && i <= n && 1 <= j && j <= n && !visited[i][j] && arr[i][j]) return true;
    return false;
}
int bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int value = 0;
    while(!q.empty()){
        int frontx = q.front().first;
        int fronty = q.front().second;
        q.pop();
        value++;
        for(int k=0;k<4;k++){
            if(isok(frontx + dx[k], fronty + dy[k])){
                visited[frontx + dx[k]][fronty + dy[k]] = true;
                q.push({frontx + dx[k], fronty + dy[k]});
            }
        }
    }
    return value;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    int ans = 0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!visited[i][j] && arr[i][j]){
                v.push_back(bfs(i, j));
                ans++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ans << '\n';
    for(int i=0;i<v.size();i++) cout << v[i] << '\n';
}
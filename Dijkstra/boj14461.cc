#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, pair<int,int>>;
ll arr[101][101];
ll ans[101][101];
int dx[16]={-3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 1, 0, -1, 0};
int dy[16]={0, -1, 1, -2, 2, 3, -3, -2, 2, -1, 1, 0, 0, 1, 0, -1};
priority_queue<pi, vector<pi>, greater<pi>> pq;
ll dab;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,t; cin >> n >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            cin >> arr[i][j];
        }
    }
    memset(ans, -1, sizeof(ans));
    dab = 1e11;
    pq.push({0, {1, 1}});
    ans[1][1]=0;
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        ll cost = pq.top().first;
        pq.pop();
        if(ans[x][y] != -1 && ans[x][y] < cost) continue;
        if(2 * n - x - y < 3){
            dab = min(dab, cost + t * (2 * n - x - y));
        }
        for(int i=0;i<16;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(ans[nx][ny] != -1 && ans[nx][ny] < cost + 3 * t + arr[nx][ny]) continue;
            pq.push({cost + 3*t + arr[nx][ny], {nx,ny}});
            ans[nx][ny] = cost + 3*t + arr[nx][ny];
        }
        
    }
    cout << dab;
}
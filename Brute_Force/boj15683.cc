#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int arr[10][10];
vector<pair<int,pair<int,int>>> v;
vector<int> vdir;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n,m,ans = 100;
void shot(int dir, int tmpr, int tmpc) {
    // cout << "dir: "<<dir<<"tmpr: "<<tmpr<<" tmpc: "<<tmpc<<'\n';
    while(1) {
        tmpr += dx[dir], tmpc += dy[dir];
        if(!(1 <= tmpr && tmpr <= n && 1 <= tmpc && tmpc <= m) || arr[tmpr][tmpc] == 6) break;
        if(arr[tmpr][tmpc] == 0) arr[tmpr][tmpc] = -1;
    }
}
void dfs(int d) {
    if(d == v.size()) {
        // cout << "d: "<<d<<'\n';
        //# 표시 counting
        for(int i=0;i<v.size();i++) {
            int r = v[i].second.first, c = v[i].second.second;
            int tmpr = r, tmpc = c;
            if(v[i].first == 1) {
                shot(vdir[i]-1, tmpr, tmpc);
            }
            else if(v[i].first == 2) {
                if(vdir[i] == 1) {
                    shot(0, tmpr, tmpc);
                    shot(2, tmpr, tmpc);
                }
                else if(vdir[i] == 2) {
                    shot(1, tmpr, tmpc);
                    shot(3, tmpr, tmpc);
                }
            }
            else if(v[i].first == 3) {
                if(vdir[i] == 4) {
                    shot(3, tmpr, tmpc);
                    shot(0, tmpr, tmpc);
                } else {
                    shot(vdir[i]-1, tmpr, tmpc);
                    shot(vdir[i], tmpr, tmpc);
                }
            }
            else if(v[i].first == 4) {
                for(int j=0;j<4;j++) {
                    if(j == vdir[i]-1) continue;
                    shot(j, tmpr, tmpc);
                }
            }
            else {
                for(int j=0;j<4;j++) {
                    shot(j, tmpr, tmpc);
                }
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(arr[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(arr[i][j] == -1) arr[i][j] = 0;
            }
        }
        return;
    }
    if(v[d].first == 2) {
        for(int i=1;i<=2;i++) {
            vdir.push_back(i);
            dfs(d+1);
            vdir.pop_back();
        }
    } else if(v[d].first == 5) {
        vdir.push_back(1);
        dfs(d+1);
        vdir.pop_back();
    } else {
        for(int i=1;i<=4;i++) {
            vdir.push_back(i);
            dfs(d+1);
            vdir.pop_back();
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j] >= 1 && arr[i][j] < 6) {
                v.push_back({arr[i][j],{i,j}});
            }
        }
    }
    dfs(0);
    cout << ans;
}
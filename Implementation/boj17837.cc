#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr[15][15];
vector<pair<pair<int,int>,int>> v;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int oppo(int idx) {
    if(idx == 0) return 1;
    else if(idx == 1) return 0;
    else if(idx == 2) return 3;
    else return 2;
}
int main(){
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int color; cin >> color;
            arr[i][j].push_back(color);
        }
    }
    v.resize(k+1);
    for(int i=1;i<=k;i++) {
        int x,y,d;
        cin >> x >> y >> d;
        arr[x][y].push_back(i);
        v[i] = {{x,y},d-1};
    }
    int ans = 1;
    while(ans <= 1000) {
        bool end = false;
        for(int i=1;i<v.size();i++) {
            int x = v[i].first.first, y = v[i].first.second;
            int nx = x + dx[v[i].second];
            int ny = y + dy[v[i].second];
            int idx = 1;
            for(; idx < arr[x][y].size();idx++) {
                if(arr[x][y][idx] == i) break;
            }
            if(nx <= 0 || nx > n || ny <= 0 || ny > n || arr[nx][ny][0] == 2) {
                int nidx = oppo(v[i].second);
                nx = x + dx[nidx], ny = y + dy[nidx];
                v[i].second = nidx; //방향 전환
                if(nx > 0 && nx <= n && ny > 0 && ny <= n && arr[nx][ny][0] != 2) {
                    if(arr[nx][ny][0] == 0) {
                        for(int j=idx;j<arr[x][y].size();j++) {
                            arr[nx][ny].push_back(arr[x][y][j]);
                            v[arr[x][y][j]].first = {nx, ny};
                        }
                    }
                    else {
                        for(int j=arr[x][y].size()-1;j>=idx;j--) {
                            arr[nx][ny].push_back(arr[x][y][j]);
                            v[arr[x][y][j]].first = {nx, ny};
                        }
                    }
                    while(arr[x][y].begin()+idx != arr[x][y].end()) {
                        arr[x][y].erase(arr[x][y].begin()+idx);
                    }
                }
            }
            else if(arr[nx][ny][0] == 0) {
                for(int j=idx;j<arr[x][y].size();j++) {
                    arr[nx][ny].push_back(arr[x][y][j]);
                    v[arr[x][y][j]].first = {nx, ny};
                }
                while(arr[x][y].begin()+idx != arr[x][y].end()) {
                    arr[x][y].erase(arr[x][y].begin()+idx);
                }
            }
            else if(arr[nx][ny][0] == 1) {
                for(int j=arr[x][y].size()-1;j>=idx;j--) {
                    arr[nx][ny].push_back(arr[x][y][j]);
                    v[arr[x][y][j]].first = {nx, ny};
                }
                while(arr[x][y].begin()+idx != arr[x][y].end()) {
                    arr[x][y].erase(arr[x][y].begin()+idx);
                }
            }
            //체크
            for(int r=1;r<=n;r++) {
                for(int c=1;c<=n;c++) {
                    if(arr[r][c].size() >= 5) {
                        end = true;
                        break;
                    }
                }
                if(end) break;
            }
            if(end) break;
        }
        if(end) break;
        else ans++;
    }
    if(ans > 1000) cout << -1;
    else cout << ans;
}
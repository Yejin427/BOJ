#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct ball{
    int m,s,d;
};
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<ball> map[51][51];
int main(){
    int n,m,K; cin >> n >> m >> K;
    for(int i=1;i<=m;i++) {
        int r,c;
        ball b;
        cin >> r >> c >> b.m >> b.s >> b.d;
        map[r][c].push_back(b);
    }
    while(K--) {
        // cout << "K: "<<K<<'\n';
        //이동
        vector<ball> copy[51][51];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                for(int k=0;k<map[i][j].size();k++) {
                    copy[i][j].push_back(map[i][j][k]);
                }
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                for(int k=0;k<copy[i][j].size();k++) {
                    ball b = copy[i][j][k];
                    // cout << "dir: "<<b.d<<'\n';
                    int nr = i + dr[b.d] * b.s;
                    int nc = j + dc[b.d] * b.s;
                    map[i][j].erase(map[i][j].begin());
                    if(nr >= 0) nr %= n;
                    else nr = nr % n + n;
                    if(nr == 0) nr = n;
                    if(nc >= 0) nc %= n;
                    else nc = nc % n + n;
                    if(nc == 0) nc = n;
                    // cout << "nr: "<<nr<<" nc: "<<nc<<'\n';
                    map[nr][nc].push_back(b);
                }
            }
        }
        //나누기
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(map[i][j].size() < 2) continue;
                vector<ball> tmp;
                int mass = 0, velo = 0, odd = 0, even = 0;
                for(int k=0;k<map[i][j].size();k++) {
                    ball b = map[i][j][k];
                    mass += b.m;
                    velo += b.s;
                    (b.d % 2 == 0) ? even++ : odd++;
                }
                mass /= 5; velo /= map[i][j].size();
                map[i][j].clear();
                if(mass == 0) continue;
                if(odd == 0 || even == 0) {
                    map[i][j].push_back({mass, velo, 0});
                    map[i][j].push_back({mass, velo, 2});
                    map[i][j].push_back({mass, velo, 4});
                    map[i][j].push_back({mass, velo, 6});
                }
                else {
                    map[i][j].push_back({mass, velo, 1});
                    map[i][j].push_back({mass, velo, 3});
                    map[i][j].push_back({mass, velo, 5});
                    map[i][j].push_back({mass, velo, 7});
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=0;k<map[i][j].size();k++) {
                ans += map[i][j][k].m;
            }
        }
    }
    cout << ans;
}
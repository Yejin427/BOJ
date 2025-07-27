#include<iostream>
#include<string>
#include<vector>
using namespace std;
char map[26][26];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool haspipe(char sym, int dir) {
    if(sym == '-') {
        return dir == 0 || dir == 2;
    }
    else if(sym == '|') {
        return dir == 1 || dir == 3;
    }
    else if(sym == '+') {
        return true;
    }
    else if(sym == '1') {
        return dir == 0 || dir == 1;
    }
    else if(sym == '2') {
        return dir == 0 || dir == 3;
    }
    else if(sym == '3') {
        return dir == 2 || dir == 3;
    }
    else if(sym == '4') {
        return dir == 1 || dir == 2;
    }
    return false;
}
int main(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> map[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(map[i][j] != '.') continue;
            vector<int> v;
            for(int d=0;d<4;d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                    if(haspipe(map[nx][ny], d ^ 2)) {
                        v.push_back(d);
                    }
                }
            }
            if(v.size()) {
                cout << i << ' '<<j<<' ';
                if(v.size() == 4) {
                    cout << '+';
                }
                else if(v[0] == 0 && v[1] == 2) {
                    cout << '-';
                }
                else if(v[0] == 1 && v[1] == 3) {
                    cout << '|';
                }
                else if(v[0] == 0 && v[1] == 1) {
                    cout << '1';
                }
                else if(v[0] == 1 && v[1] == 2) {
                    cout << '4';
                }
                else if(v[0] == 2 && v[1] == 3) {
                    cout << '3';
                }
                else cout << '2';
                return 0;
            }
        }
    }
}
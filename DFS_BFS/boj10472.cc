#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int dx[5] = {1, 0, -1, 0, 0}, dy[5] = {0, 1, 0, -1, 0}, d[5] = {-3, -1, 3, 1, 0};
bool chk[1 << 9];
int main(){
    int p; cin >> p;
    while(p--) {
        int board = 0;
        for(int i=8;i>=0;i--) {
            char x; cin >> x;
            if(x == '*') {
                board += (1 << i);
                // cout << "i: "<<i<<"1<<i "<<(1<<i)<<'\n';
            }
        }
        queue<pair<int,int>> q;
        q.push({0, 0});
        memset(chk, false, sizeof(chk));
        chk[0] = true;
        bool solved = false;
        while(!q.empty()) {
            int b = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(b == board) {
                cout << cnt << '\n';
                break;
            }
            bool prev[3][3];
            int idx = 8;
            for(int i=0;i<3;i++) {
                for(int j=0;j<3;j++) {
                    prev[i][j] = ((b & (1<< idx)) != 0);
                    idx--;
                }
            }
            idx = 8;
            for(int i=0;i<3;i++) {
                for(int j=0;j<3;j++) {
                    int nb = b;
                    for(int k=0;k<5;k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        int nn = idx + d[k];
                        if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                            nb ^= (1 << nn);
                        }
                    }
                    idx--;
                    if(!chk[nb]) {
                        chk[nb] = true;
                        q.push({nb, cnt+1});
                    }
                }
            }
        }
    }
}
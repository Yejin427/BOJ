#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct {
    int y,x;
}Dir;

Dir moveDir[3] = {{1,1}, {1,0}, {1,-1}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<string> mine(2);
        cin >> mine[0] >> mine[1];

        int res = 0; int temp = 0;
        for(int i=0;i<n;i++) {
            if(mine[1][i] == '*') res++;
        }
        for(int i=0;i<n;i++) {
            if(mine[0][i] > '0' && mine[0][i] <= '9') {
                temp = mine[0][i] - '0';
            }
            else continue;

            for(int j=0;j<3;j++) {
                int nxtX = i + moveDir[j].x;
                if(!temp) break;
                if(0 <= nxtX && nxtX < n) {
                    if(mine[1][nxtX] == '*') temp--;
                }
            }
            for(int j=0;j<3;j++) {
                int nxtX = i + moveDir[j].x;
                if(!temp) break;
                if(0 <= nxtX && nxtX < n) {
                    if(mine[1][nxtX] == '#') {
                        mine[1][nxtX] = '*';
                        res++;
                        // cout << "res: "<<res<<'\n';
                        temp--;
                    }
                }
            }
        }
        cout << res << '\n';
    }
}
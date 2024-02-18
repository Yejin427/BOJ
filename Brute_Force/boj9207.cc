#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

char arr[10][10];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int minpin = 100, minmove;
bool inmap(int x, int y) {
    return 1 <= x && x <= 5 && 1 <= y && y <= 9;
}
void dfs(int depth) {

    bool canmove = false;

    for(int i=1;i<=5;i++) {
        for(int j=1;j<=9;j++) {
            if(arr[i][j] == 'o') {
                for(int k=0;k<4;k++) {
                    int nxtX = i + dx[k];
                    int nxtY = j + dy[k];

                    if(!inmap(nxtX, nxtY) || !inmap(nxtX+dx[k], nxtY+dy[k])) continue;
                    if(arr[nxtX][nxtY] == 'o' && arr[nxtX+dx[k]][nxtY+dy[k]] == '.') {
                        canmove = true;
                        arr[i][j] = '.';
                        arr[nxtX][nxtY] = '.';
                        arr[nxtX+dx[k]][nxtY+dy[k]] = 'o';
                        dfs(depth+1);
                        arr[i][j] = 'o';
                        arr[nxtX][nxtY] = 'o';
                        arr[nxtX+dx[k]][nxtY+dy[k]] = '.';
                    }
                }
            }
        }
    }
    
    if(!canmove) {
        int cnt = 0;
        for(int i=1;i<=5;i++) {
            for(int j=1;j<=9;j++) {
                if(arr[i][j] == 'o') cnt++;
            }
        }
        if(minpin > cnt) {
            minpin = cnt;
            minmove = depth;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    while(n--) {
        for(int i=1;i<=5;i++) {
            for(int j=1;j<=9;j++) {
                cin >> arr[i][j];
            }
        }
        dfs(0);
        cout << minpin << ' ' << minmove << '\n';
        minpin = 100, minmove = 0;
    }
}
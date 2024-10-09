#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string str[2001];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int MOD = 1e9 + 7;
long long func(int num) {
    if(num == 1) return 2;
    long long tmp;
    if(num % 2) {
        return (2 * func(num-1)) % MOD;
    }
    else {
        tmp = func(num / 2);
        return (tmp * tmp) % MOD;
    }
}
int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> str[i];
    }
    int num = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c = str[i][j];
            int k;
            for(k=0;k<4;k++) {
                int nx = i + d[k][0], ny = j + d[k][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(str[nx][ny] != c) break;
            }
            if(k == 4) {
                num++;
            }
        }
    }
    cout << func(num) << '\n';
}
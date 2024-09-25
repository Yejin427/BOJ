#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[25][25];
int map[25][25];
int cnt[6];
int n;
int func(int x, int y, int d1, int d2) {
    for(int i=1;i<=5;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            map[i][j] = 5;
        }
    }
    int sub = 0;
    for(int i=1;i<x+d1;i++) {
        if(i >= x) {
            sub++;
        }
        for(int j=1;j<=y-sub;j++) {
            map[i][j] = 1;
        }
    }
    sub = 0;
    for(int i=1;i<=x+d2;i++) {
        if(i > x) sub++;
        for(int j=y+1+sub;j<=n;j++) {
            map[i][j] = 2;
        }
    }
    sub = 0;
    for(int i=n;i>=x+d1;i--) {
        if(i < x+d1+d2) sub++;
        for(int j=1;j<y-d1+d2-sub;j++) {
            map[i][j] = 3;
        }
    }
    sub = 0;
    for(int i=n;i>x+d2;i--) {
        if(i <= x+d1+d2) sub++;
        for(int j=y-d1+d2+sub;j<=n;j++) {
            map[i][j] = 4;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cnt[map[i][j]] += a[i][j];
        }
    }
    sort(cnt+1, cnt+6);
    return cnt[5] - cnt[1];
}
int main(){
    cin >> n;
    int sum = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    int ans = 10000;
    for(int x=1;x<=n;x++) {//행 x
        for(int y=1;y<=n;y++) {//열 y
            for(int d1 = 1; d1 < y; d1++) { //d1
                if(x + d1 > n) break;
                for(int d2 = 1; d2 <= n - y; d2++) {    //d2
                    if(x + d1 + d2 > n) break;
                    int tmp = func(x,y,d1,d2);
                    if(ans > tmp) {
                        ans = tmp;
                        // cout << x << ' '<<y<<' '<<d1<<' '<<d2<<'\n';
                        // cout << tmp << '\n';
                    }
                }
            }
        }
    }
    cout << ans;
}
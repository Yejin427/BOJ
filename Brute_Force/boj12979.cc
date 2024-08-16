#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
    int w,h,a;
    cin >> w >> h >> a;
    int ans = 2e9;
    for(int i=1;i<=sqrt(a);i++) {
        if(a % i == 0) {
            int q = a / i;
            //w가 q가 될때
            int tmpw = w, tmph = h, cnt = 0;
            if(tmpw >= q && tmph >= i) {
                while(tmpw > q) {
                    tmpw = ceil((double)tmpw / 2);
                    cnt++;
                }
                while(tmph > i) {
                    tmph = ceil((double)tmph / 2);
                    cnt++;
                }
                ans = min(ans, cnt);
            }
            tmpw = w, tmph = h, cnt = 0;
            if(tmpw >= i && tmph >= q ) {
                while(tmpw > i) {
                    tmpw = ceil((double)tmpw / 2);
                    cnt++;
                }
                while(tmph > q) {
                    tmph = ceil((double)tmph / 2);
                    cnt++;
                }
                ans = min(ans, cnt);
            }
        }
    }
    if(ans == 2e9) cout << -1;
    else cout << ans;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int arr[100001];
int pow2[100001];
const int MOD = 1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    pow2[0] = 1;
    for(int i=1;i<=100000;i++) {
        pow2[i] = pow2[i-1] * 2 % MOD;
    }
    while(t--) {
        int n; cin >> n;
        for(int i=1;i<=n;i++) {
            cin >> arr[i];
        }
        if(n == 1) {
            cout << arr[1] << '\n';
            continue;
        }
        int ans = -2;
        int startidx = 1;
        bool isPlus = false;
        while(startidx <= n) {
            while(arr[startidx] == 0) {
                ans = max(0, ans);
                startidx++;
            }
            if(startidx > n) break;
            int twostart = -1, twoend = -1, minusCnt = 0, twoCnt = 0;
            int endidx;
            for(endidx=startidx;endidx<=n;endidx++) {
                if(arr[endidx] == 0) break;
                if(abs(arr[endidx]) == 2) {
                    twoCnt++;
                    if(twostart == -1) twostart = endidx;
                    twoend = endidx;
                }
                if(arr[endidx] < 0) minusCnt++;
            }
            endidx--;
            if(arr[startidx] < 0 && startidx == endidx) {
                ans = max(arr[startidx], ans);
                startidx = endidx + 1;
                continue;
            }
            isPlus = true;
            if(minusCnt % 2 == 0) {
                ans = max(twoCnt, ans);
            } else {
                bool canPlus = false;
                for(int i=startidx; i<twostart; i++) {
                    if(arr[i] < 0) {
                        canPlus = true;
                        break;
                    }
                }
                if(!canPlus) {
                    for(int i=twoend+1; i<=endidx; i++) {
                        if(arr[i] < 0) {
                            canPlus = true;
                            break;
                        }
                    }
                }
                if(canPlus) {
                    ans = max(twoCnt, ans);
                } else {
                    int minustwo1 = 0, minustwo2 = 0;
                    for(int i=twostart; i<=twoend; i++) {
                        if(abs(arr[i]) == 2) {
                            minustwo1++;
                        }
                        if(arr[i] < 0) break;
                    }
                    for(int i=twoend; i>=twostart; i--) {
                        if(abs(arr[i]) == 2) {
                            minustwo2++;
                        }
                        if(arr[i] < 0) break;
                    }
                    ans = max(twoCnt - min(minustwo1, minustwo2), ans);
                }
            }
            startidx = endidx+1;
        }
        if(!isPlus) cout << ans << '\n';
        else cout << pow2[ans] << '\n';
    }
}
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
ll arr[100];
bool watch[100][100];
ll ccw(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = y1 * x2 + y2 * x3 + y3 * x1;
    if(a < b) return -1;
    else if(a > b) return 1;
    else return 0;
}
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    memset(watch, true, sizeof(watch));
    for(int i=1;i<=n;i++) {
        for(int j=i+2;j<=n;j++) {
            for(int k=i+1;k<j;k++) {
                if(ccw(i, k, j, arr[i], arr[k], arr[j]) <= 0) {
                    watch[i][j] = false;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        int cnt = 0;
        for(int j=1;j<=n;j++) {
            if(i == j) continue;
            if((i < j && watch[i][j]) || (j < i && watch[j][i])) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
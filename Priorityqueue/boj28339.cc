#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int p[100001], a[100001];
int cnt[11];
int curmax[11], ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
        priority_queue<pair<int,int>> q[10];
        int n,k; cin >> n >> k;
        for(int i=1;i<=n;i++) {
            cin >> p[i] >> a[i];
        }
        for(int i=1;i<=k;i++) {
            q[p[i]].push({a[i], i});
        }
        ans = 0;
        int total = 0;
        for(int i=1;i<=9;i++) {
            if(q[i].empty()) {
                total = 0;
                break;
            }
            total += q[i].top().first;
        }
        for(int i=k;i<=n;i++) {
            q[p[i]].push({a[i], i});
            for(int j=1;j<=9;j++) {
                while(!q[j].empty() && q[j].top().second <= i-k) {
                    q[j].pop();
                }
            }
            int total = 0;
            for(int j=1;j<=9;j++) {
                if(q[j].empty()) {
                    total = 0;
                    break;
                }
                total += q[j].top().first;
            }
            ans = max(ans, total);
        }
        cout << ans << '\n';
    }
}
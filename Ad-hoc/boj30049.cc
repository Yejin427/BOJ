#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[10001][301]; 
pair<int,int> curmax[10001];  //가게 최대 매출
int maxcnt[301];    //사람마다 최대매출 수
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k; cin >> n >> m >> k;
    for(int i=1;i<=m;i++) {
        curmax[i] = {0, 0};
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            int store, price; cin >> store >> price;
            arr[store][i] = price;
            if(price > curmax[store].second) {
                curmax[store] = {i, price};
            }
        }
    }
    for(int i=1;i<=m;i++) {
        maxcnt[curmax[i].first]++;
    }
    int q; cin >> q;
    while(q--) {
        int i,j,v; cin >> i >> j >> v;
        arr[j][i] += v;
        if(arr[j][i] > curmax[j].second) {
            maxcnt[curmax[j].first]--;
            maxcnt[i]++;
            curmax[j] = {i, arr[j][i]};
        }
        int ans = 0;
        for(int idx=1;idx<=n;idx++) {
            // cout << 'p'<<idx<<": "<<maxcnt[idx]<<' ';
            if(maxcnt[idx] == k) ans++;
        }
        // cout << '\n';
        cout << ans << '\n';
    }
}
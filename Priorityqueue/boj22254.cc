#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
vector<ll> v(100001);
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    int n; ll x; 
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = n;
    ll ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;

        for(int i = 1; i <= mid; i++) pq.push(0);
        for(int i = 1; i <= n; i++) {
            ll top = pq.top();
            pq.pop();
            top += v[i];
            pq.push(top);
        }
        ll maxTime = 0;
        while(!pq.empty()) {
            maxTime = max((ll)pq.top(), maxTime);
            pq.pop();
        }
        if(maxTime <= x) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}
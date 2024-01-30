#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using ll = long long;
ll arr[1001];
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main() {
    int n,m; cin >> n >> m;

    ll sum = 0;
    for(int i=1;i<=n;i++) {
        ll x; cin >> x;
        pq.push(x);
        sum += x;
    }

    while(m--) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        sum += (a + b);
        pq.push(a + b);
        pq.push(a + b);
    }
    cout << sum;
}
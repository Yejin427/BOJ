#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
ll a[100001];
ll sum[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sum[i] = sum[i-1] ^ a[i];
    }
    vector<int> one(30);
    for(int i=0;i<30;i++) {
        for(int j=0;j<=n;j++) {
            if((1<<i) & sum[j]) one[i]++;
        }
    }

    ll ans = 0;
    for(int i=0;i<30;i++) {
        ans += (1LL << i)*one[i]*(n+1-one[i]);
    }    
    cout << ans;
}
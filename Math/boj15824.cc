#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1'000'000'007
using namespace std;
vector<long long> v;
long long power[300010];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    long long ans = 0;
    power[0] = 1;
    for(int i=1;i<=n;i++) {
        power[i] = power[i-1] * 2 % MOD;
    }
    for(int i=0;i<n;i++) {
        ans += (v[i] % MOD) * power[i] % MOD;
        ans -= (v[i] % MOD) * power[n-i-1] % MOD;
        ans = ((ans % MOD) + MOD) % MOD;
    }

    cout << ans;
}
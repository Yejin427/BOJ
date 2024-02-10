#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
using ll = long long;
vector<string> v;
ll dp[1 << 15][110];
int ten[55];
int rest[16][2];
int n,k;
ll gcd(ll x, ll y) {
    while (y != 0) {
		ll R = x % y;
		x = y;
		y = R;
	}
	return x;
}
ll f(int s, int num) {
    if(s == (1 << n) - 1) return (num % k == 0);
    if(dp[s][num] != -1) return dp[s][num];
    dp[s][num] = 0;

    for(int i=0;i<n;i++) {
        if(s & (1 << i)) continue;
        
        ll nxt = num * ten[rest[i][0]] + rest[i][1];
        nxt %= k;
        dp[s][num] += f(s | (1 << i), nxt);
    }
    return dp[s][num];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll total = 1;
    for(int i=1;i<=n;i++) {
        string num; cin >> num;
        v.push_back(num);
        total *= i;
    }
    cin >> k;
    ten[0] = 1 % k;
    for(int i=1;i<=52;i++) {
        ten[i] = ten[i-1] * 10 % k;
    }
    for(int i=0;i<n;i++) {
        rest[i][0] = v[i].length();
        for(int j=0;j<v[i].length();j++) {
            int idx = v[i].length() - 1 - j;
            rest[i][1] += ((v[i][j] - '0') * ten[idx]) % k;
        }
        rest[i][1] %= k;
    }
    memset(dp, -1, sizeof(dp));
    ll cnt = f(0, 0);
    ll g = gcd(total, cnt);
    cout << cnt / g << "/" << total / g;
}
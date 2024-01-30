#include<iostream>

using namespace std;
using ll = long long;
ll MOD = 1e9+7;
ll gcd(ll x, ll y){
    while(y != 0){
        ll R = x % y;
        x = y; y = R;
    }
    return x;
}
ll f(ll x, ll y){
    if(x == 1) return 1;
    if(y == 0) return 1;
    if(y % 2 == 1) return x * f(x, y-1) % MOD;
    ll tmp = f(x, y / 2);
    return tmp * tmp % MOD;
}
int main(){
    int N; cin >> N;
    ll ans = 0;
    for(int i=1;i<=N;i++){
        ll a, b;
        cin >> b >> a;
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        ans += (a * f(b, MOD-2)) % MOD;
        ans %= MOD;
    }
    cout << ans;    
}
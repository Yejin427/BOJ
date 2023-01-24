#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> m;
ll n,p,q;
ll dp(ll n){
    if(n == 0) return 1;
    if(m.find(n) != m.end()) return m[n];
    return m[n] = dp(n/p)+dp(n/q);
}
int main(){
    cin >> n >> p >> q;
    cout << dp(n);
}
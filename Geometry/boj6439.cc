#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;
pair<ll,ll> lbot;
pair<ll,ll> ltop;
pair<ll,ll> rbot;
pair<ll,ll> rtop;
ll ccw(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = y1 * x2 + y2 * x3 + y3 * x1;
    if(a-b < 0) return -1;
    else if(a == b) return 0;
    else return 1;
}
bool cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll a = ccw(x1, x2, x3, y1, y2, y3);
    ll b = ccw(x1, x2, x4, y1, y2, y4);
    ll c = ccw(x3, x4, x1, y3, y4, y1);
    ll d = ccw(x3, x4, x2, y3, y4, y2);
    if(a * b < 0 && c * d < 0) return true;
    else if((a * b == 0 && c * d < 0) || (a * b < 0 && c * d == 0)) {
        return true;
    }
    else if(a * b == 0 && c * d == 0) {
        pair<ll,ll> P1 = {x1, y1};
        pair<ll,ll> P2 = {x2, y2};
        pair<ll,ll> P3 = {x3, y3};
        pair<ll,ll> P4 = {x4, y4};
        if((P1 < P3 && P1 < P4 && P2 < P3 && P2 < P4) || (P3 < P1 && P3 < P2 && P4 < P1 && P4 < P2)) {
            return false;
        }
        else return true;
    }
    else return false;
}
bool inside(ll xs, ll ys, ll xe, ll ye) {
    return lbot.first < xs && xs < rbot.first && lbot.first < xe && xe && rbot.first
        && lbot.second < ys && ys < ltop.second && lbot.second < ye && ye < ltop.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        ll xs, ys, xe, ye, xl, yt, xr, yb;
        cin >> xs >> ys >> xe >> ye >> xl >> yt >> xr >> yb;
        
        lbot = {min(xl, xr), min(yb, yt)};
        ltop = {min(xl, xr), max(yb, yt)};
        rbot = {max(xl, xr), min(yb, yt)};
        rtop = {max(xl, xr), max(yb, yt)};
        if(cross(xs, ys, xe, ye, xl, yt, xl, yb) || cross(xs, ys, xe, ye, xr, yt, xr, yb)
        || cross(xs, ys, xe, ye, xl, yt, xr, yt) || cross(xs, ys, xe, ye, xl, yb, xr, yb)
        || inside(xs, ys, xe, ye)){
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }
}
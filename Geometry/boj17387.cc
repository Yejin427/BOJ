#include<iostream>
using ll = long long;
using namespace std;
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = y1 * x2 + y2 * x3 + y3 * x1;
    if(a <b) return -1;
    else if(a > b) return 1;
    else return 0;
}
int main(){
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    pair<ll, ll> P1 ={x1,y1};
    pair<ll, ll> P2 ={x2,y2};
    pair<ll, ll> P3 ={x3,y3};
    pair<ll, ll> P4 ={x4,y4};

    ll c1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
    ll c2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
    if(c1 < 0 && c2 < 0) cout <<"1";
    else if((c1 ==0 && c2 < 0) || (c1 < 0 && c2 == 0)){
        cout << "1";
    }
    else if(c1 == 0 && c2 == 0){
        if((P1 < P3 && P2 < P3 && P1 < P4 && P2 < P4) || (P3 < P1 && P3 < P2 && P4 < P1 && P4 < P2)){
            cout << "0";
        }
        else cout <<"1";
    }
    else cout <<"0";
}

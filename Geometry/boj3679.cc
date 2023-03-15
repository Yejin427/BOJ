#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
using ll = long long;
using pii = pair<pair<ll,ll>,ll>;
pair<ll,ll> pt;
int n;
ll ccw(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3){
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = y1 * x2 + y2 * x3 + y3 * x1;
    return a - b;
}
long double dist(pair<ll,ll> a , pair<ll,ll> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
bool pointSort(pii a, pii b){
    int CCW = ccw(pt.first, a.first.first, b.first.first, pt.second, a.first.second, b.first.second);
    if(CCW == 0) return dist(pt, a.first) < dist(pt, b.first);
    return CCW > 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c; cin >> c;
    while(c--){
        vector<pii> points;
        vector<pii> convex;
        cin >> n;
        for(int i=0;i<n;i++){
            ll x,y; cin >> x >> y;
            points.push_back({{x, y},i});
        }
        
        sort(points.begin(), points.end());
        pt = points[0].first;
        sort(points.begin()+1, points.end(), pointSort);

        int idx = n-1;
        for(int i=n-1;i>=1;i--){
            if(ccw(points[0].first.first, points[idx].first.first, points[idx-1].first.first, 
            points[0].first.second, points[idx].first.second, points[idx-1].first.second) == 0) idx--;
            else break;
        }
        reverse(points.begin()+idx, points.end());
        for(auto& p: points){
            cout << p.second << ' ';
        }
        cout <<'\n';
    }
}
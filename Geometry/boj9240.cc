#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll = long long;
pair<ll,ll> standard;
vector<pair<ll,ll>> points;
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = y1 * x2 + y2 * x3 + y3 * x1;
    return a - b;
}
bool cmp(pair<ll,ll> p1, pair<ll,ll> p2){
    ll ccwpoint = ccw(standard.x, standard.y, p1.x, p1.y, p2.x, p2.y);
    if(ccwpoint == 0){
        return (p1.x + p1.y) < (p2.x + p2.y);
    }
    return ccwpoint > 0;
}
double dis(pair<ll, ll> p1, pair<ll, ll> p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
ll ccw2(pair<ll, ll> p1start, pair<ll, ll> p1end, pair<ll, ll> p2start, pair<ll, ll> p2end){
    ll ax = p1start.x - p1end.x;
    ll ay = p1start.y - p1end.y;

    ll bx = p2start.x - p2end.x;
    ll by = p2start.y - p2end.y;

    return ax * by - bx * ay;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        ll a,b; cin >> a >> b;
        points.push_back({a,b});
    }

    if(n == 2){
        cout << fixed;
        cout.precision(8);
        cout << dis(points[0], points[1]) << '\n';
        return 0;
    }
    sort(points.begin(), points.end());
    standard = points[0];
    points.erase(points.begin());
    
    sort(points.begin(), points.end(), cmp);

    vector<pair<ll, ll>> hull;  //convex hull;
    hull.push_back(standard);

    for(auto& p: points){
        while (hull.size() >= 2){
            pair<ll, ll> p1 = hull.back();
            hull.erase(hull.end() - 1);
            pair<ll, ll> p2 = hull.back();
            if(ccw(p2.x, p2.y, p1.x, p1.y, p.x, p.y) > 0){
                hull.push_back(p1);
                break;
            }
        }
        hull.push_back(p);
    }
    int size = hull.size();
    if(size == 2){//모두 일직선
        cout << fixed;
        cout.precision(8);
        cout << dis(hull[0], hull[1]);
        return 0;
    }
    double ans = 0;
    int p1 = 1; //0,1
    int p2 = 2; //1,2
    while(p1 != size + 1){
        //cout << p1 << " " << p2 <<'\n';
        pair<ll, ll> start2 = hull[p2 - 1];
        pair<ll, ll> end2 = hull[p2];
        pair<ll, ll> start1 = hull[p1 - 1];
        pair<ll, ll> end1 = hull[p1];
        if(p2 == size){
            start2 = hull.back();
            end2 = hull[0];
        }
        if(p1 == size){  
            start1 = hull.back();
            end1 = hull[0];
        }
        double length = dis(start1, start2);
        //cout<<"length: "<<length<<'\n';
        ans = max(length, ans);

        //p1 move || p2 move
        if(ccw2(start1, end1, start2, end2) >= 0){
            if(p2 == size) p2 = 1;
            else p2++;
        }
        else p1++;
    }
    cout << fixed;
    cout.precision(8);
    cout << ans << '\n';
}
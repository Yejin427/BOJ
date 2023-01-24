#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

vector<pi> arr;
vector<pi> convex;
pi standard;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = y1 * x2 + y2 * x3 + y3 * x1;
    return a - b;
}
ll ccw2(pi p1start, pi p1end, pi p2start, pi p2end){
    ll ax = p1start.x - p1end.x;
    ll ay = p1start.y - p1end.y;

    ll bx = p2start.x - p2end.x;
    ll by = p2start.y - p2end.y;

    return ax * by - bx * ay;
}
ll dis(pair<ll, ll> p1, pair<ll, ll> p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
bool cmp(pi p1, pi p2){
    ll ccwpoint = ccw(standard.x, standard.y, p1.x, p1.y, p2.x, p2.y);
    if(ccwpoint == 0){
        return (p1.x + p1.y) < (p2.x + p2.y);
    }
    return ccwpoint > 0;
}
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        ll a, b; cin >> a >> b;
        arr.push_back({a,b});

    }

    if(n == 2){
        cout << dis(arr[0], arr[1]) << '\n';
        return 0;
    }
    sort(arr.begin(), arr.end());
    for(int i = 1; i < arr.size(); i++){
        
    }
    standard = arr[0];
    arr.erase(arr.begin());
    
    sort(arr.begin(), arr.end(), cmp);

    convex.push_back(standard);

    for(auto& p: arr){
        while (convex.size() >= 2){
            pair<ll, ll> p1 = convex.back();
            convex.erase(convex.end() - 1);
            pair<ll, ll> p2 = convex.back();
            if(ccw(p2.x, p2.y, p1.x, p1.y, p.x, p.y) > 0){
                convex.push_back(p1);
                break;
            }
        }
        convex.push_back(p);
    }
    int size = convex.size();
    if(size == 2){//모두 일직선
        cout << dis(convex[0], convex[1]);
        return 0;
    }
    ll ans = 0;
    int p1 = 1; //0,1
    int p2 = 2; //1,2
    while(p1 != size + 1){
        //cout << p1 << " " << p2 <<'\n';
        pair<ll, ll> start2 = convex[p2 - 1];
        pair<ll, ll> end2 = convex[p2];
        pair<ll, ll> start1 = convex[p1 - 1];
        pair<ll, ll> end1 = convex[p1];
        if(p2 == size){
            start2 = convex.back();
            end2 = convex[0];
        }
        if(p1 == size){  
            start1 = convex.back();
            end1 = convex[0];
        }
        ll length = dis(start1, start2);
        //cout<<"length: "<<length<<'\n';
        ans = max(length, ans);

        //p1 move || p2 move
        if(ccw2(start1, end1, start2, end2) >= 0){
            if(p2 == size) p2 = 1;
            else p2++;
        }
        else p1++;
    }
    cout << ans << '\n';
}

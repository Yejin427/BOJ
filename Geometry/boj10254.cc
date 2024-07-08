#include<iostream>
#include<cmath>
#include<vector>
#include<deque>
#include<algorithm>
#define x first
#define y second
using namespace std;
using ll = long long;
typedef pair<ll, ll> pi;

ll distance(pi p1, pi p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
ll ccw(pi p1, pi p2, pi p3) {
    ll a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    ll b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return a - b;
}
ll ccw2(pi p1, pi p2, pi p3, pi p4) {
    //p3를 p2로 평행이동, p4 조정
    ll xmove = p3.x - p2.x;
    ll ymove = p3.y - p2.y;
    pi newp4 = {p4.x - xmove, p4.y - ymove};
    return ccw(p1, p2, newp4);
}
pi first;
bool ccwsort(pi p1, pi p2) {
    ll cmp = ccw(first, p1, p2);
    if(cmp == 0) {
        return distance(first, p1) < distance(first, p2);
    }
    return cmp > 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        vector<pi> p;
        int n; cin >> n;
        for(int i=1;i<=n;i++) {
            ll f,s; cin >> f >> s;
            p.push_back({f,s});
        }
        
        sort(p.begin(), p.end());
        first = p[0];
        p.erase(p.begin());
        sort(p.begin(), p.end(), ccwsort);

        deque<pi> chull;
        chull.push_back(first);

        for(int i = 0; i < n-1; i++) {
            while(chull.size() >= 2 && ccw(chull[chull.size()-2], chull.back(), p[i]) <= 0) {
                chull.pop_back();
            }
            chull.push_back(p[i]);
        }
        if(chull.size() == 2) {
            cout << chull[0].x << ' '<<chull[0].y<< ' ' << chull[1].x << ' ' << chull[1].y << '\n';
            continue;
        }
        //rotating callipers
        int idx1 = 0, idx2 = 1;
        int ansp1 = 0, ansp2 = 1;
        ll ans = 0;
        int size = chull.size();
        while(idx1 != size) {
            // cout << "idx1: "<<idx1<< " idx2: "<<idx2<<'\n';
            int idx2nxt = idx2 == size-1 ? 0 : idx2+1;
            if(distance(chull[idx1], chull[idx2]) > ans) {
                ans = distance(chull[idx1], chull[idx2]);
                // cout << "ans: "<<ans<<'\n';
                ansp1 = idx1, ansp2 = idx2;
            }
            if(ccw2(chull[idx1], chull[idx1+1], chull[idx2], chull[idx2nxt]) >= 0) {
                idx2 = (idx2 + 1) % size;
            } else {
                idx1++;
            }
        }
        cout << chull[ansp1].x << ' '<< chull[ansp1].y << ' '<<chull[ansp2].x << ' '<<chull[ansp2].y << '\n';
    }
}
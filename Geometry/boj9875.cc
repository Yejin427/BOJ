#include<iostream>
#include<cmath>
#include<deque>
#include<vector>
#include<algorithm>
#define x first
#define y second 
using namespace std;
using ll = long long;
typedef pair<ll,ll> pi;
pi start;
ll ccw(pi p1, pi p2, pi p3) {
    ll a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    ll b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return a-b;
}
ll dist(pi p1, pi p2) {
    return (p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y);
}
bool ccwsort(pi p1, pi p2) {
    ll CCW = ccw(start, p1, p2);
    if(CCW == 0) {
        return dist(start, p1) < dist(start, p2);
    }
    return CCW > 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pi> v1;
    vector<pi> v2;
    for(int i=1;i<=n;i++) {
        ll xp, yp; cin >> xp >> yp;
        v1.push_back({xp, yp});
    }
    for(int i=1;i<=n;i++) {
        ll xp, yp; cin >> xp >> yp;
        v2.push_back({xp, yp});
    }
    sort(v1.begin(), v1.end());
    start = v1[0];
    sort(v1.begin() + 1, v1.end(), ccwsort);
    deque<pi> ch1;
    for(auto point: v1) {
        while(ch1.size() >= 2 && ccw(ch1[ch1.size()-2], ch1.back(), point) <= 0){
            ch1.pop_back();
        }
        ch1.push_back(point);
    }
    // for(auto p: ch1) {
    //     cout << p.x << ' '<<p.y<<'\n';
    // }
    int leftidx = 1, rightidx = ch1.size()-1;
    int ans1 = 0, ans2 = 0;
    for(auto point: v2) {
        bool determined = false;
        while(leftidx + 1 < rightidx) {
            int mid = (leftidx + rightidx) / 2;
            if(ccw(ch1[0], ch1[leftidx], point) > 0 && ccw(ch1[0], ch1[mid], point) < 0) {
                rightidx = mid;
            }
            else if(ccw(ch1[0], ch1[mid], point) > 0 && ccw(ch1[0], ch1[rightidx], point) < 0) {
                leftidx = mid;
            }
            else if(ccw(ch1[0], ch1[leftidx], point) == 0) {
                if(ch1[0] <= point && point <= ch1[leftidx]) {
                    ans1++;
                }
                determined = true;
                break;
            }
            else if(ccw(ch1[0], ch1[mid], point) == 0) {
                if(ch1[0] <= point && point <= ch1[mid]) {
                    ans1++;
                }
                determined = true;
                break;
            }
            else if(ccw(ch1[0], ch1[rightidx], point) == 0) {
                if(ch1[0] <= point && point <= ch1[rightidx]) {
                    ans1++;
                }
                determined = true;
                break;
            } 
            else {
                determined = true;
                break;
            }
        }
        if(determined) continue;
        if(ccw(ch1[0], ch1[leftidx], point) > 0 && ccw(ch1[leftidx], ch1[rightidx], point) > 0
             && ccw(ch1[rightidx], ch1[0], point) > 0) {
            ans1++;
        }
        else if(ccw(ch1[leftidx], ch1[rightidx], point) == 0 
        && ((ch1[leftidx] <= point && point <= ch1[rightidx]) || (ch1[rightidx] <= point && point <= ch1[leftidx]))) {
            ans1++;
        }
    }
    sort(v2.begin(), v2.end());
    start = v2[0];
    sort(v2.begin()+1, v2.end(), ccwsort);
    deque<pi> ch2;
    for(auto point: v2) {
        while(ch2.size() >= 2 && ccw(ch2[ch2.size()-2], ch2.back(), point) <= 0){
            ch2.pop_back();
        }
        ch2.push_back(point);
    }
    // for(auto p: ch2) {
    //     cout << p.x << ' '<<p.y<<'\n';
    // }
    leftidx = 1, rightidx = ch2.size()-1;
    for(auto point: v1) {
        bool determined = false;
        while(leftidx + 1 < rightidx) {
            int mid = (leftidx + rightidx) / 2;
            if(ccw(ch2[0], ch2[leftidx], point) > 0 && ccw(ch2[0], ch2[mid], point) < 0) {
                rightidx = mid;
            }
            else if(ccw(ch2[0], ch2[mid], point) > 0 && ccw(ch2[0], ch2[rightidx], point) < 0) {
                leftidx = mid;
            }
            else if(ccw(ch2[0], ch2[leftidx], point) == 0) {
                if(ch2[0] <= point && point <= ch2[leftidx]) {
                    ans2++;
                }
                determined = true;
                break;
            }
            else if(ccw(ch2[0], ch2[mid], point) == 0) {
                if(ch2[0] <= point && point <= ch2[mid]) {
                    ans2++;
                }
                determined = true;
                break;
            }
            else if(ccw(ch2[0], ch2[rightidx], point) == 0) {
                if(ch2[0] <= point && point <= ch2[rightidx]) {
                    ans2++;
                }
                determined = true;
                break;
            } 
            else {
                determined = true;
                break;
            }
        }
        if(determined) continue;
        if(ccw(ch2[0], ch2[leftidx], point) > 0 && ccw(ch2[leftidx], ch2[rightidx], point) > 0
             && ccw(ch2[rightidx], ch2[0], point) > 0) {
            ans2++;
        }
        else if(ccw(ch2[leftidx], ch2[rightidx], point) == 0 
        && ((ch2[leftidx] <= point && point <= ch1[rightidx]) || (ch2[rightidx] <= point && point <= ch2[leftidx]))) {
            ans2++;
        }
    }
    cout << ans1 << ' '<<ans2;
}

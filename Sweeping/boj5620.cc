#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>

using namespace std;
using pi = pair<int,int>;
set<pi> hubo;
vector<pi> v;

int dist(pi p1, pi p2){
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    
    sort(v.begin(), v.end(), [](pi a, pi b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else a.second < b.second;
    });
    
    hubo = { v[0], v[1] };
    int ans = dist(v[0], v[1]);
    int s = 0;
    for(int i=2;i<n;i++){
        pi cur = v[i];

        while(s < i) {
            pi start = v[s];
            int disty = cur.second - start.second;
            if(disty * disty > ans){
                hubo.erase(start);
                s++;
            }
            else break;
        }
        int d = (int)sqrt((double)ans) + 1;

        //x중 -d~+d까지 볼거임
        pi lower = {cur.first - d, -100000};
        pi upper = {cur.first + d, 100000};

        auto l = hubo.lower_bound(lower);
        auto r = hubo.upper_bound(upper);

        for(auto it = l; it != r; it++){
            int distance = dist(cur, *it);
            ans = min(ans, distance);
        }
        hubo.insert(cur);
    }
    cout << ans;
    return 0;
}
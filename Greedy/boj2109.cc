#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<pair<int,int>> v;
priority_queue<int> q;
int main() {
    int n, maxDay; cin >> n;
    for(int i=1;i<=n;i++) {
        int d,p; cin >> p >> d;
        v.push_back({d, p});
        maxDay = max(d, maxDay);
    }
    
    sort(v.begin(), v.end());
    // for(int i=0;i<v.size();i++) cout << v[i].first << ' '<<v[i].second<< '\n';
    int idx = n-1, ans = 0;
    for(int i=maxDay;i>=1;i--) {
        for(; idx >= 0 && v[idx].first == i; idx--) {
            q.push(v[idx].second);
        }
        if(!q.empty()) {
            // cout << "top: "<<q.top()<<'\n';
            ans += q.top();
            q.pop();
        }
    }

    cout << ans;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<long long, long long>> rev;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        long long a,b; cin >> a >> b;
        if(a > b) rev.push_back({a, b});
    }
    sort(rev.begin(), rev.end(), [&](pair<long long, long long> a, pair<long long, long long> b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    if(rev.size() == 0) {
        cout << m;
        return 0;
    }
    long long last = rev[0].first;
    long long len = rev[0].first - rev[0].second;
    for(int i=1;i<rev.size();i++) {
        if(last >= rev[i].second) {
            if(last < rev[i].first) {
                len += rev[i].first - last;
                last = rev[i].first;
            }
        }
        else {
            len += rev[i].first - rev[i].second;
            last = rev[i].first;
        }
    }
    cout << m + 2 * len;
}
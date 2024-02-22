#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<long long, long long>> back;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        long long a,b; cin >> a >> b;
        if(a > b) back.push_back({a, b});
    }
    sort(back.begin(), back.end(), [&](pair<long long, long long> a, pair<long long, long long> b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    long long last = back[0].first;
    long long len = back[0].first - back[0].second;
    for(int i=1;i<back.size();i++) {
        if(last >= back[i].second) {
            if(last < back[i].first) {
                len += back[i].first - last;
                last = back[i].first;
            }
            
        }
        else {
            len += back[i].first - back[i].second;
            last = back[i].first;
        }
    }
    cout << m + 2 * len;
}
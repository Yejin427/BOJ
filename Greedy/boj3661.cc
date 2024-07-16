#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) {
        return a.second > b.second; //idx 큰 순으로 정렬 -> 더 작은 값을 냄
    }
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int p,n; cin >> p >> n;
        int sum = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            int x; cin >> x;
            v.push_back({x, i});
            sum += x;
        }
        sort(v.begin(), v.end(), cmp);
        if(sum < p) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        int idx = 0, curtotal = p;
        vector<int> ans;
        ans.resize(n);
        while(idx < n) {
            int mean = curtotal / (n-idx);
            if(v[idx].first > mean) break;

            while(idx < n && v[idx].first <= mean) {
                ans[v[idx].second] = v[idx].first;
                curtotal -= v[idx].first;
                idx++;
            }            
        }
        if(idx < n) {
            int mean = curtotal / (n-idx);
            int rest = curtotal % (n-idx);
            for(int i=idx; i<n-rest;i++) {
                ans[v[i].second] = mean;
            }
            for(int i=n-rest;i<n;i++) {
                ans[v[i].second] = mean+1;
            }
        }
        for(int i=0;i<n;i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}
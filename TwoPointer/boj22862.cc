#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1000001];
vector<pair<int,int>> v;
int main() {
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];

    int start = -1, end = -1;
    for(int i=1;i<=n;i++) {
        if(arr[i] % 2 == 1) {
            if(start == -1) continue;
            v.push_back({start, end});
            start = -1;
        }
        else {
            if(start == -1) {
                start = i;
                end = i;
            } else {
                end++;
            }
        }
    }
    if(start != -1) v.push_back({start, end});
    // for(auto vi: v) cout << vi.first << ' '<<vi.second << '\n';
    if(v.size() == 0) {
        cout << 0;
        return 0;
    }
    int left = 0, right = 0;
    int ans = 0, tmplen = v[0].second - v[0].first + 1, tmpcnt = 0;
    while(right < v.size()) {
        // cout << "tmplen: "<<tmplen<<" tmpcnt: "<<tmpcnt<<'\n';
        if(tmpcnt <= k) {
            ans = max(tmplen, ans);
            right++;
            tmplen += v[right].second - v[right].first + 1;
            tmpcnt += v[right].first - v[right-1].second - 1;
        } else {
            left++;
            tmplen -= v[left-1].second - v[left-1].first + 1;
            tmpcnt -= v[left].first - v[left-1].second - 1;
        }
    }
    cout << ans;
}
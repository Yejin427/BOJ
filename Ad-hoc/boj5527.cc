#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[100001];
int dp[100001];
vector<pair<int,int>> v;
int main() {
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    int l = 1, r = 1;
    for(int i=2;i<=n;i++) {
        if(arr[i] == arr[i-1]) {
            v.push_back({l, r});
            l = i; r = i;
        } 
        else {
            r++;
        }
    }
    v.push_back({l, r});
    int ans = 0;
    if(v.size() == 1) {
        cout << v[0].second - v[0].first + 1;
    } else {
        for(int i=0;i<v.size();i++) {
            int tmp = v[i].second - v[i].first + 1;
            if(i == 0) {
                ans = max(ans, tmp + v[1].second - v[1].first + 1);
            } 
            else if(i == v.size()-1) {
                ans = max(ans, tmp + v[i-1].second - v[i-1].first + 1);
            }
            else {
                ans = max(ans, tmp + (v[i-1].second - v[i-1].first + 1) + (v[i+1].second - v[i+1].first + 1));
            }
        }
        
        cout << ans;
    }
}
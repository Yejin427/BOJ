#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[200001];
int len[200001];
int ans[200001];
vector<int> v;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int num; cin >> num;
        a.push_back(num);
    }

    v.push_back(a[0]);
    len[0] = 1;
    int cnt = 0;
    for(int i=1;i<n;i++) {
        if(v.back() <= a[i]) {
            v.push_back(a[i]);
            len[i] = v.size();
        }
        else {
            v[upper_bound(v.begin(), v.end(), a[i])-v.begin()] = a[i];
            len[i] = upper_bound(v.begin(), v.end(), a[i])-v.begin();
        }
    }
    int ptr = v.size();
    for(int i=n-1;i>=0;i--) {
        if(len[i] == ptr) {
            ans[ptr] = a[i];
            ptr--;
        }
    }
    if(n - v.size() > 3) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << n-v.size()<<'\n';
        a.push_back(1e9);
        ptr = v.size();
        for(int i=n-1;i>=0;i--) {
            if(a[i] != ans[ptr]) {
                cout << i+1 << ' '<< a[i+1] << '\n';
                a[i] = a[i+1];
            }
            else ptr--;
        }
    }
}
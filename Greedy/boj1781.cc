#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
vector<pi> v;
priority_queue<int> q;
int main(){
    int n; cin >> n;
    int maxdead = 0;
    for(int i=1; i<=n; i++){
        int dead, cup;
        cin >> dead >> cup;
        maxdead = max(dead, maxdead);
        v.push_back({dead, cup});
    }
    int date = n, ans = 0;
    sort(v.begin(), v.end());
    int idx = n-1;
    for(int i=n;i>=1;i--){
        for(; idx >= 0 && v[idx].first == i; idx--){
            q.push(v[idx].second);
        }
        if(!q.empty()){
            ans += q.top();
            q.pop();
        }
    }
    cout << ans;
}
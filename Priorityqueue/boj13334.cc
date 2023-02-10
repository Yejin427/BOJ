#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using pi = pair<int,int>;
bool cmp(pi a, pi b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
vector<pi> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int s,e; cin >> s >> e;
        v.push_back({min(s, e), max(s, e)});
    }
    int d; cin >> d;
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for(int i=0;i<v.size();i++){
        int o = v[i].second;
        int h = v[i].first;

        if(o - h > d) continue;
        pq.push(h);
        while(!pq.empty()){
            int top = pq.top();
            if(o - top <= d) break;
            else pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
}
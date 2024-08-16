#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,bool>> v;

int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int s,e; cin >> s >> e;
        v.push_back({s,true});
        v.push_back({e,false});
    }
    sort(v.begin(), v.end());
    int ans = 0, cnt = 0;
    for(auto p: v) {
        if(p.second) {
            cnt++;
        } else {
            cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
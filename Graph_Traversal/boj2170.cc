#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int,int>> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int s,e;
        cin >> s >> e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end());
    int l = -1e9, r = -1e9;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(r < v[i].first){
            ans += r-l;
            l = v[i].first;
            r = v[i].second;
        }
        else r = max(r, v[i].second);
    }
    ans += r-l;
    cout << ans;
}
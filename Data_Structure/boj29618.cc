#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;
int ans[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q; cin >> n >> q;
    set<int> nc;
    for(int i=1;i<=n;i++) {
        nc.insert(i);
    }
    while(q--) {
        int a,b,x; cin >> a >> b >> x;
        queue<int> q;
        for(auto it = nc.lower_bound(a); it != nc.end() && *it <= b; it++) {
            ans[*it] = x;
            q.push(*it);
        }
        while(!q.empty()) {
            nc.erase(q.front());
            q.pop();
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
}
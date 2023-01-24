#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;//목적지, 가치
vector<pii> v[2000001];
priority_queue<int> ans[2000001];
struct cmp{
    bool operator()(pii a, pii b){
        return a.second > b.second;
    }
};
priority_queue<pii, vector<pii>, cmp> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k; cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    pq.push({1,0});
    ans[1].push(0);
    while(!pq.empty()){
        int v1 = pq.top().first;
        int w1 = pq.top().second;
        pq.pop();

        for(auto& p: v[v1]){
            if(ans[p.first].size() < k) {
                ans[p.first].push(w1 + p.second);
                pq.push({p.first, w1 + p.second});
            }
            else if(ans[p.first].top() > w1 + p.second){
                ans[p.first].pop();
                ans[p.first].push(w1+p.second);
                pq.push({p.first, w1 + p.second});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(k != ans[i].size()) cout <<"-1\n";
        else cout << ans[i].top()<<'\n';
    }
}
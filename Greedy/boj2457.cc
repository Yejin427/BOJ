#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using flower = pair<pair<int,int>, pair<int,int>>;
vector<flower> v;
struct cmp{
    bool operator()(flower f1, flower f2){
        if(f1.second != f2.second){
            return f1.second < f2.second;   //늦게 지는 순
        }
        return f1.first < f2.first;
    }
};
priority_queue<flower, vector<flower>, cmp> pq;
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        v.push_back({{m1, d1}, {m2, d2}});
    }
    sort(v.begin(), v.end());   //피는 순
    // for(auto& top: v){
    //     cout << "sorted: "<<top.first.first<<"/"<<top.first.second<<" "<<top.second.first<<"/"<<top.second.second<<'\n';
    // }
    pair<int,int> cur = {3, 1};
    pair<int,int> end = {11, 30};
    int ans = 0;
    int idx = 0;
    while(1){
        //cout << "cur: "<<cur.first<<"/"<<cur.second<<'\n';
        if(cur >= end) break;
        bool ok = false;
        while(idx < n && v[idx].first <= cur){
            if(v[idx].first <= cur && cur < v[idx].second){
                pq.push(v[idx]);
                ok = true;
            }
            idx++;
        }
        if(!ok) break;
        if(!pq.empty()){
            flower top = pq.top();
            //cout << "top: "<<top.first.first<<"/"<<top.first.second<<" "<<top.second.first<<"/"<<top.second.second<<'\n';
            pq.pop();
            ans++;
            cur.first = top.second.first;
            cur.second = top.second.second;
        }
    }
    if(cur < end){
        cout << 0;
    }
    else cout << ans;
}
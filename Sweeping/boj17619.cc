#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<pair<int,int>,int>> v;
int parent[100001];
int find(int x){
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
void merge(int x, int y){
    int rx = find(x);
    int ry = find(y);
    parent[ry] = rx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        v.push_back({{x1, x2}, i});
    }

    sort(v.begin(), v.end());
    for(int i=1;i<=n;i++) parent[i] = i;

    int start = v[0].first.first;
    int end = v[0].first.second;
    int curset = v[0].second;
    for(int i = 1; i < n; i++){
        if(v[i].first.first <= end){
            end = max(v[i].first.second, end);
            merge(curset, v[i].second);
        }
        else {
            start = v[i].first.first;
            end = v[i].first.second;
            curset = v[i].second;
        }
    }
    while(q--){
        int q1, q2; cin >> q1 >> q2;
        if(find(q1) != find(q2)){
            cout << 0 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }
}
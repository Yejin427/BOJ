#include<bits/stdc++.h>
using namespace std;
using pi = pair<pair<int,int>,int>;
bool cmp(pi a, pi b){
    return a.first.first < b.first.first;
}
class segtree{
public:
    vector<int> tree;
    int size;
    segtree(int n){
        for(size = 1; size < n; size *= 2);
        tree.resize(2 * size);
    }
    void init(){
        fill(tree.begin(), tree.end(), 500001);
    }
    int update(int pos, int start, int end, int target, int val){
        if(target < start || end < target) return tree[pos];
        if(start == end) return tree[pos] = val;
        int mid = (start + end) / 2;
        return tree[pos] = min(update(pos * 2, start, mid, target, val), update(pos * 2 + 1, mid + 1, end, target, val));
    }
    int minquery(int pos, int start, int end, int left, int right){
        if(left > end || right < start) return 500001;
        if(left <= start && end <= right) return tree[pos];
        int mid = (start + end) / 2;
        return min(minquery(pos * 2, start, mid, left, right), 
            minquery(pos * 2 + 1, mid + 1, end, left, right));
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pi> vi;
    vi.resize(n+1);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        vi[x].first.first = i;
    }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        vi[x].first.second = i;
    }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        vi[x].second = i;
    }
    sort(vi.begin() + 1, vi.end(), cmp);
    segtree seg(n);
    seg.init();
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(seg.minquery(1, 1, n, 1, vi[i].first.second) > vi[i].second) ans++;
        seg.update(1, 1, n, vi[i].first.second, vi[i].second);
    }
    cout << ans;
}
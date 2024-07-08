#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
ll arr[100001];
class segtree{
public:
    int size;
    vector<ll> tree;
    segtree(int n) {
        for(size = 1; size < n; size *= 2);
        tree.resize(2*size);
    }
    ll query(int s, int e, int l, int r, int pos) {
        if(l > e || r < s) return -1e9;
        if(l <= s && e <= r) return tree[pos];
        int mid = (s + e) / 2;
        return max(query(s, mid, l, r, 2 * pos), query(mid+1, e, l, r, 2 * pos + 1));
    }
    void update(int s, int e, int idx, int pos, ll val) {
        if(idx < s || idx > e) return;
        if(s == e) tree[pos] = val;
        else {
            int mid = (s + e) / 2;
            update(s, mid, idx, 2 * pos, val);
            update(mid+1, e, idx, 2 * pos + 1, val);
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d; cin >> n >> d;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    segtree seg(n);

    seg.update(1, n, 1, 1, arr[1]);
    ll ans = arr[1];
    for(int i=2;i<=n;i++) {
        ll tmp = arr[i];
        tmp += max(0ll, seg.query(1, n, max(0, i-d), i-1, 1));
        seg.update(1, n, i, 1, tmp);
        ans = max(ans, tmp);
    }
    cout << ans;
}
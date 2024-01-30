#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class segtree{
public:
    int size;
    vector<int> tree;

    segtree(int n) {
        for(size = 1; size < n; size *= 2);
        tree.resize(2 * size);
    }

    void insert(int node, int start, int end, int pos, int val) {
        if(pos < start || end < pos) return;
        if(start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        insert(2 * node, start, mid, pos, val);
        insert(2 * node + 1, mid + 1, end, pos, val);
        tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int left, int right) {
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return max(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    segtree seg(n);
    for(int i=1;i<=n;i++) {
        int val; cin >> val;
        seg.insert(1, 1, n, i, val);
    }

    for(int i=m;i<=n-m+1;i++){
        cout << seg.query(1, 1, n, i-m+1, i+m-1) << ' ';
    }
}
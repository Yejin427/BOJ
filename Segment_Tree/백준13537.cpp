#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class segtree {
public:
	int size;
	vector<int> tree[300000];
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
	}
	void update(int x, int pos) {
		int idx = size + pos - 1;
		while (idx) {
			tree[idx].push_back(x);
			idx /= 2;
		}
	}
	int query(int start, int end, int left, int right, int pos, int num) {
		if (start > right || end < left) return 0;
		else if (left <= start && end <= right) return tree[pos].end() - upper_bound(tree[pos].begin(), tree[pos].end(), num);
		int mid = (start + end) / 2;
		return query(start, mid, left, right, pos * 2, num) + query(mid + 1, end, left, right, pos * 2 + 1, num);
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	segtree seg(n);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		seg.update(x, i);
	}
	for (int i = 1; i < seg.size; i++) {
		sort(seg.tree[i].begin(), seg.tree[i].end());
	}
	int t; cin >> t;
	while (t--) {
		int i, j, k; cin >> i >> j >> k;
		cout << seg.query(1, seg.size, i, j, 1, k) << '\n';
	}
}

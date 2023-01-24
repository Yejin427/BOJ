#include<iostream>
#include<vector>
using namespace std;
class segtree {
public:
	vector<int> tree;
	vector<int> lazy;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		tree.resize(2 * size);
		lazy.resize(2 * size);
	}
	void update_lazy(int pos, int start, int end) {
		if (lazy[pos] != 0) {
			if ((end - start + 1) % 2 == 1) tree[pos] ^= lazy[pos];
			if (start != end) {
				lazy[pos * 2] ^= lazy[pos];
				lazy[pos * 2 + 1] ^= lazy[pos];
			}
			lazy[pos] = 0;
		}
	}
	void update_range(int pos, int start, int end, int left, int right,int diff) {
		update_lazy(pos, start, end);
		if (left > end || right < start) return;
		if (left <= start && end <= right) {
			lazy[pos] ^= diff;
			update_lazy(pos, start, end);
			return;
		}
		int mid = (start + end) / 2;
		update_range(pos * 2, start, mid, left, right, diff);
		update_range(pos * 2 + 1, mid + 1, end, left, right, diff);
		tree[pos] = tree[pos * 2] ^ tree[pos * 2 + 1];
	}
	int getxor(int pos, int left, int right, int start, int end) {
		update_lazy(pos, start, end);
		if (left > end || right < start) {
			return 0;
		}
		else if (left <= start && end <= right) {
			return tree[pos];
		}
		int mid = (start + end) / 2;
		return getxor(pos * 2, left, right, start, mid) ^ getxor(pos * 2 + 1, left, right, mid + 1, end);
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m; cin >> n;
	segtree tree(n);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		tree.update_range(1, 1, tree.size, i, i, x);
	}
	cin >> m;
	while (m--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			if (b > c) swap(b, c);
			tree.update_range(1, 1, tree.size, b+1, c+1, d);
		}
		else {
			cin >> b >> c;
			if (b > c) swap(b, c);
			cout << tree.getxor(1, b+1, c+1, 1, tree.size) << '\n';
		}
	}
}
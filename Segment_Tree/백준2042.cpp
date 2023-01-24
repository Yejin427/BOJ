#include<iostream>
#include<vector>
using namespace std;
class segtree {
public:
	vector<long long> tree;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		tree.resize(2 * size);
	}
	void update(int pos, long long x) {
		int index = size + pos - 1;
		int u = x - tree[index];
		while (index) {
			tree[index] += u;
			index /= 2;
		}
	}
	long long getsum(int pos, int left, int right, int start, int end) {
		if (right<start || left>end) {
			return 0;
		}
		if (start >= left && end <= right) {
			return tree[pos];
		}
		int mid = (start + end) / 2;
		return getsum(pos * 2, left, right, start, mid) + getsum(pos * 2 + 1, left, right, mid + 1, end);

	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	segtree tree(n);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		tree.update(i, x);
	}
	int t = m + k;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) tree.update(b, c);
		else cout << tree.getsum(1, b, c, 1, tree.size) << "\n";
	}
}
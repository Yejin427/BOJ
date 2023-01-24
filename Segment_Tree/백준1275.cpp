#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
class segtree {
public:
	vector<ll> tree;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		tree.resize(2 * size);
	}
	void update(int pos, ll x) {
		int index = size + pos - 1;
		ll u = x - tree[index];
		while (index) {
			tree[index] += u;
			index /= 2;
		}
	}
	ll getsum(int pos, int left, int right, int start, int end) {//left right가 찾는 범위
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
	int n, q, k, x, y, a, b;
	cin >> n >> q;
	segtree tree(n);
	for (int i = 1; i <= n; i++) {
		cin >> k;
		tree.update(i, k);
	}
	while (q--) {
		cin >> x >> y >> a >> b;
		if (x <= y) cout << tree.getsum(1, x, y, 1, tree.size) << "\n";
		else cout << tree.getsum(1, y, x, 1, tree.size) << "\n";
		tree.update(a, b);
	}
}
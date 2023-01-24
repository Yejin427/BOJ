#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
class segtree {
public:
	int size;
	vector<ll> v;
	vector<ll> lazy;
	segtree(int n) {
		for (size = 1; size <= n; size *= 2);
		v.resize(2 * size);
		lazy.resize(2 * size);
	}
	void update(int idx, ll x) {
		int pos = idx + size - 1;
		while (pos) {
			v[pos] += x;
			pos /= 2;
		}
	}
	void update_range(int start, int end, int left, int right, ll diff, int node) {
		if (lazy[node]) {
			v[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (right < start || left > end) return;
		if (left <= start && end <= right) {
			v[node] += (end - start + 1) * diff;
			if (start != end) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		int mid = (start + end) / 2;
		update_range(start, mid, left, right, diff, node * 2);
		update_range(mid + 1, end, left, right, diff, node * 2 + 1);
		v[node] = v[node * 2] + v[node * 2 + 1];
	}
	ll var(int start, int end, int left, int right, int node) {
		if (lazy[node]) {
			v[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (right<start || left>end) return 0;
		if (left <= start && end <= right) return v[node];
		int mid = (start + end) / 2;
		return var(start, mid, left, right, node * 2) + var(mid + 1, end, left, right, node * 2 + 1);
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m,i,j,k,q; cin >> n;
	segtree tree(n);
	for (int p = 1; p <= n; p++) {
		int x; cin >> x;
		tree.update(p, x);
	}
	cin >> m;
	while (m--) {
		cin >> q;
		if (q == 1) {
			cin >> i >> j >> k;
			tree.update_range(1, tree.size, i, j, k, 1);
		}
		else {
			cin >> k;
			cout << tree.var(1, tree.size, k, k, 1) << '\n';
		}
	}
}
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
class segtree {
public:
	int size;
	vector<ll> tree;
	vector<pair<ll, ll>> lazy;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		tree.resize(2 * size);
		lazy.resize(2 * size);
	}
	void init(int pos, ll x) {
		int idx = size + pos - 1;
		while (idx) {
			tree[idx] += x;
			idx /= 2;
		}
	}
	void update_lazy(int start, int end, int node) {
		if (lazy[node].first != 0) {
			tree[node] += (end - start + 1) * (lazy[node].first + lazy[node].second) / 2;
			if (start != end) {//lazy propagate
				ll intv = (lazy[node].second - lazy[node].first) / (end - start);
				lazy[node * 2].first += lazy[node].first;
				lazy[node * 2 + 1].second += lazy[node].second;
				lazy[node * 2].second += lazy[node].first + intv * ((start + end) / 2 - start);
				lazy[node * 2 + 1].first += lazy[node].second - intv * ((start + end) / 2 - start);
			}
			lazy[node].first = 0; lazy[node].second = 0;
		}
	}
	void update(int start, int end, int left, int right, int node) {
		update_lazy(start, end, node);
		if (right<start || left>end) return;
		if (left <= start && end <= right) {
			tree[node] += (end - start + 1) * (start - 2 * left + 2 + end) / 2;
			if (start != end) {
				lazy[node * 2].first += start - left + 1;
				lazy[node * 2 + 1].second += end - left + 1;
				lazy[node * 2].second += (start + end) / 2 - left + 1;
				lazy[node * 2 + 1].first += (start + end) / 2 - left + 2;
			}
			return;
		}
		int mid = (start + end) / 2;
		update(start, mid, left, right, node * 2);
		update(mid + 1, end, left, right, node * 2 + 1);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	ll query(int start, int end, int left, int right, int node) {
		update_lazy(start, end, node);
		if (right<start || left>end) return 0;
		if (left <= start && end <= right) {
			return tree[node];
		}
		int mid = (start + end) / 2;
		return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	segtree seg(n);
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		seg.init(i, x);
	}
	int q; cin >> q;
	while (q--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int s, e; cin >> s >> e;
			seg.update(1, seg.size, s, e, 1);
		}
		if (cmd == 2) {
			int node; cin >> node;
			cout << seg.query(1, seg.size, node, node, 1) << '\n';
		}
	}
}
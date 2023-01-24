#include<iostream>
#include<vector>
using namespace std;
class segtree {
public:
	vector<int> v;
	vector<bool> lazy;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		v.resize(2 * size);
		lazy.resize(2 * size);
	}
	void update_range(int node, int start, int end, int left, int right) {
		if (lazy[node] != 0) {
			v[node] = (end - start + 1) - v[node];
			if (start != end) {
				lazy[node * 2] = !lazy[node*2];
				lazy[node * 2 + 1] = !lazy[node * 2 + 1];
			}
			lazy[node] = 0;
		}
		if (right<start || left>end) return;
		if (left <= start && end <= right) {
			v[node] = (end - start + 1) - v[node];
			if (start != end) {
				lazy[node * 2] = !lazy[node * 2];
				lazy[node * 2 + 1] = !lazy[node * 2 + 1];
			}
			return;
		}
		int mid = (start + end) / 2;
		update_range(node * 2, start, mid, left, right);
		update_range(node * 2 + 1, mid + 1, end, left, right);
		v[node] = v[node * 2] + v[node * 2 + 1];
	}
	int getsum(int node, int start, int end, int left, int right) {
		if (lazy[node] != 0) {
			v[node] = (end - start + 1) - v[node];
			if (start != end) {
				lazy[node * 2] = !lazy[node*2];
				lazy[node * 2 + 1] = !lazy[node*2+1];
			}
			lazy[node] = 0;
		}
		if (right<start || left>end) {
			return 0;
		}
		if (left <= start && end <= right) {
			return v[node];
		}
		int mid = (start + end) / 2;
		return getsum(node * 2, start, mid, left, right) + getsum(node * 2 + 1, mid + 1, end, left, right);
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, o, s, t;
	cin >> n >> m;
	segtree tree(n);
	while (m--) {
		cin >> o >> s >> t;
		if (o==0) tree.update_range(1, 1, tree.size, s, t);
		else cout << tree.getsum(1, 1, tree.size, s, t) << '\n';
	}
}
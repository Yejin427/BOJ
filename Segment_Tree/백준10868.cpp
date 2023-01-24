#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class segtree {
public:
	vector<long long> v;
	int i;
	segtree(int n) {
		for (i = 1; i < n; i *= 2);
		v.resize(2 * i);
	}
	void minupdate(int pos, long long x) {
		int index = i + pos - 1;
		v[index] = x;
		index /= 2;
		while (index) {
			v[index] = min(v[index * 2], v[index * 2 + 1]);
			index /= 2;
		}
	}
	long long getmin(int pos, int start, int end, int left, int right) {
		if (right<start || left>end) return 1000000000;
		if (left <= start && end <= right) return v[pos];
		int mid = (start + end) / 2;
		return min(getmin(pos * 2, start, mid, left, right), getmin(pos * 2 + 1, mid + 1, end, left, right));
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	segtree tree(n);
	for (int i = 1; i <= n; i++) {
		long long x; cin >> x;
		tree.minupdate(i, x);
	}
	while (m--) {
		int a, b; cin >> a >> b;
		cout << tree.getmin(1, 1, tree.i, a, b) << '\n';
	}
}
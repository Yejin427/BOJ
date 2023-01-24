#include<iostream>
#include<vector>
using namespace std;
int a[500001];
int b[1000001];
class segtree {
public:
	int size;
	vector<long long int> v;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		v.resize(2 * size);
	}
	void update(int x) {
		int idx = x + size - 1;
		while (idx) {
			v[idx]++;
			idx /= 2;
		}
	}
	int sum(int start, int end, int left, int right, int pos) {
		if (start > right || left > end) return 0;
		else if (left <= start && end <= right) return v[pos];
		else {
			int mid = (start + end) / 2;
			return sum(start, mid, left, right, pos * 2) + sum(mid + 1, end, left, right, pos * 2 + 1);
		}
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	segtree tree(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long int ans = 0;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		b[num] = i;
	}
	for (int i = 1; i <= n; i++) {
		tree.update(b[a[i]]);
		ans += tree.sum(1, tree.size, b[a[i]] + 1, n, 1);
	}
	cout << ans;
}
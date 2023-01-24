#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const long int M=1000000007;
class segtree {
public:
	vector<ll> v;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		v.resize(2 * size);
	}
	void update(int pos, ll num) {
		int index = size + pos - 1;
		v[index] = num;
		index /= 2;
		while (index) {
			v[index] = (v[index * 2] % M * v[index * 2 + 1] % M) % M;
			index /= 2;
		}
	}
	ll getmultiple(int pos, int left, int right, int start, int end) {
		if (left > end || right < start) return 1;
		else if (left >= start && right <= end) return v[pos] % M;
		int mid = (left + right) / 2;
		return ((getmultiple(pos * 2, left, mid, start, end) % M) * (getmultiple(pos * 2 + 1, mid+1, right, start, end) % M))%M;
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
		ll x; cin >> x;
		tree.update(i, x);
	}
	int t = m + k;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) tree.update(b, c);
		else cout << tree.getmultiple(1, 1, tree.size, b, c) << '\n';
	}
}
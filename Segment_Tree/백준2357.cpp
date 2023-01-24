#include<iostream>
#include<vector>
#include<algorithm>
#define M 1000000000
using namespace std;
typedef long long ll;
class segtree {
public:
	vector<ll> tree1;
	vector<ll> tree2;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		tree1.resize(2 * size);
		tree2.resize(2 * size);
	}
	void minupdate(int pos, ll x) {
		int index = size + pos - 1;
		tree1[index] = x;
		index /= 2;
		while (index) {
			tree1[index] = min(tree1[index * 2], tree1[index * 2 + 1]);
			index /= 2;
		}
		
	}
	ll getmin(int pos, int left, int right, int start, int end) {
		if (left > end || start > right) {
			return M;
		}
		if (right <= end && start <= left) {
			return tree1[pos];
		}
		int mid = (left + right) / 2;
		return min(getmin(pos * 2, left, mid, start, end), getmin(pos * 2 + 1, mid + 1, right, start, end));
	}
	void maxupdate(int pos, ll x) {
		int index = size + pos - 1;
		tree2[index] = x;
		index /= 2;
		while (index) {
			tree2[index] = max(tree2[index * 2], tree2[index * 2 + 1]);
			index /= 2;
		}

	}
	ll getmax(int pos, int left, int right, int start, int end) {
		if (left > end || start > right) {
			return 0;
		}
		if (right <= end && start <= left) {
			return tree2[pos];
		}
		int mid = (left + right) / 2;
		return max(getmax(pos * 2, left, mid, start, end), getmax(pos * 2 + 1, mid + 1, right, start, end));
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, x, a, b;
	cin >> n >> m;
	segtree tree(n);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		tree.minupdate(i, x);
		tree.maxupdate(i, x);
	}
	while (m--) {
		cin >> a >> b;
		cout << tree.getmin(1, 1, tree.size, a, b) << " " << tree.getmax(1, 1, tree.size, a, b) << "\n";
	}
}
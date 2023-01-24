#include<iostream>
#include<vector>
using namespace std;
class segtree {
public:
	int size;
	vector<int> tree;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		tree.resize(2 * size);
	}
	void update(int pos, int x) {
		int idx = size + pos - 1;
		if (x > 0) tree[idx] = 1;
		else if (x < 0) tree[idx] = -1;
		else tree[idx] = 0;
		idx /= 2;
		while (idx) {
			tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
			idx /= 2;
		}
	}
	int query(int left, int right, int start, int end, int pos) {
		if (left <= start && end <= right) return tree[pos];
		else if (left > end || right < start) return 1;
		else {
			int mid = (start + end) / 2;
			return query(left, right, start, mid, pos * 2) * query(left, right, mid + 1, end, pos * 2 + 1);
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k; 
	while (cin >> n >> k) {
		vector<char> ans;
		segtree seg(n);
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			seg.update(i, x);
		}
		char cmd; int i, v;
		while (k--) {
			cin >> cmd >> i >> v;
			if (cmd == 'C') {
				seg.update(i, v);
			}
			else {
				int q = seg.query(i, v, 1, seg.size, 1);
				if (q == 0) ans.push_back('0');
				else if (q == 1) ans.push_back('+');
				else ans.push_back('-');
			}
		}
		for (int m = 0; m < ans.size(); m++) {
			cout << ans[m];
		}
		cout << '\n';
	}
}
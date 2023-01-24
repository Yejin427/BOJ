#include<iostream>
#include<vector>
using namespace std;
class segtree {
public:
	vector<int> sum;
	vector<int> cnt;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		sum.resize(2 * size);
		cnt.resize(2 * size);
	}
	void update_range(int start, int end, int node, int left, int right, int diff) {
		if (end < left || right < start) return;
		if (left <= start && end <= right) {
			cnt[node] += diff;
		}
		else {
			int mid = (start + end) / 2;
			update_range(start, mid, node * 2, left, right, diff);
			update_range(mid + 1, end, node * 2 + 1, left, right, diff);
		}
		if (cnt[node] > 0) {
			sum[node] = end - start + 1;
		}
		else if (start != end) {
			sum[node] = sum[node * 2] + sum[node * 2 + 1];
		}
		else sum[node] = 0;
	}
};
int main() {
	int n; cin >> n;
	while (n--) {
		int l, r;
		cin >> l >> r;
		update_range(1,tree.size)
	}
}

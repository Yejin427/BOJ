#include<iostream>
#include<algorithm>
#include<vector>
const long long INF = 100000000000;
using namespace std;
class segtree {
public:
	int size;
	int max = 0;
	//vector<int> tree;
	vector<int> index;
	long long int arr[100001];
	segtree(int n) {
		for (size = 1; size <= n; size *= 2);
		//tree.resize(2 * size);
		index.resize(2 * size);
		arr[0] = INF;
	}
	void update(int idx, int x) {
		int pos = size + idx - 1;
		arr[idx] = x;
		//tree[pos] = x;
		index[pos] = idx;
		pos /= 2;
		while (pos) {
			//tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
			if (arr[index[pos * 2]] < arr[index[pos * 2 + 1]]) {
				index[pos] = index[pos * 2];
			}
			else index[pos] = index[pos * 2 + 1];
			pos /= 2;
		}
	}
	int compare(int x, int y) {
		if (arr[x] < arr[y]) return x;
		else return y;
	}
	int findidx(int start, int end, int left, int right, int pos) {
		if (start > right || end < left) return 0;//arr[0]에 가장 큰값 저장되어있음
		if (left <= start && end <= right) return index[pos];
		int mid = (start + end) / 2;
		return compare(findidx(start, mid, left, right, pos*2), findidx(mid + 1, end, left, right, pos*2+1));
	}
	long long largest(int left, int right) {
		int divide = findidx(1, size, left, right, 1);
		long long area = (arr[divide]) * (right - left + 1);

		if (left <= divide - 1) {
			long long temp = largest(left, divide - 1);
			if (temp > area) area = temp;
		}
		if (right >= divide + 1) {
			long long temp = largest(divide + 1, right);
			if (temp > area) area = temp;
		}
		return area;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	while (cin >> t&&t!=0) {
		segtree seg(t);
		for (int i = 1; i <= t; i++) {
			int x; cin >> x;
			seg.update(i, x);
		}
		cout<<seg.largest(1, t)<<'\n';
	}
}
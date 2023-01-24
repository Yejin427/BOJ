#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
class segtree {
public:
	vector<ll> tree;
	vector<ll> lazy;
	int size;
	segtree(int n) {
		for (size = 1; size < n; size *= 2);
		tree.resize(2 * size);
		lazy.resize(2 * size);
	}
	void update(int pos, ll x) {
		int index = size + pos - 1;
		ll u = x - tree[index];
		while (index) {
			tree[index] += u;
			index /= 2;
		}
	}
	void update_range(int start, int end, int node, int left, int right, ll diff) {
		//노드에 lazy값이 저장되어 있나 확인
		if (lazy[node] != 0) {//lazy값이 저장된 경우
			tree[node] += (end - start + 1) * lazy[node];//segtree노드에 구간길이 만큼 lazy값 반영
			if (start != end) {//segtree노드에 자식 노드가 있는 경우, 자식 노드의 lazy배열에 lazy값 반영
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;//lazy값을 0으로 초기화
		}
		if (right < start || end < left) return;//노드가 범위밖 종료
		if (left <= start && end <= right) {//노드가 범위 안인 경우
			tree[node] += (end - start + 1) * diff;
			if (start != end) {//segtree노드에 자식 노드가 있는 경우, 자식 노드의 lazy 배열에 diff값 반영
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		int mid = (start + end) / 2;
		update_range(start, mid, node * 2, left, right, diff);//재귀호출
		update_range(mid + 1, end, node * 2 + 1, left, right, diff);//재귀호출
		tree[node] = tree[node * 2] + tree[node * 2 + 1];//자식 노드에서 변화된 값을 반영
	}
	ll getsum(int node, int left, int right, int start, int end) {
		if (lazy[node] != 0) {//lazy값이 저장된 경우
			tree[node] += (end - start + 1) * lazy[node];//segtree노드에 구간길이 만큼 lazy값 반영
			if (start != end) {//segtree노드에 자식 노드가 있는 경우, 자식 노드의 lazy배열에 lazy값 반영
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;//lazy값을 0으로 초기화
		}
		if (left > end || right < start) {
			return 0;
		}
		else if (left <= start && right >= end) {
			return tree[node];
		}
		int mid = (start + end) / 2;
		return getsum(node * 2, left, right, start, mid) + getsum(node * 2 + 1, left, right, mid + 1, end);
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
		int x; cin >> x;
		tree.update(i, x);
	}
	int t = m + k;
	while (t--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			tree.update_range(1, tree.size, 1, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << tree.getsum(1, b, c, 1, tree.size) << '\n';
		}
	}
	return 0;
}
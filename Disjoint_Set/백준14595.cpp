#include<iostream>
using namespace std;
int parent[1000001];
int nxt[1000001];
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	int rx = find(x);
	int ry = find(y);
	parent[rx] = ry;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		nxt[i] = i + 1;
	}
	int ans = n;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		while (find(x) != find(y)) {
			ans--;
			uni(x,find(x) + 1);
		}
	}
	cout << ans;
}
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int>> p;
priority_queue<p, vector<p>, greater<p>> pq;
int parent[100001];
int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	int rx = find(x);
	int ry = find(y);
	parent[ry] = rx;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}
	while (!pq.empty()) {
		int f1 = pq.top().second.first;
		int f2 = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (find(f1) != find(f2)) {
			uni(f1, f2);
			ans += cost;
		}
	}
	cout << ans;
}
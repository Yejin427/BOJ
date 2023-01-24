#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int parent[100002], ans, cnt;
bool visited[100002];
typedef pair<int,pair<int,int>> p;
priority_queue<p, vector<p>, greater<p>> pq;
int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
void uni(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	parent[root_b] = root_a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;//a가 상위 b가 하위
		pq.push({ c,{a,b} });
	}
	while (!pq.empty()) {
		p e = pq.top();
		pq.pop();
		if (find(e.second.first) != find(e.second.second)) {
			uni(e.second.first,e.second.second);
			ans += e.first;
			cnt = max(e.first, cnt);
		}
	}
	cout << ans - cnt;
}
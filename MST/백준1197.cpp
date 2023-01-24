#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, pair<int, int>> p;
priority_queue<p, vector<p>, greater<p>> pq;
int parent[10001];
int find(int x){
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void uni1(int x, int y) {
	int px = find(x);
	int py = find(y);
	parent[py] = px;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e; cin >> v >> e;
	long long int ans = 0;
	while (e--) {
		int a, b, c; cin >> a >> b >> c;
		parent[a] = a; parent[b] = b;
		pq.push({ c,{a,b} });
	}
	while (!pq.empty()) {
		int front_a = pq.top().second.first;
		int front_b = pq.top().second.second;
		if (find(front_a) != find(front_b)) {
			uni1(front_a, front_b);
			ans += pq.top().first;
		}
		pq.pop();
	}
	cout << ans;
}
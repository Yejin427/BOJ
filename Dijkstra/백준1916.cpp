#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int city[1001][1001];
struct bus {
	int f, cost;
};
bool operator<(bus a, bus b) {
	return a.cost > b.cost;
}
priority_queue<bus, vector<bus>, less<bus>> pq;
vector<bus> v[1001];
int ans[1001];
int main() {
	int n, m, c, s, start, finish, f1, c1;
	cin >> n >> m;
	struct bus b;
	for (int i = 1; i <= m; i++) {
		cin >> s >> b.f >> b.cost;
		v[s].push_back({ b.f,b.cost });
	}
	cin >> start >> finish;
	pq.push({ start,0 });
	while (!pq.empty()) {
		f1 = pq.top().f;
		c1 = pq.top().cost; pq.pop();
		if (ans[f1] != 0) continue;
		ans[f1] = c1;
		for (int i = 0; i < v[f1].size(); i++) {
			pq.push({ v[f1][i].f,c1 + v[f1][i].cost });
		}
	}
	cout << ans[finish];
}

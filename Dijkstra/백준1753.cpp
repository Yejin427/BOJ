#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node {
	int v, w;
};
struct cmp {
	bool operator()(node a, node b) {
		return a.w > b.w;
	}
};
priority_queue<node, vector<node>, cmp> pq;
vector<node> ve[20001];
int ans[20001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int v, e, k, l, v1, w1;
	cin >> v >> e >> k;
	struct node a;
	for (int i = 1; i <= e; i++) {
		cin >> l >> a.v >> a.w;
		ve[l].push_back({ a.v,a.w });
	}
	pq.push({ k,0 });
	while (!pq.empty()) {
		v1 = pq.top().v;
		w1 = pq.top().w; pq.pop();
		if (ans[v1] != 0) continue;
		ans[v1] = w1;
		for (int i = 0; i < ve[v1].size(); i++) {
			pq.push({ ve[v1][i].v, w1 + ve[v1][i].w });
		}
	}
	for (int i = 1; i <= v; i++) {
		if (i == k) cout << "0" << "\n";
		else if (ans[i] == 0) cout << "INF" << "\n";
		else cout << ans[i] << "\n";
	}
}
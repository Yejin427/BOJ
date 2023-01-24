#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> v[501];
int ans[501];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int s, e; cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	int Q; cin >> Q;
	memset(ans, -1, sizeof(ans));
	while (Q--) {
		queue<int> q;
		int a, i, j; cin >> a >> i >> j;
		if (a == 1) {
			v[i].push_back(j);
			v[j].push_back(i);
		}
		else {
			for (int k = 0; k < v[i].size(); k++) {
				if (v[i][k] == j) {
					v[i].erase(v[i].begin() + k);
					break;
				}
			}
			for (int k = 0; k < v[j].size(); k++) {
				if (v[j][k] == i) {
					v[j].erase(v[j].begin() + k);
					break;
				}
			}
		}
		ans[1] = 0;
		q.push(1);
		while (!q.empty()) {
			int fr = q.front();
			q.pop();
			for (int k = 0; k < v[fr].size(); k++) {
				if (ans[v[fr][k]] == -1) {
					ans[v[fr][k]] = ans[fr] + 1;
					q.push(v[fr][k]);
				}
			}
		}
		for (int k = 1; k <= n; k++) cout << ans[k] << " ";
		cout << "\n";
		memset(ans, -1, sizeof(ans));
	}
}
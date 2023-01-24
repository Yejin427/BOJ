#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool visit_dfs[1002];
bool visit_bfs[1002];
vector<int> v[1002];
queue<int> q;
void dfs(int x) {
	visit_dfs[x] = true;
	cout << x << " ";
	for (int i = 0; i < v[x].size(); i++) {
		if (!visit_dfs[v[x][i]]) {
			dfs(v[x][i]);
		}
	}
}
void bfs(int x) {
	visit_bfs[x] = true;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 0; i < v[now].size(); i++) {
			if (!visit_bfs[v[now][i]]) {
				q.push(v[now][i]);
				visit_bfs[v[now][i]] = true;
			}
		}
	}
}
int main() {
	int a, b, c, j1, j2;
	cin >> a >> b >> c;
	for (int i = 0; i < b; i++) {
		cin >> j1 >> j2;
		v[j1].push_back(j2);
		v[j2].push_back(j1);
	}
	for (int i = 0; i < a; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(c);
	cout << "\n";
	bfs(c);
}
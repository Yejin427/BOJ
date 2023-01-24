#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> v[101];
queue<int> q;
int n, m, a, b, h;
long cnt = 987654321;
bool visited[101];
int ans[101];
int depth[101];
int bfs(int x) {
	q.push(x);
	visited[x] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < v[front].size(); i++) {
			if (!visited[v[front][i]]) {
				depth[v[front][i]] = depth[front] + 1;
				q.push(v[front][i]);
				visited[v[front][i]] = true;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += depth[i];
	}
	return sum;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = bfs(i);
		memset(depth, 0, sizeof(depth));
		memset(visited, false, sizeof(visited));
	}
	for (int i = 1; i <= n; i++) {
		if (cnt > ans[i]) {
			cnt = ans[i];
			h = i;
		}
	}
	cout << h;
	return 0;
}
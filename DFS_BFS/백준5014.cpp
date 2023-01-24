#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
bool visited[1000001];
int f, s, g, u, d, ans[1000001];
bool isok(int n) {
	if (n > f || n < 1 || visited[n]) return false;
	else return true;
}
int main() {
	cin >> f >> s >> g >> u >> d;
	if (s == g) {
		cout << "0";
		return 0;
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (isok(front + u)) {
			ans[front + u] = ans[front] + 1;
			visited[front + u] = true;
			q.push(front + u);
		}
		if (isok(front - d)) {
			ans[front - d] = ans[front] + 1;
			visited[front - d] = true;
			q.push(front - d);
		}
	}
	if (!ans[g]) cout << "use the stairs";
	else cout << ans[g];
}
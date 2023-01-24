#include<iostream>
int n, m, ans[10];
bool visited[10];
using namespace std;
void backtracking(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[depth] = i;
			backtracking(depth + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	backtracking(0);
}
#include<iostream>
using namespace std;
int n, lotto[50], ans[7];
void dfs(int front, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = front; i < n; i++) {
		ans[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n) {
		for (int i = 0; i < n; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << "\n";
		cin >> n;
	}
}
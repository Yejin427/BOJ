#include<iostream>
#include<algorithm>
using namespace std;
int arr[10], ans[10], n, m;
bool visited[10001];
void backtracking(int depth) {
	if (depth == m + 1) {
		for (int i = 1; i <= m; i++) cout << ans[i] << " ";
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[arr[i]]) {
			visited[arr[i]] = true;
			ans[depth] = arr[i];
			backtracking(depth + 1);
			visited[arr[i]] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	backtracking(1);
}
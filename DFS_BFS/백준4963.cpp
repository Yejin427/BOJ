#include<iostream>
#include<string.h>
using namespace std;
int sum[52][52], n, m, ans;
bool visited[52][52];
int dx[8] = { 1,0,-1,0,1,1,-1,-1 }, dy[8] = { 0,1,0,-1,1,-1,1,-1 };
bool is_ok(int x, int y) {
	if (x<0 || x>=m || y<0 || y>=n || visited[x][y] || !sum[x][y])
		return false;
	return true;
}
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		if (is_ok(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}
int main() {
	cin >> m >> n;
	while (n || m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> sum[j][i];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (sum[j][i] && !visited[j][i]) {
					ans++;
					dfs(j, i);
				}
			}
		}
		cout << ans << "\n";
		cin >> m >> n;
		ans = 0;
		memset(sum, 0, sizeof(sum));
		memset(visited, 0, sizeof(visited));
	}
}
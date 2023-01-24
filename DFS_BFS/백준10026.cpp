#include<iostream>
#include<cstring>
using namespace std;
char arr[101][101];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 }, n;
bool visited[101][101];
bool inmap(int x, int y, char c) {
	if (x >= 1 && x <= n && y >= 1 && y <= n && !visited[x][y] && c == arr[x][y]) return true;
	else return false;
}
bool isok(int x, int y, char c) {
	if (x >= 1 && x <= n && y >= 1 && y <= n && !visited[x][y]) {
		if (c == arr[x][y]) return true;
		else if (c == 'R' && arr[x][y] == 'G') return true;
		else if (c == 'G' && arr[x][y] == 'R') return true;
		else return false;
	}
	return false;
}
void dfs(int x, int y, char c) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (inmap(x + dx[i], y + dy[i], c)) {
			dfs(x + dx[i], y + dy[i], c);
		}
	}
}
void dfs2(int x, int y, char c) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (isok(x + dx[i], y + dy[i], c)) {
			dfs2(x + dx[i], y + dy[i], c);
		}
	}
}
int main() {
	int ans1 = 0, ans2 = 0; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				ans1++;
				dfs(i, j, arr[i][j]);
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				ans2++;
				dfs2(i, j, arr[i][j]);
			}
		}
	}
	cout << ans1 <<" "<< ans2;
}
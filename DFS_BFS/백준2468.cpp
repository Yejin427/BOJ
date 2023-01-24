#include<iostream>
#include<cstring>
using namespace std;
int arr[101][101], n;
int dx[] = { 1,0,-1,0 }; int dy[] = { 0,1,0,-1 }; int ans[101];
bool visited[101][101];
bool isok(int col, int row,int height) {
	if (col <= 0 || col > n || row <= 0 || row > n || visited[col][row] || arr[col][row] < height) return false;
	else return true;
}
void dfs(int col, int row,int height) {
	visited[col][row] = true;
	for (int i = 0; i < 4; i++) {
		if (isok(col+dx[i],row+dy[i],height)) {
			dfs(col + dx[i], row + dy[i],height);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int max = 0; int max1 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (max1 < arr[i][j]) max1 = arr[i][j];
		}
	}
	for (int k = 1; k <= max1; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (isok(i, j, k)) {
					ans[k]++;
					dfs(i, j, k);
				}
			}
		}
		if (max < ans[k]) max = ans[k];
		memset(visited, false, sizeof(visited));
	}
	cout << max;
}
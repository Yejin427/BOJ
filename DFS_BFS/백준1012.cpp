#include<iostream>
#include<string.h>
using namespace std;
int n, m, baechu[110][110], bug, visited[110][110], k, x, y;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool is_ok(int i, int j) {
	if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || !baechu[i][j]) {//��踦 �Ѱų� �湮�� ��, 1�� �ƴ� ��
		return false;
	}
	return true;
}
void dfs(int i, int j) {
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		if (is_ok(i + dx[k], j + dy[k])) {
			dfs(i + dx[k], j + dy[k]);
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n >> k;//m�� ���� n�� ����
		for (int i = 1; i <= k; i++) {
			cin >> x >> y;
			baechu[x][y] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (baechu[j][i] && !visited[j][i]) {//0�̰ų� �湮���� ���� ��
					bug++;
					dfs(j, i);
				}
			}
		}
		cout << bug<<"\n";
		bug = 0;
		memset(visited, 0, sizeof(visited));
		memset(baechu, 0, sizeof(baechu));
	}
}
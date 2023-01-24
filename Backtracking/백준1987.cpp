#include<iostream>
#include<algorithm>;
using namespace std;
char board[22][22];
bool alpha[30];
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 }, r, c, ans;
bool go(int x, int y) {
	if (x <= 0 || x > c || y <= 0 || y > r || alpha[board[x][y] - 'A']) {
		return false;
	}
	else return true;
}
void dfs(int x, int y,int depth) {//(x,y)에서 시작
	alpha[board[x][y] - 'A'] = true;
	ans = max(ans, depth);
	for (int i = 0; i < 4; i++) {
		if (go(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i],depth+1);
			alpha[board[x + dx[i]][y + dy[i]] - 'A'] = false;
		}
	}
}
int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[j][i];
		}
	}
	dfs(1, 1,1);
	cout << ans;
}
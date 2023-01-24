#include<iostream>
#include<cstring>
using namespace std;
int map[501][501], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, m, n, ans;
long long int dp[501][501];
bool inmap(int x, int y) {
	if (x<1 || y<1 || x>m || y>n) return false;
	else return true;
}
long long int visit(int col, int row) {
	if (col == 1 && row == 1) {
		return 1;
	}
	if (inmap(col, row) && dp[col][row] == -1) {
		dp[col][row] = 0;
		for(int i=0;i<=3;i++){
			if (map[col + dx[i]][row + dy[i]] > map[col][row] && inmap(col+dx[i],row+dy[i])) {
				dp[col][row] += visit(col + dx[i], row + dy[i]);
			}
		}
	}
	return dp[col][row];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << visit(m, n);
}
#include<iostream>
#include<algorithm>
using namespace std;
bool chess[11][11], l[23], r[23];
int ans[2], n;
void backtracking(int row, int col, int cnt, int color) {
	if (col >= n) {
		row++;
		if (col % 2 == 0) col = 1;
		else col = 0;
	}
	if (row >= n) {
		ans[color] = max(ans[color], cnt);
		return;
	}
	if (chess[row][col] && !l[col - row + n - 1] && !r[row + col]) {
		l[col - row + n - 1] = r[row + col] = 1;
		backtracking(row, col + 2, cnt + 1, color);
		l[col - row + n - 1] = r[row + col] = 0;
	}
	backtracking(row, col + 2, cnt, color);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> chess[i][j];
		}
	}
	backtracking(0, 0, 0, 0);
	backtracking(0, 1, 0, 1);
	cout << ans[0] + ans[1];
}
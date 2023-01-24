#include<iostream>
#include<vector>
using namespace std;
int chess[16][16], ans, n;
bool visited[16][16], solution[16];
void nqueen(int depth) {
	vector<bool> row(n), upperdiagonal(2 * n + 1), lowerdiagonal(2 * n + 1);
	if (depth == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (row[i] || upperdiagonal[n + i - depth] || lowerdiagonal[i + depth]) continue;
		row[i] = upperdiagonal[n + i - depth] = lowerdiagonal[i + depth] = true;
		nqueen(depth + 1);
		row[i] = upperdiagonal[n + i - depth] = lowerdiagonal[i + depth] = false;
	}
}
int main() {
	int n; cin >> n;
	nqueen(0);
	cout << ans;
}
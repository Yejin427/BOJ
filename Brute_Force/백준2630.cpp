#include<iostream>
using namespace std;
int paper[130][130];
int w_cnt, b_cnt;
void count(int x, int y, int n) {
	int tmp = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (paper[i][j]) tmp++;
		}
	}
	if (!tmp) w_cnt++;
	else if (tmp == n * n) b_cnt++;
	else {
		count(x, y, n / 2);
		count(x, y + n / 2, n / 2);
		count(x + n / 2, y, n / 2);
		count(x + n / 2, y + n / 2, n / 2);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> paper[i][j];
		}
	}
	count(1, 1, n);
	cout << w_cnt << "\n" << b_cnt << "\n";
}
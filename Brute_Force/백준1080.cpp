#include<iostream>
using namespace std;
int a[51][51];
int b[51][51];
void f(int x, int y) {//행렬 뒤집는 연산
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (a[x+i][y+j] == 1) a[x+i][y+j] = 0;
			else a[x+i][y+j] = 1;
		}
	}
}
int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &b[i][j]);
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				f(i, j); 
				ans++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans;
}
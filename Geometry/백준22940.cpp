#include<iostream>
using namespace std;
double arr[7][7];
double ans[7];
int x[7];
void swap(int a, int b, int n) {
	double tmp = 0;
	for (int i = 1; i <= n; i++) {
		double tmp = arr[a][i];
		arr[a][i] = arr[b][i];
		arr[b][i] = tmp;
	}
	tmp = ans[a]; ans[a] = ans[b]; ans[b] = tmp;
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
		cin >> ans[i];
	}
	for (int i = 1; i < n; i++) {//U matrix ¸¸µé±â
		if (arr[i][i] == 0) {
			int k = i;
			while (arr[k][i] == 0) k++;
			swap(i, k, n);
		}
		for (int j = i + 1; j <= n; j++) {
			double e = arr[j][i] / arr[i][i];
			for (int k = 1; k <= n; k++) {
				arr[j][k] -= e * arr[i][k];
			}
			ans[j] -= e * ans[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << ans[i] << '\n';
	}
	x[n] = round(ans[n] / arr[n][n]);
	for (int i = n - 1; i >= 1; i--) {
		double cnt = 0;
		for (int j = i + 1; j <= n; j++) {
			cnt += arr[i][j] * x[j];
		}
		x[i] = round((ans[i] - cnt) / arr[i][i]);
	}
	for (int i = 1; i <= n; i++) cout << x[i] << " ";
}
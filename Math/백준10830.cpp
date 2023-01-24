#include<iostream>
#include<cstring>
using namespace std;
long long int arr[6][6], ans[6][6], res[6][6], result[6][6];
long long n, b;
void multiple(long long int a[6][6], long long int b[6][6]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res[i][j] = 0;
			for (int k = 1; k <= n; k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = res[i][j];
		}
	}
}
void power(long long int arr[6][6], long long b) {
	for (int i = 1; i <= n; i++) result[i][i] = 1;//I matrix
	while (b > 0) {
		if (b % 2 == 1) {
			multiple(result, arr);
		}
		multiple(arr, arr);
		b /= 2;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	power(arr, b);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}
}

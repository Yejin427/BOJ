#include<iostream>
using namespace std;
int arr[1001];
int dp[1001];
int l[1001];
int r[1001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1; l[i] = 1; r[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && l[i] < l[j] + 1) {
				l[i] = l[j] + 1;
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j] && r[i] < r[j] + 1) {
				r[i] = r[j] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int m1 = 0, m2 = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (m1 < l[j]) m1 = l[j];
			}
		}
		dp[i] += m1;
		for (int j = i + 1; j <= n; j++) {
			if (arr[i] > arr[j]) {
				if (m2 < r[j]) m2 = r[j];
			}
		}
		dp[i] += m2;
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[i]) max = dp[i];
	}
	cout << max;
}
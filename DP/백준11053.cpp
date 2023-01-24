#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n; cin >> n;
	int m = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int k = arr[i];
		for (int j = 1; j <= i - 1; j++) {
			if (k > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		m = max(m, dp[i]);
	}
	cout << m;
}
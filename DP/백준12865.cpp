#include<iostream>
#include<algorithm>
using namespace std;
int arr[101][2];
int dp[101][100003];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= n; i++) {
		int w = arr[i][0];
		int v = arr[i][1];
		for (int j = 0; j <= k; j++) {
			if (j < arr[i][0]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
		}
	}
	cout << dp[n][k];
}
#include<iostream>
#include<algorithm>
using namespace std;
int arr[501];
int dp[501];
int main() {
	int n, maxx = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		arr[a] = b;
		maxx = max(maxx, a);
	}
	for (int i = 1; i <= maxx; i++) {
		if (arr[i] == 0) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (arr[j] != 0 && arr[i] > arr[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= maxx; i++) ans = max(ans, dp[i]);
	cout << n - ans;
}

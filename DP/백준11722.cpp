#include<iostream>
#include<algorithm>
using namespace std;
int a[1002];
int dp[1002];
int main() {
	int n, ans = 0;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(dp[i], ans);
	}
	cout << ans;
}
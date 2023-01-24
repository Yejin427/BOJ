#include<iostream>
#include<algorithm>
using namespace std;
int price[1001];
int dp[1001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> price[i];
	dp[1] = price[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i / 2; j++) {
			if (j == 0) {
				dp[i] = price[i];
				continue;
			}
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
		}
	}
	cout << dp[n];
}
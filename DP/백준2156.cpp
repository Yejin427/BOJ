#include<iostream>
#include<algorithm>
using namespace std;
int wine[10001], dp[10001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + wine[i] + wine[i - 1], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[n];
}
#include<iostream>
#include<algorithm>
using namespace std;
int coin[102];
int dp[102];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {//dp
			if (j >= coin[i]) dp[j] += dp[j-coin[i]];
		}
	}
	cout << dp[k];
}
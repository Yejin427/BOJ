#include<iostream>
#include<algorithm>
using namespace std;
int arr[1500001][2];
int dp[1500001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		if(i + arr[i][0] - 1 > n) continue;
		dp[i + arr[i][0] - 1] = max(dp[i + arr[i][0] - 1], dp[i + arr[i][0] - 2]);
		int cur = (dp[i - 1] + arr[i][1]);
		dp[i + arr[i][0] - 1] = max(dp[i + arr[i][0] - 1], cur);
	}
	//for (int i = 1; i <= n; i++)cout << dp[i] << " ";
	//cout << "\n";
	cout << dp[n];
}
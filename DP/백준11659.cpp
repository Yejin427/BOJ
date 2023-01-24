#include<iostream>
using namespace std;
int arr[100001], dp[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, start, end;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];
	}
	while (m--) {
		cin >> start >> end;
		cout << dp[end] - dp[start - 1] << "\n";
	}
}
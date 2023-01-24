#include<iostream>
#include<algorithm>
using namespace std;
int arr[202];
int dp[202];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(dp[i], ans);
	}
	cout << n - ans;
}
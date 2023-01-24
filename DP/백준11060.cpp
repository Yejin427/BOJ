#include<iostream>
#include<algorithm>
using namespace std;
int a[1002];
int dp[1002];
int main() {
	int n, ans, cnt = 1200;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	if (n == 1) {
		cout << "0";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (j + a[j]>=i) {
				if (dp[j] == 0&&j!=1) continue;
				dp[i] = min(dp[j] + 1, cnt);
				cnt = dp[i];//최솟값 갱신
			}
		}
		cnt = 1200;
	}
	if (dp[n] != 0) cout << dp[n];
	else cout << "-1";
}
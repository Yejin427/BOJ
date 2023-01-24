#include<iostream>
#include<algorithm>
const int INF = 987654321;
using namespace std;
int arr[102];
int sum[102];
int dp[102][102];
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i < 2 * j) dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {//현재 탐색 위치 i
		for (int j = 1; j <= m; j++) {//j: 구간개수
			dp[i][j] = dp[i - 1][j];
			for (int k = 0; k < i; k++) {//k에서 끊길거임
				if (j == 1 && k==0) {
					dp[i][j] = max(dp[i][j], sum[i]);
				}
				else if (k == 0) {
					continue;
				}
				else {
					dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + sum[i] - sum[k]);
				}
			}
		}
	}
	cout << dp[n][m] << '\n';
}
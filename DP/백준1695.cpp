#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, i;
int arr[5000];
int dp[5000][5000];//dp[left][right]
int f(int x, int y) {
	if (x > y) return 0;

	if (dp[x][y] != -1) return dp[x][y];
	if (arr[x] == arr[y]) {
		return dp[x][y] = f(x + 1, y - 1);
	}
	else {
		return dp[x][y] = min(f(x + 1, y) + 1, f(x, y - 1) + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << f(0, n - 1);
	return 0;
}
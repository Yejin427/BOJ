#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char arr1[1001];
char arr2[1001];
int dp[1001][1001];
int f(int x, int y) {
	if (x < 0 || y < 0) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	if (arr1[x] == arr2[y]) return dp[x][y] = f(x - 1, y - 1) + 1;
	else {
		return dp[x][y] = max(f(x - 1, y), f(x, y - 1));
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> arr1;
	cin >> arr2;
	int length1 = strlen(arr1);
	int length2 = strlen(arr2);
	memset(dp, -1, sizeof(dp));
	cout << f(length1-1, length2-1);
}
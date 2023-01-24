#include<stdio.h>
int dp[1001][3];
int cost[1001][3];
int min(int x, int y) {
	if (x < y) return x;
	else if (x > y) return y;
}

int main() {
	int n;
	int mini = 1000;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	printf("%d\n", min(min(dp[n][0], dp[n][1]), dp[n][2]));
	return 0;
	
}

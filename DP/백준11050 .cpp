#include<stdio.h>
int arr[15][15];
int johab(int n, int r) {
	if (n == 1 && r == 1) arr[1][1] = 1;
	if (r == 0) arr[n][0] = 1;
	if (n == r) arr[n][r] = 1;
	
	if (arr[n][r] > 0) return arr[n][r];
	arr[n][r] = johab(n - 1, r) + johab(n - 1, r - 1);
	return arr[n][r];
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", johab(N,K));
}

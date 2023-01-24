#include<stdio.h>
#define A 10007
long long int arr[1003][1003];
long long int johab(int n, int r) {
	if (n == r || r == 0) arr[n][r] = 1;

	if (arr[n][r] > 0) return arr[n][r]%A;
	arr[n][r] = johab(n - 1, r)%A + johab(n - 1, r - 1)%A;
	return arr[n][r]%A;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%lld", johab(N, K));
}

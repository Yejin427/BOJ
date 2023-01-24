#include<stdio.h>
#define A 10007
int arr[1005];
int tile(int n) {
	if (n == 1) arr[n] = 1;
	if (n == 2) arr[n] = 2;
	if (arr[n] > 0) return arr[n]%A;

	arr[n] = tile(n - 1)%A + tile(n - 2)%A;
	return arr[n] % A;
}
int main() {
	int N;
	scanf("%d", &N);
	printf("%d", tile(N));
}
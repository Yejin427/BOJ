#include<stdio.h>
long long int arr[1000];
long long int pado(int n) {
	if (n == 1 || n == 2 || n == 3) arr[n]=1;
	if (n == 4 || n == 5) arr[n]=2;
	if (arr[n] > 0) return arr[n];
	arr[n] = pado(n-1) + pado(n-5);
	return arr[n];
}
int main() {
	int T, N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &T);
		printf("%lld\n", pado(T));
	}
	return 0;
}
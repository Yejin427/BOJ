#include<stdio.h>
int main() {
	int N, n1, n2, n3, ans, A;
	ans = 0;
	scanf("%d", &N);
	A = N;
	do {
		n1 = (N / 10);
		n2 = (N % 10);
		n3 = (n1 + n2)%10;
		N = 10 * n2 + n3;
		ans++;
	} while (N != A);
	printf("%d", ans);
}
#include<stdio.h>
int arr[50];
int count(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (arr[n] > 0) return arr[n];
	arr[n] = count(n - 1) + count(n - 2);
	
	return arr[n];
}
int main() {
	int N,T;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &T);
		if (T == 0) printf("1 0\n");
		else printf("%d %d\n", count(T - 1), count(T));
	}
	return 0;
}
#include<stdio.h>
int dab;
int num[100];
int plus(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 4;
	if (x >= 4) {
		dab = plus(x - 3) + plus(x - 2) + plus(x - 1);
		return dab;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", plus(num[i]));
	}
}
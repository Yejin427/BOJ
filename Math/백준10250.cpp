#include<stdio.h>
int main() {
	int T, H, W, N, ans, F, R;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d", &H, &W, &N);
		if (N % H == 0) {
			F = H;
			R = N / H;
		}
		else {
			F = N % H;
			R = N / H + 1;
		}
		ans = 100 * F + R;
		printf("%d\n", ans);
	}
}
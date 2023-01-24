#include<stdio.h>
int main() {
	int a, b;
	int x;
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= a; i++) {
		scanf("%d", &x);
		if (x < b) printf("%d ", x);
	}
}
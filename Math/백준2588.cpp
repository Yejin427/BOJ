#include<stdio.h>
int main() {
	int a, b;
	int b1, b2, b3;
	scanf("%d %d", &a, &b);
	b1 = b / 100;
	b2 = (b % 100) / 10;
	b3 = (b % 100) % 10;
	printf("%d\n", a * b3);
	printf("%d\n", a * b2);
	printf("%d\n", a * b1);
	printf("%d", a * b);
}
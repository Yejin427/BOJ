#include<stdio.h>
int gcd(int x, int y) {
	while (y != 0) {
		int R = x % y;
		x = y;
		y = R;
	}
	return x;
}
int lcd(int x, int y, int z) {
	return x * y / z;//z는 최대공약수
}
int main() {
	int a, b, g, l;
	scanf("%d %d", &a, &b);
	g = gcd(a, b);
	l = lcd(a, b, g);
	printf("%d\n%d", g, l);
}
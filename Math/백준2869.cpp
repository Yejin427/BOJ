#include<stdio.h>
int main() {
	long long int A, B, V, day = 0, x=0;
	scanf("%lld%lld%lld", &A, &B, &V);
	day = (V - B - 1) / (A - B) + 1;
	printf("%lld", day);
}
#include<stdio.h>
long long int arr[100];
long long int pn(int n) {
	if (n == 1) arr[n] = 1;
	if (n == 2) arr[n] = 1;
	if(arr[n]>0) return arr[n];
	arr[n] = pn(n-1) + pn(n-2);//1�������� 0���ü� �ְ� 0�������� 1,0 ��� �ü� ����
	return arr[n];
}
int main() {
	int N;
	scanf("%d", &N);
	printf("%lld", pn(N));
}
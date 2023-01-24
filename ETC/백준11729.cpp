#include<stdio.h>
int k;//���� �ű� Ƚ��
void hanoi(int n) {
	if (n == 1) {
		k++;
		return;
	}
	hanoi(n - 1);
	k++;
	hanoi(n - 1);
}
void hanoi2(int n, int from, int to, int by) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi2(n - 1, from, by, to);//��� ����� ���� n-1���� ���� ������� �ű��
	printf("%d %d\n", from, to);//������ ������ ������ ������� �ű�
	hanoi2(n - 1, by, to, from);//���� ��տ� �׿��ִ� ���� n-1���� ������ ������� �̵�
}
int main() {
	int N;
	scanf("%d", &N);
	if (N <= 20) {
		hanoi(N);
		printf("%d\n", k);
		//N���� ������ 1������ 3������ �ű�� ���� ���
		hanoi2(N, 1, 3, 2);
	}
	else {
		hanoi(N);
		printf("%d", k);
	}
}